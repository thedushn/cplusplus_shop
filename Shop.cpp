//
// Created by thedushn on 04-Dec-20.
//

#include <cstring>
#include <fstream>
#include "Shop.h"

void Shop::Display_list() {
    cout <<"DISPLAY :\n";
    ItemNode *temp=this->tail;
    while(temp){
        cout<< *temp;

        temp= temp->getNext();


    }

}

int Shop::Insert( unsigned int price, unsigned int count, const string& name_new){

    if(price<=0){
        cout <<"price cant be lower or equal to 0"<<endl;
        return -1;
    }
    if(count<=0){
        cout <<"count cant be lower or equal to 0"<<endl;
        return -1;
    }
    if(name_new.length() <= 0 || name_new.length() >= 63){
        cout <<"name_new must have at least one letter"<<endl;
        cout <<"name_new must be less then 64 letters"<<endl;
        return -1;
    }
    Item item;
    if (this->head== nullptr)
    {
        setItem(&item, price, count, name_new);
        this->head=this->tail=new ItemNode(nullptr,nullptr,item);
        this->length++;


    }
    else
    {

        setItem(&item, price, count, name_new);
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
void Shop::setItem(Item *item, unsigned int price, unsigned int count, string name_new) {

    item->setCount(count);
    item->setPrice(price);
    item->setName(name_new);
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

os << itemNode.getItem();

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

void Shop::DeleteNode(const string &name_new) {
    ItemNode *temp=this->tail;
    while(temp){

        if(strcmp(temp->getItem().getName(), name_new.c_str()) == 0){

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

void Shop::CopyList(Shop::ItemNode *head, Shop::ItemNode *tail) {

}

void Shop::SaveList() {
    ofstream ofstream1;
    ofstream1.exceptions ( ofstream::failbit | ofstream::badbit );
    if(!strlen(this->Shopname)){//shop has no name;
        return;
    }
        try{
            ofstream1.open(this->getName(),ios::out | ios::trunc);
        }
        catch (ofstream::failure &e) {

            cerr << "Exception opening" <<endl;

            return;
        }


    ItemNode *temp=this->tail;
    string text;
    while(temp){

        ofstream1<<*temp;

        temp= temp->getNext();


    }

    ofstream1.close();
}

Shop::Shop(const string& new_name) {

    this->length= 0;
    this->head  = nullptr;
    this->tail  = nullptr;
    if(new_name.length()<=63){
      strcpy(Shopname, new_name.c_str());
    }
    this->Downloadlist(new_name);


}

const char *Shop::getName() const {
    return Shopname;
}

void Shop::Downloadlist(const string& name_new) {
    ifstream myfile(name_new);
    string line;
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            cout << line<<endl;
            Item item_new;
            char nametemp[64]={0};
            string::size_type  found;
            unsigned int price=0;
            unsigned int count=0;
           found= line.rfind(' ');
           string tempstring;
            tempstring=line.substr(found+1);
           strcpy(nametemp,tempstring.c_str());

                item_new.setName(nametemp);

                if(!getline (myfile,line)){
                    break;
                }
            tempstring=line.substr(found+1);
            price= strtoul(tempstring.c_str(), nullptr,10);


                item_new.setPrice(price);

                if(!getline (myfile,line)){
                    break;
                }
            tempstring=line.substr(found+1);
            count= strtoul(tempstring.c_str(), nullptr,10);



                item_new.setPrice(count);




                cout << item_new;
                this->Insert(price, count, nametemp);



        }
        myfile.close();
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










