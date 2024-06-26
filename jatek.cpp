#include "jatek.hpp"
#include "graphics.hpp"

using namespace genv;
using namespace std;

Jatek::Jatek(int szelesseg,int magassag, vector <vector <int>> v, bool jatekos, int nyertes) : Widgets(szelesseg,magassag), _v(v), _jatekos(jatekos), _nyertes(nyertes) {
}


void Jatek::kezel(){

    event ev;

    StaticText* s = new StaticText(_szel,_mag,10,10,200,50,"Ki van soron: ");

    s->rajzolText(_jatekos);


    while(gin >> ev && ev.keycode != key_escape) {

        int sor = -1;
        int oszlop = -1;




        if(ev.button == btn_left){
            for (int o = 0; o < 7; ++o) {
                if(ev.pos_y > 90 && ev.pos_y < 710){
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
        }



        if(sor > -1 && oszlop > -1){

            if(_jatekos){
                _v[sor][oszlop]=1;
            }
            else{
                _v[sor][oszlop]=2;
            }

            if(_nyertes<1){
                oszlopNyert(sor,oszlop);
                sorNyert(sor,oszlop);
                atloJobbFel(sor,oszlop);
                atloBalFel(sor,oszlop);
                dontetlen();
                rajzolKor(_v);
                korok();
            }
        }

        if(_nyertes>0){
            ujJatek(ev);
        }



        s->rajzolText(_jatekos);
    }


    delete s;
}


void Jatek::korok(){
    if(_jatekos){
        _jatekos = 0;
    }
    else{
        _jatekos = 1;
    }
}

void Jatek::oszlopNyert(int sor, int oszlop){

    int szin = _v[sor][oszlop];
    int db = 1;

    for (int i = 1; i < 4; ++i) {
        if(sor-i >= 0 ){
            if(_v[sor-i][oszlop] == szin){
                db++;
            }
        }
    }

    if(db>3){
        _nyertes = szin;

        gyoztes();
    }
}


void Jatek::sorNyert(int sor, int oszlop){

    int szin = _v[sor][oszlop];
    int db = 1;

    for (int i = 1; i < 4; ++i) {
        if(oszlop-i >= 0 ){
            if(_v[sor][oszlop-i] == szin){
                db++;
            }
            else{
                break;
            }
        }
    }

    for (int i = 1; i < 4; ++i) {
        if(oszlop+i <= 6){
            if(_v[sor][oszlop+i] == szin){
                db++;
            }
            else{
                break;
            }
        }
    }


    if(db>3){
        _nyertes = szin;

        gyoztes();
    }
}



void Jatek::atloBalFel(int sor, int oszlop){
    int szin = _v[sor][oszlop];
    int db = 1;

    for (int i = 1; i < 4; ++i) {
        if(sor+i <= 5 && oszlop-i >= 0){
            if(_v[sor+i][oszlop-i] == szin){
                db++;
            }
            else{
                break;
            }
        }
    }

    for (int i = 1; i < 4; ++i) {
        if(sor-i >= 0 && oszlop+i <= 6){
            if(_v[sor-i][oszlop+i] == szin){
                db++;
            }
            else{
                break;
            }
        }
    }

    if(db>3){
        _nyertes = szin;


        gyoztes();
    }
}

void Jatek::atloJobbFel(int sor, int oszlop){
    int szin = _v[sor][oszlop];
    int db = 1;

    for (int i = 1; i < 4; ++i) {
        if(sor-i >= 0 && oszlop-i >= 0){
            if(_v[sor-i][oszlop-i] == szin){
                db++;
            }
            else{
                break;
            }
        }
    }

    for (int i = 1; i < 4; ++i) {
        if(sor+i <= 5 && oszlop+i <= 6){
            if(_v[sor+i][oszlop+i] == szin){
                db++;
            }
            else{
                break;
            }
        }
    }

    if(db>3){
        _nyertes = szin;


        gyoztes();
    }
}

void Jatek::gyoztes(){
    if(_nyertes == 1){
        gout<<move_to(450,30)<<color(255,255,255)<<text("Gyoztes: Sarga");
    }
    else{
        gout<<move_to(450,30)<<color(255,255,255)<<text("Gyoztes: Piros");
    }
    gout<<move_to(415,60)<<color(255,255,255)<<text("'Enter' az uj jatekhoz");
}

void Jatek::dontetlen(){
    int db = 0;

    for (int s = 0; s < 6; ++s) {
        for (int o = 0; o < 7; ++o) {
            if(_v[s][o]>0){
                db++;
            }
        }
    }

    if(db == 42 && _nyertes == 0){
        gout<<move_to(460,30)<<color(255,255,255)<<text("Dontetlen");
        gout<<move_to(415,60)<<color(255,255,255)<<text("'Enter' az uj jatekhoz");
        _nyertes = 3;
    }
}

void Jatek::ujJatek(event ev){



    if(ev.keycode == key_enter){
        for (int s = 0; s < 6; ++s) {
            for (int o = 0; o < 7; ++o) {
                _v[s][o] = 0;
            }
        }

        gout<<move_to(0,0)<<color(0,0,0)<<box(_szel,_mag);

        rajzolPalya();
        _jatekos = 0;
        _nyertes = 0;
    }

}


