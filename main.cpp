#include "graphics.hpp"
#include "widgets.hpp"
#include "jatek.hpp"
#include "iostream"

using namespace std;
using namespace genv;

class MyApp: public Widgets
{
public:
    MyApp(int szelesseg,int magassag): Widgets(szelesseg,magassag){

    }
    void tabla(){
        event ev;

        vector<vector<int>> v (6, vector<int>(7, 0));

        Jatek* j = new Jatek(_szel,_mag,v,0,0);

        j->megnyit();
        j->start();
        j->kezel();
    }

protected:
    Jatek* j;
};



int main()
{
    MyApp app(1000,800);


    app.tabla();
    return 0;
}
