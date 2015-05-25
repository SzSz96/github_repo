#ifndef WID_HPP_INCLUDED
#define WID_HPP_INCLUDED
#include "graphics.hpp"

using namespace genv;

class widget
{
    protected:
    int x, y, sx, sy;

    public:
    bool focus, focusable;
    widget(int num1, int num2, int num3, int num4);
    virtual void rajzol() = 0;
    virtual void focusev(int code) = 0;
    virtual void focusjel();
    virtual void katt(genv::event ev);
    virtual void allito();
    virtual void kovetkezo();
    virtual void valt(int px, int py);
    bool setf(int px, int py);
};

#endif // WID_HPP_INCLUDED
