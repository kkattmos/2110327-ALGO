// 
// Shortest Path in Grid (Redo)

#include <bits/stdc++.h>
using namespace std;

int noRows, noCols;
vector<string> maze;
vector<vector<bool>> visited;

const vector<pair<int, int>> DIRS = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}
};

int bestMoves = 1e7;

int main() {
    cin >> noRows >> noCols;
    
    maze.resize(noRows);
    for (int i=0; i<noRows; i++) cin >> maze[i];

    visited.resize(noRows);
    for (int i=0; i<noRows; i++) visited[i].assign(noCols, false);

    //BFS
    queue<pair<pair<int, int>, int>> toSearch;
    toSearch.push({{0, 0}, 0});

    while (!toSearch.empty()) {
        int currMoves = toSearch.front().second;
        pair<int, int> currCoor = toSearch.front().first;
        toSearch.pop();

        if (currCoor == make_pair(noRows-1, noCols-1)) {
            bestMoves = min(bestMoves, currMoves);
            continue;
        }

        for (const auto &d: DIRS) {
            int newRow = currCoor.first + d.first;
            int newCol = currCoor.second + d.second;

            if (newRow < 0 || newRow >= noRows) continue;
            if (newCol < 0 || newCol >= noCols) continue;
            if (maze[newRow][newCol] == '#') continue;
            if (visited[newRow][newCol]) continue;

            toSearch.push({{newRow, newCol}, currMoves+1});
            visited[newRow][newCol] = true;
        }
    }

    if (bestMoves == 1e7) cout << "-1";
    else cout << bestMoves;
}