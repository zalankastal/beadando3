#ifndef STATICTEXT_HPP
#define STATICTEXT_HPP

#include "graphics.hpp"
#include "widgets.hpp"


class StaticText : public Widgets
{
protected:
    int _x;
    int _y;
    int _sx;
    int _sy;
    std::string _text;

public:
    StaticText(int , int ,int, int, int, int, std::string);

    void rajzolText(bool jatekos);
};

#endif // STATICTEXT_HPP
