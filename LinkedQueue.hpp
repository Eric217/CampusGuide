//
//  LinkedQueue.hpp
//  8.1
//
//  Created by Eric on 29/11/2017.
//  Copyright © 2017 Eric. All rights reserved.
//

#ifndef LinkedQueue_hpp
#define LinkedQueue_hpp

#include "Node.hpp"
///front = 0 时队列为空
template <typename T>
class LinkedQueue {
    Node<T> * front;
    Node<T> * rear;
    
public:
    LinkedQueue(): front(0), rear(0) {}
    ~LinkedQueue();
    bool isEmpty() const { return !front; }
    int size() const;
    T first() const;
    T last() const;
    LinkedQueue<T> & push(const T &);
    LinkedQueue<T> & pop(T &);
    T * output() const;
    
};

template <typename T>
int LinkedQueue<T>::size() const {
    Node<T> * node = front;
    int s = 0;
    while (node) {
        s++;
        node = node->link;
    }
    return s;
}

///delete manually!!!
template <typename T>
T * LinkedQueue<T>::output() const {
    if (!front)
        return 0;
    int s = size();
    T * arr = new T[s];
    Node<T> * node = front;
    for (int i = 0; i < s; i++) {
        arr[i] = node->data;
        node = node->link;
    }
    return arr;
}

template <typename T>
LinkedQueue<T>::~LinkedQueue() {
    while (front) {
        Node<T> * node = front->link;
        delete front;
        front = node;
    }
}

template <typename T>
T LinkedQueue<T>::first() const {
    if (front)
        return front->data;
    throw OutOfBounds();
}

template <typename T>
T LinkedQueue<T>::last() const {
    if (front)
        return rear->data;
    throw OutOfBounds();
}

template <typename T>
LinkedQueue<T> & LinkedQueue<T>::push(const T & t) {
    Node<T> * node = new Node<T>;
    node->data = t;
    node->link = 0;
    if (front)
        rear = rear->link = node;
    else
        front = rear = node;
    return *this;
}

template <typename T>
LinkedQueue<T> & LinkedQueue<T>::pop(T & r) {
    if (!front)
        throw OutOfBounds();
    Node<T> * node = front->link;
    r = front->data;
    delete front;
    if (node)
        front = node;
    else
        rear = front = 0;
    return *this;
}


#endif /* LinkedQueue_hpp */
