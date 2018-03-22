//
//  UndirectedNetwork.hpp
//  10.1_图
//
//  Created by Eric on 21/03/2018.
//  Copyright © 2018 Eric. All rights reserved.
//

#ifndef UndirectedNetwork_hpp
#define UndirectedNetwork_hpp

#include "Network.h"

class UndirectedNetwork : virtual public Network {
public:
    bool connected();
    int labelComponents(int * label);
};

#endif /* UndirectedNetwork_hpp */
