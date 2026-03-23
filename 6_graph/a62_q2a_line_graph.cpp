// DONE
// นับกราฟเส้นตรง

#include <bits/stdc++.h>
using namespace std;

int noNodes, noEdges;
vector<vector<int>> relations;
vector<bool> visited;

int lineCount = 0;

bool isLineGraph(int node, int parent, bool status) {
    visited[node] = true;
    bool result = (relations[node].size() > 2) ? false: status;

    for (const auto &x: relations[node]) {
        if (!visited[x]) result = isLineGraph(x, node, result);
        else if (x != parent) result = false; // Cyclic graph
    }

    return result;
}

int main() {
    cin >> noNodes >> noEdges;

    relations.resize(noNodes);
    visited.assign(noNodes, false);

    for (int i=0; i<noEdges; i++) {
        int start, end;
        cin >> start >> end;
        relations[start].push_back(end);
        relations[end].push_back(start);
    }

    for (int i=0; i<noNodes; i++) {
        if (!visited[i]) {
            if (isLineGraph(i, -1, true)) lineCount++;
        }
    }

    cout << lineCount;
}