#include <iostream>
#include <fstream>
#include <cstring>
#include "Shop.h"


using namespace std;

int main() {

    Shop shp("t");
    Shop shp1;
    cout << "dispay list"<<endl;
    shp.Display_list();

    shp.Insert(43,44,"flurers");
    shp.Insert(10,666,"cutters");

    shp.Insert(42,50,"nutters");
    shp.Insert(43,44,"flurers");
    shp.Display_list();
    shp.SaveList();
    string line;


    cout << "dispay list"<<endl;
    shp1.Display_list();
//    shp.DeleteNode("cutters");
//    cout << "two"<<endl;
//    shp.Display_list();
//    shp.DeleteNode("nutters");
//    cout << "one"<<endl;

//
//    shp.Insert(10,666,"cutters");
//    shp.Insert(10,666,"cutters");
//    shp.Insert(45,999,"tsada");


//   shp.Display_list();
//    shp.DeleteNode("flurers");
//    shp.Display_list();

    return 0;
}
