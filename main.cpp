#include "graphics.hpp"
#include <fstream>
#include <iostream>
#include <vector>
#include <math.h>
#include <cstdlib>
#include <stdio.h>
#include <time.h>
#include "szov.hpp"
#include "cb.hpp"
#include "jatekmester.hpp"

using namespace genv;
using namespace std;

const int szel = 640;
const int mag = 670;

int main()
{
    gout.open(szel,mag);

    vector< vector<widget*> > wid;
    vector<widget*> sor;
    vector<string> elemek;
    vector<widget*> szoveges;

    szov* s = new szov(30, 0, true, "A lila/kék játékos rak.");

    for (int j = 0; j < 40 ; j++)
    {
        wid.push_back(vector<widget*>());
        for (int i = 0; i < 40; i++)
        {
            cb* sor = new cb(0+i*16, 30+j*16, 16, 16, false);
            wid[j].push_back(sor);
        }
    }
    szoveges.push_back(s);

    event ev;
    gin.timer(500);
    while(gin >> ev && ev.keycode != key_escape)
        {
            if(ev.button == btn_left)
            {
                for (int j = 0; j < 40; j++)
                {
                    for (int i = 0; i < 40; i++)
                    {
                        wid[j][i]->valt(ev.pos_x, ev.pos_y);
                    }
                }
                for(int z = 0; z < szoveges.size(); z++)
                {
                    szoveges[z]->allito();
                }
                bool tmpbool = false;
                for (int j = 0; j < 40; j++)
                {
                    for (int i = 0; i < 40; i++)
                    {
                    if(wid[j][i]->focus == true);
                    {
                        wid[j][i]->focus = false;
                        if (tmpbool == false)
                        tmpbool = wid[j][i]->setf(ev.pos_x, ev.pos_y);
                    }
                    }

                }
            }

            if((ev.keycode >= 32 and ev.keycode <= 126) or ev.keycode == 8)
            {
                for (int j = 0; j < 40; j++)
                {
                    for (int i = 0; i < 40; i++)
                    {
                        if (wid[j][i]->focus == true)
                        wid[j][i]->focusev(ev.keycode);
                    }
                }
            }

            if(ev.keycode == key_f1)
            {
                ofstream fki;
                fki.open("adatok.txt");
                //fki << box1->all() << endl;
                //fki << box2->all() << endl;
                fki.close();
            }

            if(ev.keycode == key_tab)
            {
                bool tmpbool = false, fc = false;
                for (int j = 0; j < 40; j++)
                {
                    for (int i = 0; i < 40; i++)
                    {
                if (tmpbool == true and wid[j][i]->focusable == true)
                {
                    wid[j][i]->focus = true;
                    tmpbool = false;
                    break;
                }
                if (wid[j][i]->focus == true)
                {
                    wid[j][i]->focus = false;
                    fc = true;
                    tmpbool = true;
                }
                }
                if (tmpbool == true or fc == false)
                {
                    for(unsigned int i = 0; i< wid.size(); i++)
                    {
                    if(wid[j][i]->focusable == true)
                    {
                    wid[j][i]->focus = true;
                    tmpbool = false;
                    break;
                    }
                    }
                }
                }
            }

            if(ev.type==ev_timer)
            {
                gout << move_to(0,0) << color(0,0,0);
                gout << box_to(szel-1,mag-1);

                for (int j = 0; j < 40; j++)
                {
                    for (int i = 0; i < 40; i++)
                    {
                        wid[j][i]->rajzol();
                        if (wid[j][i]->focus == true)
                        wid[j][i]->focusjel();
                    }
                }
                for(int z = 0; z < szoveges.size(); z++)
                {
                    szoveges[z]->rajzol();
                }

            gout << refresh;
            }

        }

    return 0;
}
