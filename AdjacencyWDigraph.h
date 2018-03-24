//
//  AdjacencyWDigraph.hpp
//  10.1_图
//
//  Created by Eric on 19/03/2018.
//  Copyright © 2018 Eric. All rights reserved.
//

#ifndef AdjacencyWDigraph_hpp
#define AdjacencyWDigraph_hpp

#include "Common.h"
#include "Network.h"
#include "MinHeap.hpp"


class Dist {
public:
    Dist();
    Dist(int d, int i);
    int dist;
    int idx;
    operator int() const;
};


class AdjacencyWDigraph : public virtual Network {

protected:
    ///当前位置的数组，pos[i]即i当前邻接点的位置
    int * pos;
    ///顶点数
    int n;
    ///边数
    int e;
    ///二维数组
    int ** arr;
    //NoEdge predefined
public:
    AdjacencyWDigraph(int Vertices = 10);
    ~AdjacencyWDigraph();
    
    bool exist(int i, int j) const;
    int edges() const;
    int vertices() const;
    int outDegree(int i) const;
    int inDegree(int i) const;
    void Delete();
    
    AdjacencyWDigraph & addEdge(int i, int j, const int & w);
    AdjacencyWDigraph & deleteEdge(int i, int j);

    ///dijkstra. 这里的T就是按int做的了
    void shortestPaths(int s, int * d, int * p);
    

    
    ///孤立一个点，回头再删掉这个点
    void isolate(int point);
    
    void initializePos() ;
    void deactivatePos() ;
    ///返回第一个与顶点i邻接的顶点
    int beginIterator(int i);
    int nextIterator(int i);
};

#endif /* AdjacencyWDigraph_hpp */
