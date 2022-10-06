#include"Board.h"
Square Board::getsquareAt(Position position)
{
    return this->_grille.at(position.getRow()).at(position.getColumn());
}
void Board::createBoard()
{
    auto arrays = g_function::square_busy();
    int numRow = 1;
    auto begin = 5;
    auto row_size=getRow();
    auto column_size = getColumn();
    for (auto row =0;row<row_size;row++ ) {
        for (auto column=0;column<column_size ;column++ ) {
            if (column>=begin && column<(column_size-begin))
            {
                {
                    if((row >=numRow && row<=5) || (row>=6 && row <=9))
                    {
                        if(column == begin || column==((column_size-1)-begin)){
                            this->_grille.at(row).at(column)= Square(Type::X);

                        }else{
                            auto position = Position(row, column);
                            if(square_is_busy(arrays,position)){
                                this->_grille.at(row).at(column)= Square(Type::BUSY);
                            }else{

                                if((column%2==0 && row%2!=0) || (column %2 !=0 && row %2 == 0)){
                                    this->_grille.at(row).at(column)= Square(Type::OUT_OF_BOND);

                                }else{
                                    this->_grille.at(row).at(column)= Square(Type::EMPTY);
                                }
                            }
                        }
                    }
                }
            }else{
                this->_grille.at(row).at(column)= Square(Type::OUT_OF_BOND);
            }
            if(column == (column_size-1)){
                if(row>=0 && row<5){
                    begin--;
                }else{
                    if(row>=5 && row<=10){
                        begin++;
                    }
                }
            }
        }
    }
}
bool Board::square_is_free(Position &pos)
{
    return this->_grille.at(pos.getRow()).at(pos.getColumn()).is_free();
}
void Board::setSquareType(Position position, Type& type)
{
    this->_grille.at(position.getRow()).at(position.getColumn()).set_square(type);
}




