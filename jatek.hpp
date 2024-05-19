#ifndef JATEK_HPP
#define JATEK_HPP

#include "graphics.hpp"
#include "widgets.hpp"

class Jatek : public Widgets
{
protected:
    std::vector <std::vector <int>> _v;
    bool _jatekos;

public:
    Jatek(int szelesseg, int magassag, std::vector <std::vector <int>> v, bool jatekos);

    virtual void kezel(genv::event ev) override;
    void rajzolKor();
    void korok();
};

#endif // JATEK_HPP
