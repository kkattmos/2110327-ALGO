// DONE
// EV Truck

#include <bits/stdc++.h>
using namespace std;

int noNodes, noEdges;
vector<vector<int>> cost;

int globalMax = -1;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> noNodes >> noEdges;

    //Floyd-Warshall
    cost.assign(noNodes, vector<int>(noNodes, INT_MAX/2));
    for (int i=0; i<noNodes; i++) cost[i][i] = 0;

    for (int i=0; i<noEdges; i++) {
        int a, b, w; cin >> a >> b >> w;
        cost[a][b] = cost[b][a] = w;
    }

    for (int k=0; k<noNodes; k++) {
        for (int i=0; i<noNodes; i++) {
            for (int j=0; j<noNodes; j++) {
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }

    for (int i=0; i<noNodes; i++) {
        for (int j=0; j<noNodes; j++) globalMax = max(globalMax, cost[i][j]);
    }

    cout << globalMax;
}