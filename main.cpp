#include "graphics.hpp"
#include "widgets.hpp"
#include "jatek.hpp"
#include "iostream"

using namespace std;
using namespace genv;

const int szelesseg = 1000;
const int magassag = 800;


int main()
{
    gout.open(szelesseg,magassag);

    event ev;


    vector<vector<int>> v (6, vector<int>(7, 0));




    Jatek* j = new Jatek(szelesseg,magassag,v,0,0);

    j->palyaRajzol();






    gout<<refresh;


    while(gin >> ev && ev.keycode != key_escape) {

        j->kezel(ev);



    }
    return 0;
}
