#ifndef SZOV_HPP_INCLUDED
#define SZOV_HPP_INCLUDED
#include "graphics.hpp"
#include "wid.hpp"
#include <string>
#include "cb.hpp"

using namespace genv;

struct szov : public widget
{
    std::string s;
    bool smelyik;
    int szamolo = 2;
    //bool k;
    szov(int num1, int num2, bool num5, std::string str1);
    virtual void rajzol();
    virtual void allito();
    virtual void leir(std::string _s);
    virtual void focusev(int code){}
};


#endif // WID_HPP_INCLUDED
