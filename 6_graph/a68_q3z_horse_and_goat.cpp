// [[PPPP][PPP][PPP][---][---][----]]
// ม้ากับแพะ (ตัวน้อย)

#include <bits/stdc++.h>
using namespace std;

int noRows, noCols;
vector<vector<char>> matrix;
vector<vector<bool>> visited;
pair<int, int> startLoc, endLoc;

const vector<pair<int, int>> DIRS = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}
};

int minDist = 1e7;

int main() {
    cin >> noRows >> noCols;

    matrix.resize(noRows);
    visited.resize(noRows);
    for (int i=0; i<noRows; i++) {
        matrix[i].resize(noCols);
        visited[i].assign(noCols, false);
        for (int j=0; j<noCols; j++) {
            cin >> matrix[i][j];
            if (matrix[i][j] == 'S') startLoc = {i, j};
            else if (matrix[i][j] == 'T') endLoc = {i, j};
        }
    }

    queue<pair<pair<int, int>, int>> toSearch;
    toSearch.push(make_pair(startLoc, 0));

    while (!toSearch.empty()) {
        pair<int, int> corr = toSearch.front().first;
        int currDist = toSearch.front().second;
        toSearch.pop();

        if (endLoc == corr) {
            minDist = min(minDist, currDist);
            continue;
        }


        for (const auto &x: DIRS) {
            int newRow = corr.first + x.first;
            int newCol = corr.second + x.second;
            
            if (newRow < 0 || newRow >= noRows) continue;
            if (newCol < 0 || newCol >= noCols) continue;
            if (visited[newRow][newCol]) continue;
            if (matrix[newRow][newCol] == 'X') continue;


            if (matrix[newRow][newCol] == '#') {
                visited[newRow][endLoc.second] = true;
                visited[endLoc.first][newCol] = true;
                toSearch.push(make_pair(make_pair(newRow, endLoc.second), currDist+1));
                toSearch.push(make_pair(make_pair(endLoc.first, newCol), currDist+1));
            }
            else {
                visited[newRow][newCol] = true;
                toSearch.push(make_pair(make_pair(newRow, newCol), currDist+1));
            }

        }
    }

    cout << minDist;
}