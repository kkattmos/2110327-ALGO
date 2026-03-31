// PPPPPPPPPTTTTPTPTPTP
// Longest path in DAG (recursive)

#include <bits/stdc++.h>
using namespace std;

int noNodes, noEdges;
vector<vector<pair<int, int>>> destination;
vector<bool> isBegin, visited;

int maxWeight = 0;

void dfs(int currNode, int currWeight) {
    if (destination[currNode].empty()) {
        maxWeight = max(maxWeight, currWeight);
        return;
    }

    for (const auto &x: destination[currNode]) dfs(x.first, currWeight + x.second);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> noNodes >> noEdges;

    isBegin.assign(noNodes+1, true);
    visited.assign(noNodes+1, false);
    destination.resize(noNodes+1);

    for (int _=0; _<noEdges; _++) {
        int start, end, weight; cin >> start >> end >> weight;
        destination[start].push_back(make_pair(end, weight));
        isBegin[end] = false;
    }

    for (int i=1; i<=noNodes; i++) {
        if (isBegin[i]) dfs(i, 0);
    }

    cout << maxWeight;
}