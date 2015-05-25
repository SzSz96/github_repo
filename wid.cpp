
#include "graphics.hpp"
#include "wid.hpp"
using namespace genv;

widget::widget(int num1, int num2, int num3, int num4)
    {
        x = num1; y = num2; sx = num3; sy = num4; focus = false; focusable = false;
    }

void widget::focusjel()
{
    /*if(focus == true)
        {
            gout << color(0,150,150);
            for(int i = 0; i <= sx+9; i++)
        {
                    gout << move_to(x+i-5, y-5);
                    gout << dot;
                    gout << move_to(x+i-5, y+sy+5);
                    gout << dot;
        }
            for(int i = 0; i < sy+10; i++)
        {
                    gout << move_to(x-5, y+i-5);
                    gout << dot;
                    gout << move_to(x+sx+5, y+i-5);
                    gout << dot;
        }
        }*/
    }

bool widget::setf(int px, int py)
    {
        if(px >= x and px <= x+sx and py >= y and py <= y+sy and focusable == true)
        {
            focus = true;
            return true;
        }
        else
        return false;
    }

void widget::valt(int px, int py)
{

}

void widget::katt(event ev)
{

}

void widget::allito()
{

}
