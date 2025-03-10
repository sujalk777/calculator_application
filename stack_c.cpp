#include "stack_c.h"
#include <iostream>
#include <stdexcept>
using namespace std;

Stack_C::Stack_C(){
    try{
        stk=new List;
    }
    catch(const bad_alloc& e){
        throw runtime_error("Out of Memory");
    }
}

Stack_C::~Stack_C()
{
   stk->~List();
   delete stk;
}

void Stack_C::push(int data)
{
    stk->insert(data);

}

int Stack_C::pop()
{
    if(stk->get_size()<1){
        throw runtime_error("Empty Stack");
    }
    else{   
        return stk->delete_tail();   
    }
}

int Stack_C::get_element_from_top(int idx)
{
    if((stk->get_size()-idx-1 ) < 0){
        throw runtime_error("Index out of range");
    }
    else{
         Node *cur=stk->get_head()->next;
        while(cur->next !=nullptr){
            cur=cur->next;
        }
        cur=cur->prev;
        for(int i(stk->get_size()-1);i>=(stk->get_size()-idx);i--){
            cur=cur->prev;
        }
        int y=(cur->get_value());
        return y;   
    }

}


int Stack_C::get_element_from_bottom(int idx)
{
    if(idx >= stk->get_size() ){
        throw runtime_error("Index out of range");
    }
    else{
        Node *cur=stk->get_head()->next;
        int i=0;
        while(i<idx){
            cur=cur->next;i++;
        }
        return (cur->get_value());
    }
}

void Stack_C::print_stack(bool top_or_bottom)
{
    if(top_or_bottom){
        if (stk->get_size()>=1){
        Node *cur=stk->get_head()->next;
        while(cur->next !=nullptr){
            cur=cur->next;
        }
        cur=cur->prev;
        while(cur->prev!=stk->get_head()){
            cout << cur->get_value() << "\n";
            cur=cur->prev;
        }}
    }
    else{
        if (stk->get_size()>0){
        int i=0;
        Node *cur=stk->get_head()->next;
        while(i<stk->get_size()){
            cout << cur->get_value() << "\n";
            cur=cur->next;i++;
        }}
    }

}

int Stack_C::add()
{
    if (stk->get_size() < 2)
    {
        throw runtime_error("Not Enough Arguements");
    }
    else
    {
        int first = Stack_C::pop();
        int second = Stack_C::pop();
        Stack_C::push(first + second);
        return Stack_C::get_element_from_top(0);
    }
}

int Stack_C::subtract()
{
    if (stk->get_size() < 2)
    {
        throw runtime_error("Not Enough Arguements");
    }
    else
    {
        int first = Stack_C::pop();
        int second = Stack_C::pop();
        Stack_C::push(second - first);
        return Stack_C::get_element_from_top(0);
    }
}

int Stack_C::multiply()
{
    if (stk->get_size() < 2)
    {
        throw runtime_error("Not Enough Arguements");
    }
    else
    {
        int first = Stack_C::pop();
        int second = Stack_C::pop();
        Stack_C::push(first * second);
        return Stack_C::get_element_from_top(0);
    }
}

int Stack_C::divide()
{
    if (stk->get_size() < 2)
    {
        throw runtime_error("Not Enough Arguements");
    }
    else
    {
        int first = Stack_C::pop();
        int second = Stack_C::pop();
        if (first == 0)
        {
            throw runtime_error("Divide by Zero Error");
        }
        else
        {
            if((first * second) < 0){
                Stack_C::push((second/first) - 1);
            }   
            else{
                Stack_C::push((second/first));
            }
            return Stack_C::get_element_from_top(0);
        }
    }
}

List *Stack_C::get_stack()
{
    return stk;
}

int Stack_C::get_size()
{
    return stk->get_size();
}
