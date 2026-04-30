//
// 15 Puzzle 

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> board(4, vector<int>(4, -1));
int startRow, startCol;

const vector<pair<int, int>> DIRS = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}
};

int ans = 0;

int manhattanDist(vector<vector<int>> b) {
    int dist = 0;

    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            int val = b[i][j];
            if (val == 0) continue;
            int distI = (val - 1) / 4;
            int distJ = (val - 1) % 4;
            dist += abs(i - distI) + abs(j - distJ);
        }
    }

    return dist;
}

int dfs(int row, int col, int currMove, int thershold, int prevRow, int prevCol) {

    int currScore = manhattanDist(board);
    int computedScore = currMove + currScore;
    if (computedScore > thershold) return computedScore;
    if (currScore == 0) { // already solved
        ans = currMove;
        return -1;
    }
    int minValue = INT_MAX/2;
    for (const auto &d: DIRS) {
        int newRow = row + d.first;
        int newCol = col + d.second;
        if (newRow < 0 || newRow > 3) continue;
        if (newCol < 0 || newCol > 3) continue;
        if (newRow == prevRow && newCol == prevCol) continue;

        swap(board[row][col], board[newRow][newCol]);
        int result = dfs(
            newRow, newCol, currMove+1, thershold, row, col
        );
        swap(board[row][col], board[newRow][newCol]);
        
        if (result == -1) return -1;
        minValue = min(minValue, result);
    }

    return minValue;

}

int main() {
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            cin >> board[i][j];
            if (board[i][j] == 0) {
                startRow = i;
                startCol = j;
            }
        }
    }

    int currThreshold = manhattanDist(board);
    while (true) {
        int result = dfs(
            startRow, startCol, 0, currThreshold, -1, -1
        );
        if (result == -1) break;
        currThreshold = result;

    }

    cout << ans;
}