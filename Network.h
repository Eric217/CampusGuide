//
//  Network.h
//  test1
//
//  Created by Eric on 2018/3/20.
//  Copyright © 2018 Eric. All rights reserved.
//

#ifndef Network_h
#define Network_h

#include "LinkedQueue.hpp"


class Network {
    void depthSearch(int, int *, int label);
    bool findPathDFS(int, int, int &, int *, int *);
    
public:
    virtual int beginIterator(int i);
    virtual int nextIterator(int i);
    virtual int vertices() const;
    virtual void initializePos();
    virtual void deactivatePos();

    ///从点V开始，总点数n
    void breadthFSearch(int v, int * reach, int label);
    void depthFSearch(int v, int * reach, int label);
    ///寻找一条路径, 写入路径长度、路径path，返回是否找到
    bool findPath(int start, int end, int & length, int * path);
    
};

#endif /* Network_h */
