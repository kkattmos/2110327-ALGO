// DONE
// Sea bridge

#include <bits/stdc++.h>
using namespace std;

int noRows, noCols;
vector<vector<int>> mapData;
vector<vector<bool>> visited;

const vector<pair<int, int>> DIRS = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}
};

int bestSoFar = INT_MAX / 2;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> noRows >> noCols;

    //BFS
    queue<tuple<int, int, int>> toSearch;

    mapData.assign(noRows, vector<int>(noCols, -1));
    visited.assign(noRows, vector<bool>(noCols, false));
    for (int i=0; i<noRows; i++) {
        for (int j=0; j<noCols; j++) {
            cin >> mapData[i][j];
            if (mapData[i][j] == 1) toSearch.push({1, i, j});
        }
    }

    while (!toSearch.empty()) {
        auto [currDist, currRow, currCol] = toSearch.front();
        toSearch.pop();

        if (currDist >= bestSoFar) continue;

        for (const auto &d: DIRS) {
            int newRow = currRow + d.first;
            int newCol = currCol + d.second;

            if (newRow < 0 || newRow >= noRows) continue;
            if (newCol < 0 || newCol >= noCols) continue;
            if (mapData[newRow][newCol] == 1 || mapData[newRow][newCol] == 3) continue; 
            if (mapData[newRow][newCol] == 2) {
                bestSoFar = min(bestSoFar, currDist+1);
                continue;
            }
            if (visited[newRow][newCol]) continue;
            visited[newRow][newCol] = true;
            toSearch.push({currDist+1, newRow, newCol});
        }
    }
    cout << bestSoFar;
}