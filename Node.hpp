//
//  Node.hpp
//  9.3
//
//  Created by Eric on 10/02/2018.
//  Copyright © 2018 Eric. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

#include "Common.h"
 
template <typename T>
class Node {
public:
    T data;
    Node<T> * link;
};
#endif /* Node_hpp */
