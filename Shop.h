//
// Created by thedushn on 04-Dec-20.
//

#ifndef SHOPING_SHOP_H
#define SHOPING_SHOP_H


#include <iostream>
#include "Item.h"

class Shop {

private:

    class ItemNode {
    private:
        ItemNode* next;
        ItemNode* prev;
        Item      item{};

    public:
        ItemNode();

        ItemNode(ItemNode *next,ItemNode *prev,Item item);

        void setNext(ItemNode *node);

        void setPrev(ItemNode *node);

        void setItem(const Item &item_new);

        ItemNode *getNext() ;

        ItemNode *getPrev() const;

        void removeItem() ;

        Item &getItem() ;



    };
        ItemNode        * head;
        ItemNode        * tail;
        unsigned int    length;
        char Shopname[64];

        friend ostream & operator << (ostream&,Shop::ItemNode);

        bool search (Item *item);







public:
        Shop();
        Shop(const string& name);

        void Display_list();

        int  Insert( unsigned int price, unsigned int count, const string& name_new);
        void setItem(Item *item, unsigned int price, unsigned int count, string name_new);
        void DeleteNode(const string& name_new);
        void CopyList( ItemNode* head, ItemNode* tail);
        void SaveList();

    const char *getName() const;

    ItemNode *getHead() const;

        virtual ~Shop();
};


#endif //SHOPING_SHOP_H
