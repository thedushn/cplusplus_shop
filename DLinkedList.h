//
// Created by thedushn on 04-Dec-20.
//

#ifndef SHOPING_DLINKEDLIST_H
#define SHOPING_DLINKEDLIST_H

#include <cstring>
#include <iostream>
#include <iosfwd>
typedef struct Item Item;
struct Item{
    unsigned int price;
    unsigned int count;
    char name [64];



};
using namespace std;
class DlinkedList {

public:
    void append(unsigned int price, unsigned int count, string name);

};


#endif //SHOPING_DLINKEDLIST_H