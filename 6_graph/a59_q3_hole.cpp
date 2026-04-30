// DONE
// Hole

#include <bits/stdc++.h>
using namespace std;

int noHoles, houseRow, houseCol;
vector<vector<bool>> isHole(1002, vector<bool>(1001, false))
, visited(1001, vector<bool>(1001, false));

const vector<pair<int, int>> DIRS = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}
};

int minCost = INT_MAX / 2;

int main() {
    cin >> noHoles >> houseRow >> houseCol;
    
    for (int i=0; i<noHoles; i++) {
        int row, col; cin >> row >> col;
        isHole[row][col] = true;
    }

    typedef pair<pair<int, int>, int> coor;
    queue<coor> toSearch;
    toSearch.push({{houseRow, houseCol}, 0});

    while (!toSearch.empty()) {
        pair<int, int> currPos = toSearch.front().first;
        int currCost = toSearch.front().second;
        toSearch.pop();

        if (visited[currPos.first][currPos.second]) continue;
        visited[currPos.first][currPos.second] = true;

        for (const auto &x: DIRS) {
            int newRow = currPos.first + x.first;
            int newCol = currPos.second + x.second;

            if (newRow < 0 || newRow > 1000 || newCol < 0 || newCol > 1000) {
                minCost = min(minCost, currCost);
                continue;
            }

            if (visited[newRow][newCol]) continue;
            if (isHole[newRow][newCol]) toSearch.push({{newRow, newCol}, currCost+1});
            else toSearch.push({{newRow, newCol}, currCost});
        }
    }

    cout << minCost;
}