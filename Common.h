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

extern int SITES;

class NoMem {};
class OutOfBounds {};

inline bool existIn(int * arr, int l, int v) {
    for (int i = 0; i < l ; i++) {
        if (arr[i] == v)
            return 1;
    }
    return 0;
}

inline void make2DArray(int * * & arr, int row, int col) {
    arr = new int * [row];
    for (int i = 0; i < row; i ++ )
        arr[i] = new int[col];
}


inline void delete2DArray(int * * & arr, int row) {
    for (int i = 0; i < row; i ++)
        delete [] arr[i];
    delete [] arr;
    arr = 0;
}



#endif /* Common_h */
