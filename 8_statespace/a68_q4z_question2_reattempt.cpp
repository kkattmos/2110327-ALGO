//
// Guitar’s Array 3
#include <bits/stdc++.h>
using namespace std;

int noRows, noCols;
vector<string> board;
vector<vector<bool>> isReached;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> noRows >> noCols;

    isReached.assign(noRows, vector<bool>(noCols, false));
    board.resize(noRows);
    for (int i=0; i<noRows; i++) {
        cin >> board[i];
        for (int j=0; j<noCols; j++) {
            if (board[i][j] == '#') isReached[i][j] = true;
        }
    }
}