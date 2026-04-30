//
// EV Truck

#include <bits/stdc++.h>
using namespace std;

int noCities, noRoads;
vector<vector<pair<int, int>>> road;

int minCost = 0;

int main() {
    cin >> noCities >> noRoads;
    road.resize(noCities);

    for (int _=0; _<noRoads; _++) {
        int start, end, weight; cin >> start >> end >> weight;
        road[start].push_back({end, weight});
        road[end].push_back({start, weight});
    }

    //Prim's
    vector<int> cost(noCities, INT_MAX/2), prevNode(noCities, -1);
    vector<bool> taken(noCities, false);
    cost[0] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> toSearch;
    toSearch.push({0, 0});

    while (!toSearch.empty()) {
        auto [currCost, currNode] = toSearch.top();
        toSearch.pop();

        if (taken[currNode]) continue;
        taken[currNode] = true;

        minCost = max(minCost, currCost);


        for (const auto &[destNode, destWeight]: road[currNode]) {
            if (taken[destNode]) continue;
            if (cost[destNode] > destWeight) {
                cost[destNode] = destWeight;
                prevNode[destNode] = currNode;
                toSearch.push({cost[destNode], destNode});
            }
        }
    }

    for (const auto &x: cost) cout << x << " ";
}