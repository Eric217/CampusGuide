#include "UndirectedNetwork.h"


bool UndirectedNetwork::connected() {
    int n = this->vertices();
    int * reach = new int[n+1];
    for (int i = 1; i <= n; i++)
        reach[i] = 0;
    this->depthFSearch(1, reach, 1);
    for (int i = 1; i <= n; i++)
        if (!reach[i])
            return 0;
    return 1;
}

/// 返回构件的数目，  label[1:num]表示构件标号
int UndirectedNetwork::labelComponents(int * label) {
    int n = vertices();
    for (int i = 1; i <= n; i++)
        label[i] = 0;
    int l = 0;
    for (int i = 1; i <= n; i++) {
        if (!label[i]) {
            l++;
            this->breadthFSearch(i, label, l);
        }
    }
    return l;

}
