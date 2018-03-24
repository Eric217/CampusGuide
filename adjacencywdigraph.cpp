#include "AdjacencyWDigraph.h"


Dist::Dist() {}
Dist::Dist(int d, int i): dist(d), idx(i) {}

Dist::operator int() const { return dist; }


int AdjacencyWDigraph::edges() const {
    return e;
}

int AdjacencyWDigraph::vertices() const {
    return n;
}

AdjacencyWDigraph::~AdjacencyWDigraph() {
    if (arr != 0)
        delete2DArray(arr, n+1);
}

void AdjacencyWDigraph::initializePos() {
    pos = new int[n+1];
}

void AdjacencyWDigraph::deactivatePos() {
    delete[] pos; pos = 0;
}

void AdjacencyWDigraph::Delete() {
    delete2DArray(arr, n+1);
    arr = 0;
}



///需要一个数组标记顶点i是否在路径中，dist标记路径外的点通过以生成的路径到起始点的最短距离。pre标记顶点i的前一个点。
///距离最小的顶点加入到路径中，然后更新路径外的顶点通过路径到起始点的最短距离和路径外的顶点通过路径的前一个顶点，直到所有顶点加入到路径中

void AdjacencyWDigraph::shortestPaths(int start, int * dist, int * pre) {
    if (start > n || start < 1)
        throw OutOfBounds();
    MinHeap<Dist> heap(n);
    for (int i = 1; i <= n; i++) {

        int test = arr[start][i];

         dist[i] = test;
        dist[i] = arr[start][i];
        if (dist[i] != NoEdge) {
            pre[i] = start;
            heap.push(Dist(dist[i], i));
        } else
            pre[i] = 0;
    }

    while (!heap.empty()) {
        Dist distan;
        heap.pop(distan);
        int i = distan.idx;
        for (int j = 1; j <= n; j++) {

            int incomingDist = dist[i] + arr[i][j];
            if (j != start && arr[i][j] != NoEdge && (!pre[j] || dist[j] > incomingDist)) {
                dist[j] = incomingDist;
                if (!pre[j])
                    heap.push(Dist(dist[j], j));
                pre[j] = i;
            }
        }
    }
}




int AdjacencyWDigraph::beginIterator(int i) {
    if (i < 1 || i > n)
        throw OutOfBounds();
    for (int j = 1; j <= n; j++) {
        if (arr[i][j] != NoEdge) {
            pos[i] = j;
            return j;
        }
    }
    pos[i] = n+1;
    return 0;
}


int AdjacencyWDigraph::nextIterator(int i) {
    if (i < 1 || i > n)
        throw OutOfBounds();
    for (int j = pos[i] + 1; j <= n; j++) {
        if (arr[i][j] != NoEdge) {
            pos[i] = j;
            return j;
        }
    }
    pos[i] = n+1;
    return 0;
}




AdjacencyWDigraph::AdjacencyWDigraph(int v): n(v), e(0) {
    make2DArray(arr, n+1, n+1);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            arr[i][j] = NoEdge;
}


bool AdjacencyWDigraph::exist(int i, int j) const {
    if (i < 1 || j < 1 || i > n || j > n || arr[i][j] == NoEdge)
        return 0;
    return 1;
}


int AdjacencyWDigraph::inDegree(int i) const {
    if (i < 1 || i > n)
        throw OutOfBounds();
    int sum = 0;
    for (int j = 1; j <= n; j++)
        if (arr[j][i] != NoEdge)
            sum++;
    return sum;
}

int AdjacencyWDigraph::outDegree(int i) const {
    if (i < 1 || i > n)
        throw OutOfBounds();
    int sum = 0;
    for (int j = 1; j <= n; j++)
        if (arr[i][j] != NoEdge)
            sum ++;
    return sum;
}

AdjacencyWDigraph & AdjacencyWDigraph::addEdge(int i, int j, const int & w) {
    if (i < 1 || j < 1 || i > n || j > n || i == j)
        throw OutOfBounds();
    if (arr[i][j] == NoEdge)
        e++;
    arr[i][j] = w;
    return *this;
}

AdjacencyWDigraph & AdjacencyWDigraph::deleteEdge(int i, int j) {
    if (i < 1 || j < 1 || i > n || j > n || arr[i][j] == NoEdge || i == j)
        throw OutOfBounds();
    arr[i][j] = NoEdge;
    e--;
    return *this;
}
