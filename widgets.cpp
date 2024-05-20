#include "widgets.hpp"
#include "graphics.hpp"

using namespace genv;
using namespace std;


Widgets::Widgets(int szelesseg, int magassag): _szel(szelesseg), _mag(magassag)
{

}

void Widgets::megnyit(){

    gout.open(_szel,_mag);
}

void Widgets::rajzolPalya(){


    gout<<move_to(140,90)<<color(120,120,250)<<box(720,620);


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



    gout<<refresh;
}

void Widgets::rajzolKor(vector <vector <int>> _v){

    for (int s = 0; s < 6; ++s) {
        for (int o = 0; o < 7; ++o) {
            if(_v[s][o]>0){
                for (int x = 0; x < _szel; ++x) {
                    for (int y = 0; y < _mag; ++y) {
                        if(40*40>=(x-(200 + o*100))*(x-(200 + o*100)) + (y-(650-s*100))*(y-(650-s*100))){
                            if(_v[s][o]==1){
                                gout<<move_to(x,y)<<color(255,255,0)<<dot;
                            }
                            else{
                                gout<<move_to(x,y)<<color(255,0,0)<<dot;
                            }
                        }
                    }
                }
            }
        }
    }




    gout<<refresh;
}


