//
// Created by thedushn on 08-Dec-20.
//

#ifndef SHOPING_ITEM_H
#define SHOPING_ITEM_H

#include <ostream>

using namespace std;

class Item {
public:
    Item();
    friend ostream& operator << (ostream&,Item);

    unsigned int getPrice() const;

    unsigned int getCount() const;

    const char *getName() const;

    void setPrice(unsigned int price_new);

    void setCount(unsigned int count_new);

    void setName (const string& string1);

    bool operator==(const Item &rhs) const;

    bool operator!=(const Item &rhs) const;

    Item operator +=(Item);

    Item operator +(Item);

    Item operator -=(Item);



private:
    unsigned int price;
    unsigned int count;
    char name [64];
public:

};


#endif //SHOPING_ITEM_H
