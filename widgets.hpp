#ifndef WIDGETS_HPP
#define WIDGETS_HPP

#include "graphics.hpp"

class Widgets
{
protected:
    int _szel, _mag;

public:
    Widgets(int szelesseg, int magassag);
    void rajzolPalya();
    void megnyit();
    void rajzolKor(std::vector <std::vector <int>> _v);
};

#endif // WIDGETS_HPP
