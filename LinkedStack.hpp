//
//  LinkedStack.hpp
//  4.1
//
//  Created by Eric on 17/11/2017.
//  Copyright © 2017 Eric. All rights reserved.
//

#ifndef LinkedStack_hpp
#define LinkedStack_hpp

#include "Node.hpp"

template <typename T>
class LinkedStack {
   
public:
    Node<T> * top;
    LinkedStack(): top(0) {}
    LinkedStack(const LinkedStack<T> & ls);
    ~LinkedStack();
    
    ///别忘了delete []
    T * output(char print = '0') const;
    bool isEmpty() const { return !top; }
    bool contains(const T &) const;
    int size() const;
    T Top() const;
    LinkedStack<T> & push(const T & t);
    LinkedStack<T> & pop(T & receiver);
    LinkedStack<T> & pop();

    
};

template <typename T>
bool LinkedStack<T>::contains(const T & t) const {
    Node<T> * n = top;
    while (n) {
        if (n->data == t)
            return 1;
        n = n->link;
    }
    return 0;
}

template <typename T>
int LinkedStack<T>::size() const {
    int c = 0;
    Node<T> * n = top;
    while (n) {
        c++;
        n = n->link;
    }
    return c;
}
template <typename T>
LinkedStack<T>::~LinkedStack<T>() {
    Node<T> * n;
    while (top) {
        n = top->link;
        delete top;
        top = n;
    }
}

///返回T数组为结果，如果带参数则顺带打印
template <typename T>
T * LinkedStack<T>::output(char print) const {
    if (!top)
        return 0;
    int s = size();
    T * result = new T[s];
    Node<T> * n = top;
    for (int i = 0; i < s; i++) {
        result[s-i-1] = n->data;
        n = n->link;
    }
    if (print != '0') {
        for (int i = 0; i < s; i++)
            cout<<result[i]<<print;
        cout<<endl;
    }
    return result;
}

template <typename T>
T LinkedStack<T>::Top() const {
    if (!top)
        throw OutOfBounds();
    return top->data;
}

template <typename T>
LinkedStack<T> & LinkedStack<T>::push(const T & t) {
    Node<T> * n = new Node<T>;
    n->data = t;
    n->link = top;
    top = n;
    return *this;
}

template <typename T>
LinkedStack<T> & LinkedStack<T>::pop(T & r) {
    if (!top)
        throw OutOfBounds();
    Node<T> * n = top->link;
    r = top->data;
    delete top;
    top = n;
    return *this;
}

template <typename T>
LinkedStack<T> & LinkedStack<T>::pop() {
    if (!top)
        throw OutOfBounds();
    Node<T> * n = top->link;
    delete top;
    top = n;
    return *this;
}

#endif /* LinkedStack_hpp */
