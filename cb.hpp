#ifndef CB_HPP_INCLUDED
#define CB_HPP_INCLUDED
#include "graphics.hpp"
#include "wid.hpp"
#include <vector>
#include <iostream>

using namespace genv;
using namespace std;

struct cb : public widget
{
    bool status, melyik;
    int szamlalo = 1;
    cb(int num1, int num2, int num3, int num4, bool num5);
    virtual bool all() const;
    virtual void kovetkezo();
    virtual void rajzol();
    virtual void valt(int px, int py);
    virtual void focusev(int code);

};


#endif // CB_HPP_INCLUDED
