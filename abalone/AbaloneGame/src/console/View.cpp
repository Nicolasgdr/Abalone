#include "View.h"
void View::displayBoard(Game &game) {
    auto board = game.get_board();
    for (int i=0;i<board.getRow() ;i++ ) {
        for (int j=0;j<board.getColumn() ;j++ ) {
            Position instance(i,j);
            auto row = get_abapro_row(i);
            auto col = get_abapro_col(instance);
            switch (i) {
            case 0:
            case 10:
                if(j>=8 && j<=17){
                    std::cout<<"x";
                }else{
                    std::cout<<" ";
                }
                break;
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
                displayFirstPart(row,instance,game);
                break;
            case 6:
            case 7:
            case 8:
            case 9:
                displaySndPart(row,col,instance,game);
                break;
            case 11:
                switch (j) {
                case 9:
                    std::cout<<1;
                    break;
                case 11:
                    std::cout<<2;
                    break;
                case 13:
                    std::cout<<3;
                    break;
                case 15:
                    std::cout<<4;
                    break;
                case 17:
                    std::cout<<5;
                    break;
                default: std::cout<<" ";
                }
                break;

            }
        }
        std::cout<<std::endl;
    }
}

void View::displayFirstPart(char row,Position instance, Game&game)
{
    auto board= game.get_board();
    switch (board.getsquareAt (instance).getType())
    {
    case Type::X :
        if(instance.getColumn()==4 || instance.getColumn()<5){
            std::cout<<row<<"->" << "x ";
        }else{
            std::cout<< " x";
        }
        break;

    case Type::BUSY :
    {
        if (game.marble_is_present_at (instance))
        {
            Marble marble = game.get_marble_at (instance);
            if (marble.getColor()== Color::WHITE)
            {
                std::cout << "W";
            }else if(marble.getColor()== Color::BLACK){
                std::cout << "B";
            }

        }
        break;
    case Type::EMPTY :
            std::cout << "-";
            break;
        default:
            std::cout << " ";
        }
    }
}

char View::get_abapro_row(int row)
{

    switch (row) {
    case 1 :
        return 'I';
    case 2 :
        return 'H';
    case 3:
        return 'G';
    case 4:
        return 'F';
    case 5 :
        return 'E';
    case 6 :
        return 'D';
    case 7:
        return 'C';
    case 8:
        return 'B';
    case 9 :
        return 'A';

    }
    return 0;
}

std::string &View::playerInput()
{
    std::cout<<"ENTER ABAPRO MOVEMENT :"<<std::endl;
    static std::string input;
    auto const regex = std::regex("([A-I]\\d){2}");
    std::cin>>input;
    auto matches = std::regex_search(input.begin(),input.end(),regex);
    while(!matches){
        std::cout<<"Input Incorrect..."<<std::endl;
        std::cin>>input;
        matches = std::regex_search(input.begin(),input.end(),regex);
    }

    return input;
}

std::vector<AbaPro> View::tabInput(std::string&input)
{
    auto aba_pro = std::vector<AbaPro>(input.size()/2);
    if(aba_pro.size()==2)
    {
        auto col = input.at(1)-'0';
        auto col2 = input.at(3)-'0';
        aba_pro.at(0)= AbaPro(input.at(0),col);
        aba_pro.at(1)= AbaPro(input.at(2),col2);
    }else{
        auto col = input.at(1)-'0';
        auto col2 = input.at(3)-'0';
        auto col3 = input.at(5)-'0';
        aba_pro.at(0)= AbaPro(input.at(0),col);
        aba_pro.at(1)= AbaPro(input.at(2),col2);
        aba_pro.at(2)= AbaPro(input.at(4),col3);

    }

    return aba_pro;
}


void View::print_msg (const std::string message)
{
    std::cout << message << std::endl;
}

Color View::player_color ()
{
    char color;
    std::cin >> color;
    while (!valid_input (color))
    {
        print_msg ("Color input not valid retry...");
        std::cin >> color;
    }
    return color == 'w' ? Color::WHITE : Color::BLACK;
}

bool View::valid_input (char &color)
{
    return color == 'w' || color == 'b';
}

void View::printPlayer(Player currentP)
{
    char player = currentP.getPlayerColor();
    if(player==Color::WHITE){
        print_msg("PLAYER WHITE: ");
    }else{
        print_msg("PLAYER BLACK: ");
    }
}

void View::displaySndPart(char row,int col,Position instance, Game&game)
{
    auto board= game.get_board();
    switch (board.getsquareAt (instance).getType())
    {
    case Type::X :
        if(instance.getColumn()>=14 && instance.getColumn()<=18){
            std::cout<< " x"<<"\\-> "<<col;
        }else{
            if(instance.getColumn()==1 || instance.getColumn()<=4){
                std::cout<<row<<"->" << "x ";
            }else{
                std::cout<< " x";
            }
        }
        break;

    case Type::BUSY :
    {
        if (game.marble_is_present_at (instance))
        {
            Marble marble = game.get_marble_at (instance);
            if (marble.getColor()== Color::WHITE)
            {
                std::cout << "W";
            }else if(marble.getColor()== Color::BLACK){
                std::cout << "B";
            }

        }
        break;
    case Type::EMPTY :
            std::cout << "-";
            break;
        default:
            std::cout << " ";
        }
    }

}
int View::get_abapro_col(Position&instance)
{
    auto row = instance.getRow();
    auto column = instance.getColumn();
    if(row==6 && column==17){
        return 9;
    }else if(row==7 && column==16){
        return 8;
    }else if(row==8 && column==15){
        return 7;
    }else if(row==9 && column==14){
        return 6;
    } else if(row==10 && column==13){
        return 5;
    }
    return 0;
}
