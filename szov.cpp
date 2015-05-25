    #include <string>
    #include "szov.hpp"
    #include "graphics.hpp"
    using namespace genv;

    szov::szov(int num1, int num2, bool num5, std::string str1)
    : widget(num1, num2, gout.twidth(str1)+4, 21)
    {
        s = str1;
        focusable = false;
    }

    void szov::allito()
    {
        if(btn_left == 1 && szamolo%2 == 1)
        {
            szamolo++;
            smelyik = true;
        }
        else
        {
            szamolo++;
            smelyik = false;
        }
    }

    void szov::rajzol()
    {
        gout << move_to(x, y+sy);
        if (smelyik == true)
        {
            gout << color(150,0,150);
        }
        else
        {
            gout << color(0,150,150);
        }
        gout << text(s);
    }

    void szov::leir(std::string _s)
    {
         s = _s;
    }
