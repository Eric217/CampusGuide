//
//  Common.h
//  10.1_图
//
//  Created by Eric on 19/03/2018.
//  Copyright © 2018 Eric. All rights reserved.
//

#ifndef Common_h
#define Common_h

#include <iostream>
using namespace std;

#define NoEdge 10000
#define Reached 1

class NoMem {};
class OutOfBounds {};

 
template <typename T>
void make2DArray(T * * & arr, int row, int col) {
    arr = new T * [row];
    for (int i = 0; i < row; i ++ )
        arr[i] = new T[col];
}

template <typename T>
void delete2DArray(T * * & arr, int row) {
    for (int i = 0; i < row; i ++)
        delete [] arr[i];
    delete [] arr;
    arr = 0;
}



#endif /* Common_h */
