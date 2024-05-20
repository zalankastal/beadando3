#ifndef JATEK_HPP
#define JATEK_HPP

#include "graphics.hpp"
#include "widgets.hpp"
#include "statictext.hpp"

class Jatek : public Widgets
{
protected:
    std::vector <std::vector <int>> _v;
    bool _jatekos;
    int _nyertes;

public:
    Jatek(int szelesseg, int magassag, std::vector <std::vector <int>> v, bool jatekos, int nyertes);

    void kezel();
    void korok();
    void sorNyert(int sor, int oszlop);
    void oszlopNyert(int sor, int oszlop);
    void atloJobbFel(int sor, int oszlop);
    void atloBalFel(int sor, int oszlop);
    void dontetlen();
    void gyoztes();
    void ujJatek(genv::event ev);
};

#endif // JATEK_HPP
