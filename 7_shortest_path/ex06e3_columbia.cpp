// DONE (but needs review)
// Columbia

#include <bits/stdc++.h>
using namespace std;

int noRows, noCols;
vector<vector<int>> tolls, dist;
vector<vector<bool>> visited;

const vector<pair<int, int>> DIRS = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1},
};

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> noRows >> noCols;

    tolls.resize(noRows);
    for (int i=0; i<noRows; i++) {
        tolls[i].resize(noCols);
        for (int j=0; j<noCols; j++) cin >> tolls[i][j];
    }

    //Dijkstra's
    dist.assign(noRows, vector<int>(noCols, 1e7));
    visited.assign(noRows, vector<bool>(noCols, false));
    dist[0][0] = 0;

    typedef pair<int, pair<int, int>> Node;
    priority_queue<Node, vector<Node>, greater<Node>> toSearch;
    toSearch.push({0, {0, 0}});

    while (!toSearch.empty()) {
        int currCost = toSearch.top().first;
        pair<int, int> currPos = toSearch.top().second;
        toSearch.pop();

        if (currCost > dist[currPos.first][currPos.second]) continue;

        if (visited[currPos.first][currPos.second]) continue;
        visited[currPos.first][currPos.second] = true;

        for (const auto &x: DIRS) {
            int newRow = currPos.first + x.first;
            int newCol = currPos.second + x.second;

            if (newRow < 0 || newRow >= noRows) continue;
            if (newCol < 0 || newCol >= noCols) continue;
            if (visited[newRow][newCol]) continue;

            int newCost = dist[currPos.first][currPos.second] + tolls[newRow][newCol];
            if (newCost < dist[newRow][newCol]) {
                dist[newRow][newCol] = newCost;
                toSearch.push({newCost, {newRow, newCol}});
            }
        }
    }

    for (int i=0; i<noRows; i++) {
        for (int j=0; j<noCols; j++) cout << dist[i][j] << " ";
        cout << "\n";
    }
}