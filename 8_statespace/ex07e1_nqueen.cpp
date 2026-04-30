//
// N-queen (permutation-based)

#include <bits/stdc++.h>
using namespace std;

int boardSize;
vector<int> col;
vector<bool> used;

int counter = 0;

void print() {
    counter++;
    for (const auto &x: col) cout << x << " ";
    cout << "\n";
}

bool check(int curr) {
    //if (curr < 2) return true;

    // Check in only diagnoal
    for (int i=0; i<curr; i++) {
        if (i - col[i] == curr - col[curr]) return false;
        if (i + col[i] == curr + col[curr]) return false;
    }

    return true;
}

void genPatterns(int curr) {
    if (curr >= boardSize) {
        counter++;
        return;
    }

    for (int i=0; i<boardSize; i++) {
        if (!used[i]) {
            used[i] = true;
            col[curr] = i;
            if (check(curr)) genPatterns(curr+1);
            used[i] = false;
        }
    }
}

int main() {
    cin >> boardSize;
    
    col.assign(boardSize, -1);
    used.assign(boardSize, false);

    genPatterns(0);
    cout << counter;
}