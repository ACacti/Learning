/*
* @Author: ACacti
* @Date:   2022-04-15 13:44:16
* @Last Modified by:   shang
* @Last Modified time: 2022-04-15 15:22:05
*/

#include "Stack.h"


void Stack::init(int sz, Item *pt, int tp){
    size = sz;
    pitems = pt;
    top = tp;
}
Stack::Stack(int n){
    init(n, new Item[n], 0);
}

Stack::Stack(const Stack &st){
    init(st.size, NULL, st.top);
    pitems = new Item[st.size];
    memcpy(pitems, st.pitems, sizeof(Item) * size);
}

Stack::~Stack()
{
    if(pitems != NULL){
        delete[] pitems;
    }
}

bool Stack::isempty() const{
    if(top == 0)
        return true;
    return false;
}

bool Stack::isfull() const{
    if(top > size - 1){
        return true;
    }
    return false;
}

bool Stack::push(const Item &item){
    if(isfull()){
        return false;
    }
    pitems[top++] = item;
    using std::cout;
    using std::endl;
    return true;
}

bool Stack::pop(Item &item){
    if(isempty()){
        return false;
    }

    item = pitems[--top];
    return true;
}

Stack& Stack::operator=(const Stack& st){
    if(this == &st){
        return *this;
    }

    if(st.pitems != NULL){
        delete[] pitems;
    }
    init(st.size, NULL, st.top);
    pitems = new Item[size];
    memcpy(pitems, st.pitems, sizeof(Item) * st.size);
    return *this;
}