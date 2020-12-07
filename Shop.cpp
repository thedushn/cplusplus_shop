//
// Created by thedushn on 04-Dec-20.
//

#include "Shop.h"

void Shop::Display_list() {
    ItemNode *temp=this->tail;
    while(temp){

        Display_item(temp->getItem());
        temp= temp->getNext();


    }

}
void Shop::Display_item(Item item) {

    cout << "Name of item "<<item.name<<endl;
    cout << "Price of item "<<item.price<<endl;
    cout << "Count of item "<<item.count<<endl;
}
int Shop::Insert( unsigned int price, unsigned int count, string name){

    if(price<=0){
        cout <<"price cant be lower or equal to 0"<<endl;
        return -1;
    }
    if(count<=0){
        cout <<"count cant be lower or equal to 0"<<endl;
        return -1;
    }
    if(name.length()<=0 ||name.length()>=63){
        cout <<"name must have at least one letter"<<endl;
        cout <<"name must be less then 64 letters"<<endl;
        return -1;
    }
    Item item;
    if (this->head== nullptr)
    {
        setItem(&item,price,count,name);
        this->head=this->tail=new ItemNode(nullptr,nullptr,item);
        this->length++;


    }
    else
    {
        setItem(&item,price,count,name);
        auto temp=new ItemNode(nullptr,head,item);
        head->setNext(temp);
        head=temp;
        this->length++;


    }


    return 0;
}
void Shop::setItem(Item *item, unsigned int price, unsigned int count, string name) {

    item->count =count ;
    item->price =price ;
    strcpy(item->name, name.c_str());
}

Shop::~Shop() {

    if(tail!= nullptr){
        ItemNode *temp=this->tail;
        while(tail){

                temp =  tail;
                tail = tail->getNext();
                delete temp;


        }
    }


}

Shop::Shop() {
    this->length= 0;
    this->head  = nullptr;
    this->tail  = nullptr;
}


void Shop::ItemNode::SetNodeData(Item item_new) {

    this->item.count =item_new.count ;
    this->item.price =item_new.price ;
    strcpy(this->item.name, item_new.name);

}

Item &Shop::ItemNode::getItem()  {
    return item;
}

Shop::ItemNode *Shop::ItemNode::getNext()  {
    return next;
}

Shop::ItemNode *Shop::ItemNode::getPrev() const {
    return prev;
}

void Shop::ItemNode::setNext(Shop::ItemNode *node) {
    ItemNode::next = node;

}

void Shop::ItemNode::setPrev(Shop::ItemNode *node) {
    ItemNode::prev = node;
}

void Shop::ItemNode::setItem(const Item &item_new) {
    ItemNode::item = item_new;
}

Shop::ItemNode::ItemNode(Shop::ItemNode *next, Shop::ItemNode *prev, Item item) {
    this->item=item;
    this->next=next;
    this->prev=prev;

}

Shop::ItemNode::ItemNode() {
    this->item= {0};
    this->next= nullptr;
    this->prev= nullptr;
}
