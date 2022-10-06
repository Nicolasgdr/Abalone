/**
 * Project Untitled
 */


#ifndef _ABAPRO_H
#define _ABAPRO_H

class AbaPro {
public: 
    AbaPro()=default;
    /**
 * @brief AbaPro  Aba pro contructor
 * @param row char that represent the row
 * @param column column of abapro input
 */
    AbaPro(char row,int column):_row(row),_column(column){}
    /**
 * @brief getLigne getter for the line return
 * @return _row
 */
    inline char get_row()const
    {
        return _row;
    }
    /**
 * @brief getColonne getter for column
 * @return _column
 */
    inline int get_column()const
    {
        return _column;
    }
private: 
    char _row;
    int _column;
};

#endif //_ABAPRO_H
