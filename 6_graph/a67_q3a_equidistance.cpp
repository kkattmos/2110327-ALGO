//
// Equidistance

#include <bits/stdc++.h>
using namespace std;

int noRows, noCols, remainingCells;
vector<vector<int>> matrix, todd, visited;

const vector<pair<int, int>> DIRS = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}
};

int main() {
    cin >> noRows >> noCols;
    remainingCells = noRows * noCols;

    vector<pair<int, int>> startCells;

    matrix.resize(noRows);
    todd.resize(noRows);
    visited.resize(noRows);
    for (int i=0; i<noRows; i++) {
        matrix[i].resize(noCols);
        todd[i].assign(noCols, 0);
        visited[i].assign(noCols, 0);
        for (int j=0; j<noCols; j++) {
            cin >> matrix[i][j];
            if (matrix[i][j] == 1) remainingCells--;
            else if (matrix[i][j] == 2) startCells.push_back({i, j});
        }
    }

    bool hasPenality = false;
    for (const auto &x: startCells) {
        queue<pair<pair<int, int>, int>> toSearch;
        toSearch.push({{x.first, x.second}, 0});

        while (!toSearch.empty()) {
            pair<int, int> coor = toSearch.front().first;
            int currDist = toSearch.front().second;
            toSearch.pop();

            if (todd[coor.first][coor.second] != -1 && currDist != todd[coor.first][coor.second]){
                if (hasPenality) {
                    remainingCells--;
                    todd[coor.first][coor.second] = -1;
                }
            }

            for (const auto &x: DIRS) {
                int newRow = coor.first + x.first;
                int newCol = coor.second + x.second;

                if (newRow < 0 || newRow >= noRows) continue;
                if (newCol < 0 || newCol >= noCols) continue;
                if (visited[newRow][newCol]) continue;

                visited[newRow][newCol] = 1;
                toSearch.push({{newRow, newCol}, currDist+1});
            }
        }
        
        
        hasPenality = true;
        for (int i=0; i<noCols; i++) visited[i].assign(noCols, 0);
    }

    cout << remainingCells;
}