//
// Guitar’s Array 3

#include <bits/stdc++.h>
using namespace std;

int noRows, noCols;
vector<string> board;
vector<vector<bool>> isReached, isInitital;

const vector<pair<int, int>> DIAG = {
    {-1, -1},
    {-1, 1},
    {1, -1},
    {1, 1}
};
const vector<pair<int, int>> CIRC = {
    {2, 1},
    {1, 2}
};
const vector<pair<int, int>> CIRC_MULT = {
    {-1, -1},
    {-1, 1},
    {1, -1},
    {1, 1}
};

int currReached = 0;

bool update(int row, int col) {
    if (row < 0 || row >= noRows) return false;
    if (col < 0 || col >= noCols) return false;
    isReached[row][col] = true;
    currReached++;
    return true;
}

void place(int row, int col) { // Not a recursive fn!!
    if (isReached[row][col]) return;
    update(row, col);
    board[row][col] = 'X';

    for (int i=0; i<noRows; i++) update(i, col);
    for (int i=0; i<noCols; i++) update(row, i);

    for (const auto &d: DIAG) {
        int nr = row + d.first;
        int nc = col + d.second;

        while (true) {
            if (!update(nr, nc)) break;
            nr += d.first;
            nc += d.second;
        }
    }
    //cout << "pass\n";
    for (const auto &d: CIRC) {
        for (const auto &m: CIRC_MULT) update(
            row + (d.first * m.first),
            col + (d.second * m.second)
        );
    }
}

void reset() {
    for (int i=0; i<noRows; i++) {
        for (int j=0; j<noCols; j++) {
            if (board[i][j] != '#') {
                currReached--;
                board[i][j] = '.';
                isReached[i][j] = false;
            }
        }
    }
}

bool tryplace() {
    for (int i=0; i<noRows; i++) {
        for (int j=0; j<noCols; j++) {
            if (isInitital[i][j]) place(i, j);
        }
    }
    if (currReached == (noCols * noRows)-1) return true;
    reset();
    return false;
}

bool checkPlaceCombination(int searchDepth, int currPlaced) {
    if (currPlaced == searchDepth) {
        if (tryplace()) return true;
    }
    if (currPlaced >= searchDepth) return false;

    for (int i=0; i<noRows; i++) {
        for (int j=0; j<noCols; j++) {
            if (!isInitital[i][j]) {
                isInitital[i][j] = true;
                if (checkPlaceCombination(searchDepth, currPlaced+1)) return true;
                isInitital[i][j] = false;
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> noRows >> noCols;

    isReached.assign(noRows, vector<bool>(noCols, false));
    isInitital.assign(noRows, vector<bool>(noCols, false));
    board.resize(noRows);
    for (int i=0; i<noRows; i++) {
        cin >> board[i];
        for (int j=0; j<noCols; j++) {
            if (board[i][j] == '#') {
                isReached[i][j] = true;
                currReached++;
            }
        }
    }

    for (int i=1; i<=noRows*noCols; i++) {
        if (checkPlaceCombination(i, 0)) break;
        //cout << "passed " << i << "\n";
    }

    for (int i=0; i<noRows; i++) {
        for (int j=0; j<noCols; j++) cout << board[i][j];
        cout << "\n";
    }
}