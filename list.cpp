#include "list.h"
#include <iostream>
#include <stdexcept>
using namespace std;
#include "node.h"

List::List(){    
    sentinel_tail=new Node(true);
    sentinel_head=new Node(true);
    sentinel_tail->prev=sentinel_head;
    sentinel_head->next=sentinel_tail;
    size=0;
}

List::~List(){
    if(get_size()>=1){
        Node *cur=sentinel_head->next;
        while(cur->next->is_sentinel_node()!=true){
            cur=cur->next;
            delete cur->prev;
        }
    delete sentinel_head;
    delete sentinel_tail;
}}

void List::insert(int v){
    try{
        Node *new_Node=new Node(v,sentinel_tail,sentinel_tail->prev);
        new_Node->prev->next=new_Node;
        sentinel_tail->prev=new_Node;
        size++;
    }
    catch(const bad_alloc& e){
        throw runtime_error("Out of Memory");
    }
}

int List::delete_tail()
{
    Node *cur=sentinel_tail->prev;
    int value_cur=cur->get_value();
    sentinel_tail->prev= cur->prev;
    cur->prev->next=sentinel_tail;
    delete cur;
    size--;
    return value_cur;
}

int List::get_size()
{
    return size;
}

Node *List::get_head()
{
    return sentinel_head;
}
