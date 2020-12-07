#include <iostream>
#include "Shop.h"


using namespace std;

int main() {

    Shop shp;
    //  Shopper a;

    shp.Insert(43,44,"flurers");
    shp.Insert(42,50,"nutters");


    shp.Insert(10,666,"cutters");
    shp.Insert(45,999,"tsada");

    // a.setList(shp.getItem());
    shp.Display_list();
    return 0;
}
