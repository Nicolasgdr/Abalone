#ifndef GENERAL_FUNCTION_HPP
#define GENERAL_FUNCTION_HPP
#include "vector"
#include "Position.hpp"
/**
  Attribut of general function
 * @brief square_busy
 * @return
 */
std::vector<Position>square_busy();
/**
  combine general method
 * @brief The g_function struct
 */
struct g_function
{
    static std::vector<Position>square_busy()
    {
        auto arrays = std::vector<Position>(14*2);
        int index = 0;
                  int column = 5;
                  int limit = 13;
                  int i = 1;
                  int begin_row = 1;
                  int end_row = 3;
                  while (i <= 2)
                    {
                      if (i == 2)
                        {
                          begin_row = 7;
                          end_row = 9;
                          column = 7;
                          limit = 12;
                        }
                      for (int row = begin_row; row <= end_row; row++)
                        {

                          switch (row)
                            {
                              case 2:
                              case 8:
                                column = 4;
                              limit = 15;
                              break;
                              case 3:
                                column = 7;
                              limit = 12;
                              break;
                              case 9:
                                column = 5;
                              limit = 14;
                              default:;
                            }
                          for (; column <= limit; column += 2)
                            {
                              arrays.at (index) = Position (row, column);
                              index++;
                            }
                        }
                      i++;
                    }


        return arrays;
    }
};

#endif // GENERAL_FUNCTION_HPP
