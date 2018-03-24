#include "Network.h"


int Network::beginIterator(int i) { return i; };

int Network::nextIterator(int i) { return i; };
int Network::vertices() const { return 0; };
void Network::initializePos() {};
void Network::deactivatePos() {};

void Network::findAllPathDFS(int v, int end, LinkedStack<int> & s, QList<QList<QPoint>> & list) {
    s.push(v);
    int u = beginIterator(v);
    while (u) {
        if (!s.contains(u)) {
            if (u == end) {
                QList<QPoint> l;
                l.append(QPoint(u, s.top->data));
                if (s.top->link) {
                    Node<int> * temp = s.top;
                    Node<int> * tempL = temp->link;
                    while (tempL) {
                        l.append(QPoint(temp->data, tempL->data));
                        temp = tempL;
                        tempL = tempL->link;
                    }
                }
                list.append(l);
            } else {
                findAllPathDFS(u, end, s, list);
                s.pop();
            }
        }
        u = nextIterator(v);
    }
}

void Network::findAllPath(int start, int end, QList<QList<QPoint>> & list) {
    initializePos();
    LinkedStack<int> s;
    findAllPathDFS(start, end, s, list);
    deactivatePos();
}

bool Network::findPathDFS(int v, int end, int & l, int * path, int *reach) {
    reach[v] = 1;
    int u = beginIterator(v);
    while (u) {
        if (!reach[u]) {
            path[++l] = u;
            if (u == end)
                return 1;
            if (findPathDFS(u, end, l, path, reach))
                return 1;
            //到这，u->end没戏，退一步，l--
            l--;
        }
        u = nextIterator(v);
    }
    return 0;
}

bool Network::findPath(int start, int end, int & l, int * path) {
    if (start == end) {
        l = 0;
        return 1;
    }
    int n = vertices();
    initializePos();
    int * reach = new int[n+1];
    for (int i = 1; i <= n; i++)
        reach[i] = 0;
    bool x = findPathDFS(start, end, l, path, reach);
    deactivatePos();
    delete [] reach;
    return x;
}

void Network::breadthFSearch(int v, int * reach, int label) {

    LinkedQueue<int> queue;
    initializePos();
    reach[v] = label;
    queue.push(v);
    while (!queue.isEmpty()) {
        int w, u;
        queue.pop(w);
        u = beginIterator(w);
        while (u) {
            if (!reach[u]) {
                queue.push(u);
                reach[u] = label;
            }
            u = nextIterator(w);
        }
//        代替while, 不需要iterator
//        for (int i = 1; i <= n; i++)
//            if (a[w][i] != NoEdge&&reach[i] != label) {
//                reach[i] = label;
//                q.push(i);
//            }
//

    }
    deactivatePos();

}

void Network::depthFSearch(int v, int * reach, int label) {
    if (v < 1 || v > vertices())
        throw OutOfBounds();
    initializePos();
    depthSearch(v, reach, label);
    deactivatePos();
}

void Network::depthSearch(int v, int * reach, int label) {
    reach[v] = label;
    int u = beginIterator(v);
    while (u) {
        if (!reach[u])
            depthSearch(u, reach, label);
        u = nextIterator(v);
    }
}

