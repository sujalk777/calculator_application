#include "stack_b.h"
#include<stdexcept>
#include<iostream>
using namespace std;


Stack_B::Stack_B(){
    size=0;
    capacity=(1 << 10);
    stk= new int [(1 << 10)];
}

Stack_B::~Stack_B(){
    delete[] stk;
}
//size is size of array >=1024
//capacity is size of stack
void Stack_B::push(int data){
    try{
        if(capacity == size){
            int *second=new int [capacity*2];
            capacity*=2;
            for(int i(0);i<size;++i){
                second[i]=stk[i];
            }
            delete[] stk;
            stk=second;
        }
        stk[size]=data;
        size++;
    }
    catch(const bad_alloc& e){
        throw runtime_error("Out of Memory");
    }

}

// int Stack_B::pop()
// {   
//     if(size < 1){
//         throw runtime_error("Empty Stack");
//     } 
//     else{
//         if(capacity>1024 && size<=int(capacity/4)){
//         int *second=new int [int(capacity/2)];
//             for(int i(0);i<size;++i){
//                 second[i]=stk[i];
//             }
//             delete[] stk;
//             stk=second; 
//             capacity=int(capacity/2);
//         }
//         size--;
//         return stk[size];
//     }
// }
int Stack_B::pop()
{   
    try{
        if(size < 1){
            throw runtime_error("Empty Stack");
        } 
        else{
            if(capacity>(1 << 10) && size<=(1 << 10)){
                int *second=new int [(1 << 10)];
                for(int i(0);i<size;++i){
                    second[i]=stk[i];
                }
                delete[] stk;
                stk=second;
                capacity=1024;
            }
            size--;
            return stk[size];
        }
    }
    catch(const bad_alloc& e){
        throw runtime_error("Out of Memory");
    }
}


int Stack_B::get_element_from_top(int idx){
    if (size - idx - 1 < 0)
    {
        throw runtime_error("Index out of range");
    }
    else
    {
        return stk[size - idx - 1];
    }
}

int Stack_B::get_element_from_bottom(int idx)
{
     if (idx >= size)
    {
        throw runtime_error("Index out of range");
    }
    else
    {
        return stk[idx];
    }
}

void Stack_B::print_stack(bool top_or_bottom){
    if (top_or_bottom)
    {
        for (int i(size - 1); i >= 0; i--)
        {
            cout << stk[i] << "\n";
        }
    }
    else
    {
        for (int i(0); i < size - 1; i++)
        {
            cout << stk[i] << "\n";
        }
    }
}

int Stack_B::add()
{
    if (size < 2)
    {
        throw runtime_error("Not Enough Arguements");
    }
    else
    {
        int first = Stack_B::pop();
        int second = Stack_B::pop();
        //cout << "first" << first << " " << second << "\n";
        Stack_B::push(first + second);
        return stk[size-1];
    }
    return 0;
}

int Stack_B::subtract()
{
    if (size < 2)
    {
        throw runtime_error("Not Enough Arguements");
    }
    else
    {
        int first = Stack_B::pop();
        int second = Stack_B::pop();
        Stack_B::push(second - first);
        return stk[size-1];
    }
    return 0;
}

int Stack_B::multiply()
{
    if (size < 2)
    {
        throw runtime_error("Not Enough Arguements");
    }
    else
    {
        int first = Stack_B::pop();
        int second = Stack_B::pop();
        Stack_B::push(first * second);
        return stk[size-1];
    }
    return 0;
}

int Stack_B::divide()
{
    if (size < 2)
    {
        throw runtime_error("Not Enough Arguements");
    }
    else
    {
        int first = Stack_B::pop();
        int second = Stack_B::pop();
        if (first == 0)
        {
            throw runtime_error("Divide by Zero Error");
        }
        else
        {
            if((first * second) < 0){
                Stack_B::push((second/first) - 1);
            }   
            else{
                Stack_B::push((second/first));
            }
            return stk[size-1];
        }
    }
}

int *Stack_B::get_stack()
{
    int* ptr =stk;
    return ptr;
}

int Stack_B::get_size()
{
    return size;
}



// int main(){
//     Stack_B A;
//     A.push(2);
//     A.push(10);
//     A.push(-6);
//     A.push(4);
//     A.push(-15);
//     A.push(4);
//     A.push(5);
//     A.push(11);
//     A.push(-9);
//    A.push(-7);
//     cout << A.add();
//   cout <<   A.add();
//    cout <<  A.add();
//    cout <<  A.subtract();
//     cout << A.subtract();
//    cout <<  A.divide();
//     cout << A.divide();
//     cout <<  A.multiply();
//     cout << A.multiply();
// }
