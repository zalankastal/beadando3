#include "jatek.hpp"
#include "graphics.hpp"
#include "iostream"

using namespace genv;
using namespace std;

Jatek::Jatek(int szelesseg,int magassag, vector <vector <int>> v, bool jatekos) : Widgets(szelesseg,magassag), _v(v), _jatekos(jatekos) {
}


void Jatek::kezel(event ev){

    int sor = -1;
    int oszlop = -1;

    if(ev.button == btn_left){
        for (int o = 0; o < 7; ++o) {
            if(ev.pos_x > 160 + o*100  && ev.pos_x < 160 + o*100 + 80 ) {
                for (int s = 0; s < 6; ++s) {
                    if(_v[s][o] == 0){

                        if(sor < 0){
                            sor = s;
                        }
                        if(oszlop < 0){
                            oszlop = o;
                        }

                    }
                }
            }
        }
    }

    if(sor > -1 && oszlop > -1){

        if(_jatekos){
            _v[sor][oszlop]=1;
        }
        else{
            _v[sor][oszlop]=2;
        }

        rajzolKor();
        korok();
    }
}

void Jatek::rajzolKor(){


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

void Jatek::korok(){
    if(_jatekos){
        _jatekos = 0;
    }
    else{
        _jatekos = 1;
    }

}
