// 20.0
// Graph Coloring

#include <bits/stdc++.h>
using namespace std;

int noNodes, noEdges;

vector<vector<int>> adjacent;
vector<int> colorState;

int colorUsed = 1;

bool check(int node, int color) {
    for (const auto &n: adjacent[node]) {
        if (colorState[n] == color) return false;
    }
    return true;
}

bool trycolor(int nodeColored, int target) {
    if (nodeColored == noNodes) return true;

    for (int i=0; i<target; i++) {
        if (check(nodeColored, i)) {
            colorState[nodeColored] = i;
            if (trycolor(nodeColored+1, target)) return true;
            colorState[nodeColored] = -1;
        }
    }
    return false;
}

int main() {
    cin >> noNodes >> noEdges;
     
    adjacent.resize(noNodes);
    for (int i=0; i<noEdges; i++) {
        int a, b; cin >> a >> b;
        adjacent[a].push_back(b);
        adjacent[b].push_back(a);
    }

    for (int i=1; i<=noNodes; i++) {
        colorState.assign(noNodes, -1);
        if (trycolor(0, i)) {
            cout << i;
            break;
        }
    }
}