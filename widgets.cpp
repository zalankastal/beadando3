#include "widgets.hpp"
#include "graphics.hpp"
using namespace genv;


Widgets::Widgets(int szelesseg, int magassag) : _szel(szelesseg), _mag(magassag)
{}


void Widgets::palyaRajzol(){

    gout<<move_to(140,90)<<color(120,120,250)<<box(720,620);

    gout<<move_to(120,16)<<color(255,0,0)<<box(20,20);

    gout<<move_to(10,30)<<color(255,255,255)<<text("Ki van soron: ")<<refresh;

    int kx = 0;
    int ky = 0;

    for (int ix = 0; ix < 7; ++ix) {
        kx = 200 + 100*ix;

        for (int iy = 0; iy < 6; ++iy) {
            ky = 150 + 100*iy;

            for (int x = 0; x < _szel; ++x) {
                for (int y = 0; y < _mag; ++y) {
                    if(40*40>=(x-kx)*(x-kx) + (y-ky)*(y-ky)){
                        gout<<move_to(x,y)<<color(0,0,0)<<dot;
                    }
                }
            }
        }
    }
}
