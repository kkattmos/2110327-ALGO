// DONE
// Detecting a cycle

#include <bits/stdc++.h>
using namespace std;

int noQueries;

int noNodes, noEdges;
vector<vector<bool>> connected;
vector<bool> visited;

int main() {
    cin >> noQueries;

    for (int _=0; _<noQueries; _++) {
        cin >> noNodes >> noEdges;

        bool flagged = false;
        visited.assign(noNodes, false);
        connected.resize(noNodes);
        for (int i=0; i<noNodes; i++) connected[i].assign(noNodes, false);
        
        for (int i=0; i<noEdges; i++) {
            int start, end; cin >> start >> end;

            connected[start][end] = true;
            connected[end][start] = true;
        }

        stack<pair<int, int>> toSearch;
        for (int i=0; i<noNodes; i++) toSearch.push({i, -1});

        while (!toSearch.empty() && !flagged) {
            int currNode = toSearch.top().first;
            int prevNode = toSearch.top().second;
            toSearch.pop();
            
            if (visited[currNode]) continue;
            visited[currNode] = true;
            
            for (int i=0; i<noNodes; i++) {
                if (connected[currNode][i]) {
                    if (visited[i] && i != prevNode) {
                        flagged = true;
                        break;
                    }
                    if (!visited[i]) toSearch.push({i, currNode});
                }
            }

        }

        if (flagged) cout << "YES\n";
        else cout << "NO\n";
    }
}