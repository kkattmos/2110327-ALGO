// DONE
// Longest Path in DAG

#include <bits/stdc++.h>
using namespace std;

int noNodes, noEdges;
vector<int> inDegree, memo;
vector<vector<pair<int, int>>> adj;

int globalMax = 0;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> noNodes >> noEdges;

    inDegree.assign(noNodes+1, 0);
    memo.assign(noNodes+1, 0);
    adj.resize(noNodes+1);

    for (int _=0; _<noEdges; _++) {
        int a, b, w; cin >> a >> b >> w;
        inDegree[b]++;
        adj[a].push_back({b, w});
    }

    queue<pair<int, int>> toSearch;
    for (int i=1; i<=noNodes; i++) {
        if (!inDegree[i]) toSearch.push({i, 0});
    }

    while (!toSearch.empty()) {
        auto [currNode, currWeight] = toSearch.front();
        toSearch.pop();

        for (const auto &[nextNode, nextWeight]: adj[currNode]) {
            memo[nextNode] = max(memo[nextNode], memo[currNode] + nextWeight);
            globalMax = max(globalMax, memo[nextNode]);
            if (!--inDegree[nextNode]) toSearch.push({nextNode, memo[nextNode]});
        }
    }
    cout << globalMax;
}