// DONE
// Shortest Start

#include <bits/stdc++.h>
using namespace std;

int noNodes, noEdges, noStarts, targetNode;
vector<int> startNodes, dist, prevNode;

typedef pair<pair<int, int>, int> edge;
vector<edge> edgeList;

int minCost = 1e7;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> noNodes >> noEdges >> noStarts >> targetNode;

    startNodes.assign(noStarts, 0);
    for (int i=0; i<noStarts; i++) cin >> startNodes[i];

    //Reverse start <-> end
    for (int _=0; _<noEdges; _++) {
        int start, end, weight; cin >> start >> end >> weight;
        edgeList.push_back({{end, start}, weight});
    }

    // Run Bellman-Ford once, with targetNode as the source
    dist.assign(noNodes, INT_MAX / 2);
    prevNode.assign(noNodes, -1);
    dist[targetNode] = 0;

    for (int i=1; i<noNodes-1; i++) { // Experimenting this
        for (const auto &x: edgeList) {
            if (dist[x.first.second] > dist[x.first.first] + x.second) {
                dist[x.first.second] = dist[x.first.first] + x.second;
                prevNode[x.first.second] = x.first.first;
            }
        }
    }

    for (const auto &startNode: startNodes) minCost = min(minCost, dist[startNode]);
    cout << minCost;
}