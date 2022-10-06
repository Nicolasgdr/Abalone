#ifndef GENERAL_FUNCTION_GUI_H
#define GENERAL_FUNCTION_GUI_H

#include "cmath"
/**
  concert the dx and dy to the hexacel shape
 * @brief convert_dx_dy
 */
void convert_dx_dy(int&,int&);

struct g_function_gui{
    static void convert_dx_dy(int&dx,int&dy)
    {
        double rad = 50;
        double horizontalSpace = sqrt(3)*rad;
        double verticalSpace = -1.5*rad;
        double horizontalShift,verticalShift=0.;

        if(dx%2==0){
            horizontalShift=-7.5*horizontalSpace;
            verticalShift=(5-dx)*verticalSpace;
            dx=dy/2;
        }else{
            horizontalShift=-8*horizontalSpace;
            verticalShift=(5-dx)*verticalSpace;
            dx=(dy/2)+1;
        }

        dx = horizontalShift+horizontalSpace*dx;
        dy= verticalShift;

    }

};

#endif // GENERAL_FUNCTION_GUI_H
