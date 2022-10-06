#ifndef ABALONE_GUI_H
#define ABALONE_GUI_H

#include <QMainWindow>
#include "../abalonecore/Game.h"
#include <QGraphicsScene>
#include "hexacell.h"
#include "marble.h"
#include "memory"

QT_BEGIN_NAMESPACE
namespace Ui { class abalone_gui; }
class hexacell;
class marble;
QT_END_NAMESPACE
/**
  class of the new graphic view
 * @brief The abalone_gui class
 */
class abalone_gui : public QMainWindow
{
    Q_OBJECT

public:
    /**
      default constructor or abalone gui
     * @brief abalone_gui
     * @param parent
     */
    abalone_gui(QWidget *parent = nullptr);
    ~abalone_gui();


private slots:
    /**
      add the position of the hexagon on a vector
     * @brief add_positions_to_list
     * @param element
     */
    void add_positions_to_list(Position&element);


    /**
      apply the move if the button is clicked
     * @brief on_apply_move_clicked
     */
    void on_apply_move_clicked();

private:

    Ui::abalone_gui *ui;
    QGraphicsScene *scene;
    QGraphicsView *view;
    Game _game;
    int index;
    std::vector<std::shared_ptr<hexacell>>elements_hexacell;
    std::vector<std::shared_ptr<marble>>elements_marbles;
    std::vector<Position>elements;
    /**
      add the board to the graphic view
     * @brief add_board_to_gui
     */
    void add_board_to_gui();
    /**
      add hexacel and marble on the view
     * @brief add_to_scene
     */
    void add_to_scene();
    /**
      update the state of the view
     * @brief update_scene
     */
    void update_scene();
    /**
      reset to default the attributs
     * @brief clear_lists
     */
    void clear_lists()
    {
        this->elements_hexacell.clear();
        this->elements_marbles.clear();
        this->elements.clear();
        index=0;
    }
    /**
      reset the list of position to default when an exception is catch
     * @brief reset
     */
    void reset(std::invalid_argument&);
    /**
      intialized the lists of marble hexacel and position
     * @brief init_lists
     */
    void init_lists()
    {
        this->elements_hexacell = std::vector<std::shared_ptr<hexacell>>(61);
        auto nbMarble=_game.get_current_player().getAllMarbles().size()+_game.get_opponent_player().getAllMarbles().size();
        this->elements_marbles = std::vector<std::shared_ptr<marble>>(nbMarble);
        this->elements = std::vector<Position>(3);
    }
 /**
   reset the message label
 * @brief set_message
 * @param signal
 */
void set_message(int signal);

};

#endif // ABALONE_GUI_H
