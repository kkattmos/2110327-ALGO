// DONE
// Detecting Cycle

#include <bits/stdc++.h>
using namespace std;

int noGraph;
int noNodes, noEdges;
vector<vector<int>> relations;
vector<bool> visited;

void print() {
    cout << "Test: ";
    for (const auto &x: visited) cout << x << " ";
    cout << "\n";
}

void print2() {
    for (int i=0; i<noNodes; i++) {
        cout << "TEST2: " << i << " | ";
        for (const auto &x: relations[i]) cout << x << " ";
        cout << "\n";
    }
}

bool iscycle(int node, int parent) {
    visited[node] = true;
    //print();
    //cout << "Node: " << node << " Parent: " << parent << "\n";
    //for (const auto &x: relations[node]) {
    //    if (!visited[x]) return iscycle(x, node);
    //    else if (x != parent) return true;
    //}
    //return false;

    bool result = false;

    for (const auto &x: relations[node]) {
        if (!visited[x]) result = iscycle(x, node);
        else if (x != parent) return true;

        if (result) break;
    }
    return result;
}

int main() {
    cin >> noGraph;
    
    for (int _=0; _<noGraph; _++) {
        cin >> noNodes >> noEdges;

        relations.resize(noNodes);
        visited.assign(noNodes, false);
        
        for (int i=0; i<noEdges; i++) {
            int start, end;
            cin >> start >> end;
            relations[start].push_back(end);
            relations[end].push_back(start);
        }

        //print2();

        bool cycleIndicator = false;
        for (int i=0; i<noNodes; i++) {
            if (!visited[i]) {
                if (iscycle(i, -1)) cycleIndicator = true;
            }
            if (cycleIndicator) break;
        }

        if (cycleIndicator) cout << "YES\n";
        else cout << "NO\n";

        relations.clear();
        visited.clear();
    }
}