#include "AdjacencyWGraph.h"
#include <qdebug.h>


AdjacencyWGraph & AdjacencyWGraph::addEdge(int i, int j, const int & w) {
    this->AdjacencyWDigraph::addEdge(i, j, w);
    this->arr[j][i] = w;
    return *this;
}

AdjacencyWGraph & AdjacencyWGraph::deleteEdge(int i, int j) {
    this->AdjacencyWDigraph::deleteEdge(i, j);
    this->arr[j][i] = NoEdge;
    return *this;
}

void AdjacencyWGraph::output() const {
    for (int i = 1; i <= SITES; i++) {
        for (int j = 1; j <= SITES; j++) {
            int k = arr[i][j];
            k++;
            qDebug() << k;
        }
    }
}
