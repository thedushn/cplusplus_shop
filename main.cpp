#include <iostream>
#include "Shop.h"


using namespace std;

int main() {

    Shop shp;
    //  Shopper a;
    Item a;
    Item b;
    Item c;
    a.setName("flurers");
    a.setPrice(60);

    b.setName("445");
    a.setCount(2344324);
    b.setCount(6);
    c=a+b;
    cout<<c;
//    shp.Insert(43,44,"flurers");
//    shp.Insert(10,666,"cutters");
//
//    shp.Insert(42,50,"nutters");
//    cout << "all threee"<<endl;
//    shp.Display_list();
//    shp.DeleteNode("cutters");
//    cout << "two"<<endl;
//    shp.Display_list();
//    shp.DeleteNode("nutters");
//    cout << "one"<<endl;
//
////
////    shp.Insert(10,666,"cutters");
////    shp.Insert(10,666,"cutters");
////    shp.Insert(45,999,"tsada");
//
//
//   shp.Display_list();
//    shp.DeleteNode("flurers");
//    shp.Display_list();

    return 0;
}
