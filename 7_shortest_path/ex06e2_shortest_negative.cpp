// DONE
// Shortest Path with Negative Edge

#include <bits/stdc++.h>
using namespace std;

int noNodes, noEdges, startNode;
//vector<vector<pair<int, int>>> to;
vector<pair<pair<int, int>, int>> edges;
vector<int> dist, prevWeight;
bool negativeFlag = false;

int main() {
    cin >> noNodes >> noEdges >> startNode;

    //to.resize(noNodes);
    for (int _=0; _<noEdges; _++) {
        int start, end, weight; cin >> start >> end >> weight;
        edges.push_back({{start, end}, weight});
    }

    dist.assign(noNodes, 1e7);
    prevWeight.assign(noNodes, -1);
    
    dist[startNode] = 0;
    for (int i=1; i<noNodes; i++) {
        for (const auto &x: edges) {
            if (dist[x.first.second] > dist[x.first.first] + x.second) {
                dist[x.first.second] = dist[x.first.first] + x.second;
                prevWeight[x.first.second] = x.first.first;
            }
        }
    }

    for (const auto &x: edges) {
        negativeFlag = negativeFlag || (dist[x.first.second] > dist[x.first.first] + x.second);
    }

    if (negativeFlag) cout << "-1";
    else {
        for (const auto &x: dist) cout << x << " ";
    }
}