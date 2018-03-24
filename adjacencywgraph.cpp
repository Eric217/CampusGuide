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

QList<QPoint> AdjacencyWGraph::minSpanTree(int * a, int length) {
    initializePos();
    QList<QPoint> result;

    int existedLength = 0;
    int * existedArr = new int[length];
    existedArr[existedLength++] = a[0];

    int connector;

    while (existedLength != length) {

        int minW = NoEdge, minP = 0;

        for (int k = 0; k < existedLength; k++) {

            int v = existedArr[k];
            int u = beginIterator(v);

            while (u) {

                if (existIn(a, length, u) && !existIn(existedArr, existedLength, u) && arr[u][v] < minW) {
                    minW = arr[u][v];
                    minP = u;
                    connector = v;
                }
                u = nextIterator(v);
            }

        }

        if (minP) {
            existedArr[existedLength++] = minP;
            result.append(QPoint(minP,connector));
        }

    }
    deactivatePos();
    delete[] existedArr;
    return result;

}
