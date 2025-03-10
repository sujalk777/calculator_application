#include "stack_a.h"
#include <iostream>
#include <stdexcept>
using namespace std;

Stack_A::Stack_A(){
    size=0;
}

void Stack_A::push(int data)
{
    if (size >= (1024))
    {
        throw runtime_error("Stack Full");
    }
    else
    {
        stk[size] = data;
        size++;
    }
}

int Stack_A::pop()
{
    if (size < 1)
    {
        throw runtime_error("Empty Stack");
    }
    else
    {
        size--;
        return stk[size];
    }
}
// size -1 at top idx=0
//  size-2 at top idx=1
// size-3 at top idx=2
//... size-idx-1 at top idx=idx

int Stack_A::get_element_from_top(int idx)
{
    if ((size - idx - 1) < 0)
    {
        throw runtime_error("Index out of range");
    }
    else
    {
        return stk[size - idx - 1];
    }
}
// 0 at bottom idx=0
// 1 at bottom idx=1
//.. idx at bottom idx=idx
//  idx<1024

int Stack_A::get_element_from_bottom(int idx)
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

void Stack_A::print_stack(bool top_or_bottom)
{
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

int Stack_A::add()
{
    if (size < 2)
    {
        throw runtime_error("Not Enough Arguements");
    }
    else
    {
        int first = Stack_A::pop();
        int second = Stack_A::pop();
        Stack_A::push(first + second);
        return Stack_A::get_element_from_top(0);
    }
    return 0;
}

int Stack_A::subtract()
{
    if (size < 2)
    {
        throw runtime_error("Not Enough Arguements");
    }
    else
    {
        int first = Stack_A::pop();
        int second = Stack_A::pop();
        Stack_A::push(second - first);
        return Stack_A::get_element_from_top(0);
    }
    return 0;
}

int Stack_A::multiply()
{
    if (size < 2)
    {
        throw runtime_error("Not Enough Arguements");
    }
    else
    {
        int first = Stack_A::pop();
        int second = Stack_A::pop();
        Stack_A::push(first * second);
        return Stack_A::get_element_from_top(0);
    }
    return 0;
}

int Stack_A::divide()
{
    if (size < 2)
    {
        throw runtime_error("Not Enough Arguements");
    }
    else
    {
        int first = Stack_A::pop();
        int second = Stack_A::pop();
        if (first == 0)
        {
            throw runtime_error("Divide by Zero Error");
        }
        else
        {
            if((first * second) < 0){
                Stack_A::push((second/first) - 1);
            }   
            else{
                Stack_A::push((second/first));
            }
            return Stack_A::get_element_from_top(0);
        }
    }
    return 0;
}

int *Stack_A::get_stack()
{
    int* ptr =stk;
    return ptr;
    //return *stk[(1 << 10)];
}

int Stack_A::get_size()
{
    return size;
}


// int main(){
//     Stack_A A;
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
//     cout << A.add() << "\n";
//   cout <<   A.add() << "\n";
//    cout <<  A.add() << "\n";
//    cout <<  A.subtract() << "\n";
//     cout << A.subtract() << "\n";
//   cout << A.divide() << "\n";
//   cout <<  A.divide() << "\n";
//     cout <<  A.multiply() << "\n";
//     cout << A.multiply() << "\n";
// }
