//
//  AdjacencyWGraph.hpp
//  test1
//
//  Created by Eric on 2018/3/20.
//  Copyright © 2018 Eric. All rights reserved.
//

#ifndef AdjacencyWGraph_hpp
#define AdjacencyWGraph_hpp

#include "AdjacencyWDigraph.h"
#include "UndirectedNetwork.h"


class AdjacencyWGraph : public AdjacencyWDigraph, public UndirectedNetwork {
    
public:
    AdjacencyWGraph(int ver = 10): AdjacencyWDigraph(ver) {}
    
    AdjacencyWGraph & addEdge(int i, int j, const int & w);
    AdjacencyWGraph & deleteEdge(int i, int j);
    
    int degree(int i) const { return this->outDegree(i); }

    void output() const;
};


#endif /* AdjacencyWGraph_hpp */
