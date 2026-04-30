// DONE
// Border Extend

#include <bits/stdc++.h>
using namespace std;

using Integer = std::int8_t;

int noRows, noCols, distLimit;
vector<vector<int>> boardinfo;
vector<vector<bool>> visited;

const vector<pair<int, int>> DIRS = {
  {-1, 0},
  {1, 0},
  {0, -1},
  {0, 1}  
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> noRows >> noCols >> distLimit;

    boardinfo.assign(noRows, vector<int>(noCols, -1));
    visited.assign(noRows, vector<bool>(noCols, false));

    //BFS
    queue<pair<pair<int, int>, int>> toSearch;
    for (int i=0; i<noRows; i++) {
        for (int j=0; j<noCols; j++) {
            cin >> boardinfo[i][j];
            if (boardinfo[i][j] == 1) {
                visited[i][j] = true;
                toSearch.push({{i, j}, 0});
            }
        }
    }

    while (!toSearch.empty()) {
        auto [currPos, currDist] = toSearch.front();
        toSearch.pop();

        if (currDist >= distLimit) continue;

        for (const auto &d : DIRS) {
            int newRow = currPos.first + d.first;
            int newCol = currPos.second + d.second;

            if (newRow < 0 || newRow >= noRows) continue;
            if (newCol < 0 || newCol >= noCols) continue;
            if (visited[newRow][newCol]) continue;
            visited[newRow][newCol] = true;
            boardinfo[newRow][newCol] = 2;
            toSearch.push({{newRow, newCol}, currDist+1});
        }
    }

    for (const auto &x: boardinfo) {
        for (const auto &y: x) cout << y << " ";
        cout << "\n";
    }
}