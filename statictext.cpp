#include "statictext.hpp"
#include "widgets.hpp"

using namespace genv;
using namespace std;



StaticText::StaticText(int szelesseg, int magassag, int x, int y, int sx, int sy, std::string text): Widgets(szelesseg,magassag), _x(x), _y(y), _sx(sx), _sy(sy), _text(text){

}

void StaticText::rajzolText(bool jatekos){
    gout<<move_to(_x,_y)<<color(100,100,100)<<box(_sx,_sy)<<move_to(_x+10,_y+_sy/2 + gout.cascent()/2)<<color(255,255,255)<<text(_text);

    if(jatekos){
        gout<<move_to(130,_y+(_sy-15)/2)<<color(255,255,0)<<box(20,20);
    }else{
        gout<<move_to(130,_y+(_sy-15)/2)<<color(255,0,0)<<box(20,20);
    }


    gout<<refresh;
}
