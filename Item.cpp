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
    os << "Name of item "<<item.name<<endl;
    os << "Price of item "<<item.price<<endl;
    os << "Count of item "<<item.count<<endl;
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

   if(strcmp(this->name,rhs.name)==0){
       return true;
   }
    return false;
}

bool Item::operator!=(const Item &rhs) const {
    return !(rhs == *this);
}

Item Item::operator+=(Item item_new) {
    if(*this==item_new){
        this->count+=item_new.count;
        return (*this);
    }else{
        return (*this);
    }


}

Item Item::operator + (Item item_new) {
    Item temp;

    if(*this==item_new){
        temp=*this;
        temp.count= this->count+item_new.count;
        return (temp);
    }else{
        return temp;
    }
}

Item Item::operator-=(Item item_new) {

    if(item_new.count>this->count){
        return *this;
    }
    else{
        this->count-=item_new.count;
        return *this;
    }

}


