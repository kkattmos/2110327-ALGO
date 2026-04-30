// DONE - but needs review
// Cable Company

#include <bits/stdc++.h>
using namespace std;

int noCenters;
vector<vector<int>> weight;

int totalCost = 0;
vector<int> minCost;
vector<bool> visited;

void print() {
    cout << "mincost: ";
    for (const auto &x: minCost) cout << x << " ";
    cout << "\nvisited: ";
    for (const auto &x: visited) cout << (x?"T":"F") << " ";
    cout << "\ntotalCost: " << totalCost;
    cout << "\n=====\n";
}

int main() {
    cin >> noCenters;

    weight.resize(noCenters);
    for (int i=0; i<noCenters; i++) weight[i].assign(noCenters, 0);

    for (int start=0; start<noCenters-1; start++) {
        for (int end=start+1; end<noCenters; end++) {
            //cout << "Test: " << start << " " << end << '\n';
            int w; cin >> w;
            weight[start][end] = w;
            weight[end][start] = w;
        }
    }

    minCost.assign(noCenters, 1e7);
    visited.assign(noCenters, false);
    minCost[1] = 0;

    for (int i=0; i<noCenters; i++) {
        int u = -1;
        for (int j=0; j<noCenters; j++) {
            if (!visited[j] && (u == -1 || minCost[j] < minCost[u])) u = j;
        }

        visited[u] = true;
        totalCost += minCost[u];

        for (int j=0; j<noCenters; j++) {
            if (!visited[j]) minCost[j] = min(minCost[j], weight[u][j]);
        }

        print();
    }

    cout << totalCost;
}