#include "abalone_gui.h"
#include "ui_abalone_gui.h"
#include <QGraphicsView>
#include "QtDebug"

abalone_gui::abalone_gui(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::abalone_gui)
{
    ui->setupUi(this);
    this->scene = new QGraphicsScene();
    this->_game = Game();
    _game.initialized(Color::BLACK);
    index=0;
    init_lists();
    add_board_to_gui();
    add_to_scene();
    set_message(0);

    this->view = new QGraphicsView(scene);

    view->setRenderHint(QPainter::Antialiasing);
    view->setRenderHint(QPainter::TextAntialiasing);
    view->setCacheMode(QGraphicsView::CacheBackground);
    view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view->setDragMode(QGraphicsView::ScrollHandDrag);
    view->update();
    this->view->setBackgroundBrush(Qt::darkRed);
    ui->verticalLayout->addWidget(view);
}

abalone_gui::~abalone_gui()
{
    delete ui;
}
void abalone_gui::add_board_to_gui()
{
    int nbElementHexacell=0;
    int nbElementMarble=0;
    auto & board = _game.get_board();
    for (auto i=1;i<board.getRow()-2 ;i++ )
    {
        for (auto j=0;j<board.getColumn() ;j++ )
        {
            auto instance = Position(i,j);
            if(board.isInside(instance))
            {
                this->elements_hexacell.at(nbElementHexacell)=std::make_unique<hexacell>(i,j);
                nbElementHexacell++;
                if(_game.marble_is_present_at(instance))
                {
                    this->elements_marbles.at(nbElementMarble)=std::make_unique<marble>(i,j,_game.get_marble_at(instance).getColor());
                    nbElementMarble++;
                }
            }
        }

    }
}
void abalone_gui::add_to_scene()
{
    for (auto it=this->elements_hexacell.begin();it!=this->elements_hexacell.end() ;it++ )
    {
        QObject::connect(it->get(),SIGNAL(sendValue(Position&)),this,SLOT(add_positions_to_list(Position&)));
        this->scene->addItem(it->get());

    }
    for (auto it=this->elements_marbles.begin();it!=this->elements_marbles.end() ;it++ )
    {
        this->scene->addItem(it->get());
    }
}

void abalone_gui::update_scene()
{
    clear_lists();
    init_lists();
    add_board_to_gui();
    add_to_scene();
    set_message(0);
    ui->move_alone->setAutoExclusive(false);
    ui->move_group->setAutoExclusive(false);
    ui->move_alone->setChecked(false);
    ui->move_group->setChecked(false);
    ui->move_alone->setAutoExclusive(true);
    ui->move_group->setAutoExclusive(true);
}

void abalone_gui::add_positions_to_list(Position&element)
{
    std::string message = "YOU CLICK ON THE HEXAGONE AT THE POSITION ["
    + std::to_string(element.getRow())+","+std::to_string(element.getColumn())+"] ";
    ui->message_label->setText(message.c_str());

    if(ui->move_alone->isChecked())
    {
        if(index>=2)
        {
            set_message(2);
        }else
        {
            this->elements.resize(2);
            this->elements.at(index)= element;
            index++;
        }

    }else if(ui->move_group->isChecked())
    {
        if(index>=3)
        {
            set_message(1);
        }else
        {
            this->elements.at(index)= element;
            index++;
        }

    }else{
        set_message(-1);

    }
}



void abalone_gui::on_apply_move_clicked()
{
    try {
        this->_game.move(this->elements);
        if(_game.checkWin())
        {
            set_message(3);
        }else
        {
            update_scene();
        }

    }  catch (std::invalid_argument &e) {
        reset(e);
    }

}
void abalone_gui::set_message(int signal)
{
    switch (signal) {
    case 0:{
        auto player = this->_game.get_current_player();
        std::string message ="Time for player";
        if(player.getPlayerColor()==BLACK)
        {
            message.append(" BLACK");
        }else
        {
            message.append(" WHITE");
        }
        ui->message_label->setText(message.c_str());
        break;
    }
    case 1:{
        ui->message_label->setText("YOU CLICK MORE THAN THREE TIME WHILE YOU SUPPOSE "
                                    "TO CHOOSE ONLY THREE HEXACELL CLICK ON "
                                    "THE BUTTON (GO) TO APPLY MOVEMENT");
        break;
    }
    case 2:
    {
        ui->message_label->setText("YOU CLICK MORE THAN TWO TIME WHILE YOU SUPPOSE "
          "TO CHOOSE ONLY TWO HEXACELL CLICK ON THE BUTTON (GO) TO APPLY MOVEMENT");
        break;
    }
    case -1:
    {
        ui->message_label->setText("ERROR PICK AN ACTION FIRST");
        break;
    }
    case 3:{
        std::string message = this->_game.get_winner_name();
        message.append(" IS THE WINNER");
        ui->message_label->setText(message.c_str());
        break;

    }
    }
}

void abalone_gui::reset(std::invalid_argument&element)
{
    std::string message = element.what();
    auto player = this->_game.get_current_player();
    message.append(" [Current Player is :");
    if(player.getPlayerColor()==BLACK)
    {
        message.append(" BLACK]");
    }else
    {
        message.append(" WHITE]");
    }
    ui->message_label->setText(message.c_str());
    this->elements.clear();
    this->elements = std::vector<Position>(3);
    index=0;

}
