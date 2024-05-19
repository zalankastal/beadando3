#ifndef WIDGETS_HPP
#define WIDGETS_HPP

#include "graphics.hpp"

class Widgets
{
protected:
    int _szel, _mag;

public:
    Widgets(int szelesseg, int magassag);
    virtual void palyaRajzol();
    virtual void kezel(genv::event ev) = 0;
};

#endif // WIDGETS_HPP
