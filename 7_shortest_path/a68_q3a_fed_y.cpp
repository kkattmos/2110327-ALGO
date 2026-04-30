//
// FED-Y

#include <bits/stdc++.h>
using namespace std;

int noCities, noRoads;
vector<vector<pair<int, int>>> roads;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> noCities >> noRoads;

    roads.resize(noCities+1);
    for (int _=0; _<noRoads; _++) {
        int start, end, weight; cin >> start >> end >> weight;
        roads[start].push_back({end, weight});
        roads[end].push_back({start,weight});
    }
    
    //Dijkstra
    vector<int> cost(noCities+1, INT_MAX/2), prev(noCities+1, -1);
    cost[1] = 0;
    
    priority_queue<pair<int, int>> toSearch;
    toSearch.push({0, 1});
    while (!toSearch.empty()) {
        auto [currDist, currNode] = toSearch.top();
        toSearch.pop();

        for (const auto [dest, weight]: roads[currNode]) {
            if (cost[dest] > currDist + weight) {
                cost[dest] = currDist + weight;
                prev[dest] = currNode;
                toSearch.push({cost[dest], dest});
            }
        }
    }

    int maxTime = -1;
    for (int i=2; i<=noCities; i++) maxTime = max(maxTime, cost[i]);
    for (int i=2; i<= noCities; i++) cout << abs(maxTime - cost[i]) << "\n";
}