//
// Created by thedushn on 04-Dec-20.
//

#ifndef SHOPING_SHOP_H
#define SHOPING_SHOP_H


#include "DLinkedList.h"

class Shop : public DlinkedList {

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
        
        void SetNodeData(Item item_new);

        Item &getItem() ;


    };
        ItemNode* head;
        ItemNode* tail;

    unsigned int    length;
public:
    Shop();

    void Display_list();
    static void Display_item(Item item);
    int  Insert( unsigned int price, unsigned int count, string name);
    void  setItem(Item *item, unsigned int price, unsigned int count, string name);

    virtual ~Shop();
};


#endif //SHOPING_SHOP_H