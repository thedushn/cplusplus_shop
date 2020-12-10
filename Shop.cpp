//
// Created by thedushn on 04-Dec-20.
//

#include <cstring>
#include "Shop.h"

void Shop::Display_list() {
    cout <<"DISPLAY :\n";
    ItemNode *temp=this->tail;
    while(temp){
        cout<< *temp;

        temp= temp->getNext();


    }

}

int Shop::Insert( unsigned int price, unsigned int count, const string& name){

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
          if(search(&item)){
              return 0;
          }

        auto temp=new ItemNode(nullptr,head,item);
        head->setNext(temp);

        head=temp;
        this->length++;


    }


    return 0;
}
void Shop::setItem(Item *item, unsigned int price, unsigned int count, string name) {

    item->setCount(count);
    item->setPrice(price);
    item->setName(name);
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



Shop::ItemNode *Shop::getHead() const {
    return head;
}

ostream &operator<<(ostream & os, Shop::ItemNode itemNode) {

cout << itemNode.getItem();

    return os;
}

bool Shop::search(Item *item) {
    ItemNode *temp=this->tail;
    while(temp){
       // cout<< *temp;

        if(temp->getItem()==*item){
            cout<<temp->getItem().getName()<<endl;
            cout<<item->getName()<<endl;
         //   cout << "hello there copy of mine"<<endl;
            temp->getItem()+=*item;

            return true;
        }
        temp= temp->getNext();


    }
    return false;
}

void Shop::DeleteNode(const string &name) {
    ItemNode *temp=this->tail;
    while(temp){

        if(strcmp(temp->getItem().getName(),name.c_str())==0){

            if(temp==this->tail && temp->getNext()== nullptr){ //last item
                    delete temp;
                this->tail=this->head= nullptr;
                return;


            }else if(temp==this->tail){
                temp=temp->getNext();
                delete this->tail;
                temp->setPrev(nullptr);
                this->tail=temp;

            }else if(temp==this->head){
                temp=temp->getPrev();

                delete this->head;
                this->head=temp;
                temp->setNext(nullptr);



            }else{
                ItemNode *temp2=temp->getNext();
                ItemNode *temp0=temp->getPrev();
                temp2->setPrev(temp0);
                temp0->setNext(temp2);
                delete temp;
            }


            return;
        }

        temp= temp->getNext();


    }
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

    this->next= nullptr;
    this->prev= nullptr;
}

void Shop::ItemNode::removeItem() {
    cout <<"we here"<<endl;
    if(this->getNext()== nullptr){//is last or only node

        this->prev= nullptr;
        delete this;
    }
    this->prev->next=this->next;
    delete this;

}








