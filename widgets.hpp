#ifndef WIDGETS_HPP
#define WIDGETS_HPP

#include "graphics.hpp"

class Widgets
{
protected:
    int _szel, _mag;

public:
    Widgets(int szelesseg, int magassag);
    void palyaRajzol();
    void megnyit();
};

#endif // WIDGETS_HPP
