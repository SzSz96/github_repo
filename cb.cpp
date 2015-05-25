#include "graphics.hpp"
#include "cb.hpp"
using namespace genv;
using namespace std;

cb::cb(int num1, int num2, int num3, int num4, bool num5)
        : widget(num1, num2, num3, num4)
    {
        status = num5;
        focusable = true;
        focus = false;
    }



bool cb::all() const
    {
        if(status) return true;
        else return false;
    }

void cb::rajzol()
    {
        gout << move_to(x, y);
        for(int i = 0; i < sx; i++)
        {
            for(int j = 0; j < sy; j++)
            {gout << move_to(x+i, y+j);
                if(j == 0 or j == sy-1 or i == 0 or i == sx-1)
                    gout << color(128,128,128);
                else
                {
                    if(status == true and (i == j or i == sy-j))
                        gout << color(0,192,0);
                    else
                        gout << color(250,250,250);
                }
                gout << dot;
            }
        }
        for(int i = 3; i < sx-3; i++)
        {
            for(int j = 3; j < sy-3; j++)
            {gout << move_to(x+i, y+j);
                if(j == 0 or j == sy-1 or i == 0 or i == sx-1)
                    gout << color(128,128,128);
                else
                {
                    if(status == true)
                    {
                        if (btn_left == 1 && szamlalo%2 == 1)
                        {
                            szamlalo++;
                            gout << color(150,0,150);
                        }
                        else
                        {
                            szamlalo++;
                            gout << color(0,150,150);
                        }
                    }
                    else
                    {
                        gout << color(0,0,0);
                    }
                }
                gout << dot;
            }
        }
        //std::cout << sorszam;
    }

void cb::valt(int px, int py)
    {
        if(px > x and px < x+sx and py > y and py < y+sy)
            {
                    if(status == true)
                    {
                        status = true;
                    }
                    else
                    {
                        status = true;
                    }
            }
    }

void cb::focusev(int code)
    {
        if(code == 32)
        {
                /*if(status == true)
                {
                    status = false;
                }
                else
                {
                   status = true;
                }*/
        }
    }
