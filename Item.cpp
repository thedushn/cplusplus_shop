//
// Created by thedushn on 08-Dec-20.
//

#include <cstring>
#include <iostream>
#include "Item.h"

Item::Item() {
    memset(this->name,0,sizeof(this->name));
   this->price=0;
   this->count=0;
}

ostream &operator<<(ostream & os, Item item) {
    cout << "Name of item "<<item.name<<endl;
    cout << "Price of item "<<item.price<<endl;
    cout << "Count of item "<<item.count<<endl;
    return os;
}

unsigned int Item::getPrice() const {
    return price;
}

unsigned int Item::getCount() const {
    return count;
}

const char *Item::getName() const {
    return name;
}

void Item::setPrice(unsigned int price_new) {
    Item::price = price_new;
}

void Item::setCount(unsigned int count_new) {
    Item::count = count_new;
}

void Item::setName(const string& string1) {

    strcpy(this->name,string1.c_str());
}

bool Item::operator==(const Item &rhs) const {

    return name == rhs.name;
}

bool Item::operator!=(const Item &rhs) const {
    return !(rhs == *this);
}

Item Item::operator+=(Item item_new) {
    this->count+=item_new.count;
    return (*this);
}

Item Item::operator + (Item item_new) {
    Item temp;
    temp.count=this->count+item_new.count;
    return (temp);
}
