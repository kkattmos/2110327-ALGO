// DONE
// Border Extend

#include <bits/stdc++.h>
using namespace std;

int noRows, noCols, targetDist;
vector<vector<int>> matrix;

const vector<pair<int,int>> DIRS = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> noRows >> noCols >> targetDist;

    //queue<pair<int, int>> toSpread;
    queue<pair<pair<int, int>, int>> toSpread;

    matrix.resize(noRows);
    for (int i=0; i<noRows; i++) {
        matrix[i].resize(noCols);
        for (int j=0; j<noCols; j++) {
            cin >> matrix[i][j];
            if (matrix[i][j] == 1) toSpread.push(make_pair(make_pair(i, j), 0));
        }
    }

    while (!toSpread.empty()) {
        int currRow = toSpread.front().first.first;
        int currCol = toSpread.front().first.second;
        int currDist = toSpread.front().second;
        toSpread.pop();

        if (currDist >= targetDist) continue;

        for (const auto &x: DIRS) {
            if (currRow + x.first < 0 || currRow + x.first >= noRows) continue;
            if (currCol + x.second < 0 || currCol + x.second >= noCols) continue;
            
            if (matrix[currRow + x.first][currCol + x.second] == 0) {
                matrix[currRow + x.first][currCol + x.second] = 2;
                toSpread.push(make_pair(make_pair(currRow + x.first, currCol + x.second), currDist+1));
            }
        }
    }

    for (int i=0; i<noRows; i++) {
        for (int j=0; j<noCols; j++) cout << matrix[i][j] << " ";
        cout << "\n";
    }

}