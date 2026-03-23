//
// Connected Component

#include <bits/stdc++.h>
using namespace std;

int noNodes, noEdges;
vector<vector<int>> relation;
vector<int> componentNo;
int cc = 0;

void print() {
    cout << "Test: ";
    for (const auto &x: componentNo) cout << x << " ";
    cout << "\n";
}

void dfs(int node) {
    componentNo[node] = cc;
    //print();
    for (const auto &x: relation[node]) {
        if (componentNo[x] == -1) dfs(x);
    }
}

int main() {
    cin >> noNodes >> noEdges;

    componentNo.assign(noNodes+1, -1); // -1 = Not visited
    relation.resize(noNodes+1);

    for (int i=0; i<noEdges; i++) {
        int start, end;
        cin >> start >> end;
        relation[start].push_back(end);
        relation[end].push_back(start);
    }

    for (int i=1; i<=noNodes; i++) {
        if (componentNo[i] == -1) {
            cc++;
            dfs(i);
        }
    }

    cout << cc;
}