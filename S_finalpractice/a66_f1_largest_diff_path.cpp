// DONE
// Largest Diff Path

#include <bits/stdc++.h>
using namespace std;

int noNodes, noEdges;
vector<vector<int>> adj;
vector<int> weight, indeg, minVal;

int ans = 0;

void solve() {
    queue<int> toSearch;
    for (int i=0; i<noNodes; i++) {
        if (!indeg[i]) toSearch.push(i);
    }

    while (!toSearch.empty())
    {
        int currPos = toSearch.front();
        toSearch.pop();

        ans = max(ans, weight[currPos] - minVal[currPos]);

        for (const auto &nextPos: adj[currPos]) {
            minVal[nextPos] = min(minVal[currPos], minVal[nextPos]);
            if (!--indeg[nextPos]) toSearch.push(nextPos); 
        } 
    }
    
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> noNodes >> noEdges;

    weight.resize(noNodes);
    minVal.resize(noNodes);

    for (int i=0; i<noNodes; i++) {
        cin >> weight[i];
        minVal[i] = weight[i];
    }

    adj.resize(noNodes);
    indeg.assign(noNodes, 0);
    for (int i=0; i<noEdges; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        indeg[b]++;
    }

    solve();
    cout << ans;
}