#include <iostream>
#include "Shop.h"


using namespace std;

int main() {

    Shop shp;
    //  Shopper a;
    cout <<shp.getName()<<endl;
    shp.Insert(43,44,"flurers");
    shp.Insert(10,666,"cutters");

    shp.Insert(42,50,"nutters");
    shp.Insert(43,44,"flurers");
   // shp.Display_list();
    shp.SaveList();
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
