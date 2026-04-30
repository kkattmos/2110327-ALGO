//
// Todd

#include <bits/stdc++.h>
using namespace std;

int noNodes, noEdges;
vector<pair<pair<int, int>, int>> edges;

void search(int start) {
    //cout << "Ignoring edge number " << edgeToRemove << "\n"; 
    vector<int> cost(noNodes, INT_MAX/2), prev(noNodes, -1);
    cost[start] = 0;

    for (int i=0; i<noNodes; i++) {
        for (int j=0; j<noEdges; j++) {
            //if (j == edgeToRemove) continue;
            if (cost[edges[j].first.second] > cost[edges[j].first.first] + edges[j].second) {
                cost[edges[j].first.second] = cost[edges[j].first.first] + edges[j].second;
                prev[edges[j].first.second] = edges[j].first.first;
            }
        }
    }

    for (int j=0; j<noEdges; j++) {
        //if (j == edgeToRemove) continue;
        if (cost[edges[j].first.second] > cost[edges[j].first.first] + edges[j].second) return;
        //cout << edges[j].first.first << " " << edges[j].first.second << " " << edges[j].second << "\n";
    }
    //cout << edgeToRemove << "\n";
    for (const auto &x: cost) cout << x << " ";
    
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> noNodes >> noEdges;

    for (int i=0; i<noEdges; i++) {
        int a, b, w; cin >> a >> b >> w;
        edges.push_back({{a, b}, w});
    }
    search(2);
    //for (int i=0; i<noEdges; i++) search(i);
}