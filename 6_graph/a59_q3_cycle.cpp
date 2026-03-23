//
// วงวนในต้นไม้

#include <bits/stdc++.h>
using namespace std;

int noNodes;
vector<bool> visited;
vector<vector<int>> relations;

int maxCC = 1;

void print() {
    cout << "Test: ";
    for (const auto &x: visited) cout << x << " ";
    cout << "\n";
}

void cycleCounter (int node, int from, int currCC) {
    visited[node] = true;
    //cout << "Node: " << node << " Parent: " << from << " currCC: " << currCC << "\n";
    
    int result = currCC;
    for (const auto &x: relations[node]) {
        if (!visited[x]) cycleCounter(x, node, currCC+1);
        else if (x != from) {
            maxCC = max(maxCC, currCC);
            return;
        }
    }
}

int main() {
    cin >> noNodes;

    visited.assign(noNodes, false);
    relations.resize(noNodes);

    for (int _=0; _<noNodes; _++) {
        int start, end;
        cin >> start >> end;
        relations[start].push_back(end);
        relations[end].push_back(start);
    }

    for (int i=0; i<noNodes; i++) {
        if (!visited[i]) {
            cycleCounter(i, -1, 1);
            //cout << "TEst: " << maxCC << "\n";
        }
    }
    cout << maxCC;


}