#ifndef JATEK_HPP
#define JATEK_HPP

#include "graphics.hpp"
#include "widgets.hpp"

class Jatek : public Widgets
{
protected:
    std::vector <std::vector <int>> _v;
    bool _jatekos;
    int _nyertes;

public:
    Jatek(int szelesseg, int magassag, std::vector <std::vector <int>> v, bool jatekos, int nyertes);

    virtual void kezel(genv::event ev) override;
    void rajzolKor();
    void korok();
    void sorNyert(int sor, int oszlop);
    void oszlopNyert(int sor, int oszlop);
    void atloJobbFel(int sor, int oszlop);
    void atloBalFel(int sor, int oszlop);
    void dontetlen();
    void gyoztes();
    void ujJatek(genv::event ev);
    void start();
};

#endif // JATEK_HPP
