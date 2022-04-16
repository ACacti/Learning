/*
* @Author: ACacti
* @Date:   2022-04-15 13:30:48
* @Last Modified by:   shang
* @Last Modified time: 2022-04-15 14:45:25
*/

#ifndef STACK_H
#define STACK_H

typedef unsigned long Item;
#include <iostream>
#include <cstring>
class Stack
{
private:
    enum {MAX = 10};
    Item * pitems;
    int size;
    int top;
    void init(int sz, Item *pt,  int tp);
public:

    Stack(int n = MAX);
    Stack(const Stack & st);
    ~Stack();
    bool isempty()const;
    bool isfull() const;
    bool push(const Item &item);
    bool pop(Item &item);
    Stack & operator=(const Stack& st);
};


#endif