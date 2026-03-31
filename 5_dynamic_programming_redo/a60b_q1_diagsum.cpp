//
// Diagonal Sum

#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> matrix, memo;

void print() {
    for (const auto &x: memo) {
        for (const auto &y: x) cout << y << " ";
        cout << '\n';
    }
}

int main() {
    cin >> n;
    
    matrix.resize(n);
    for (int r=0; r<n; r++) {
        matrix[r].resize(n);
        for (int c=0; c<n; c++) cin >> matrix[r][c];
    }

    memo.resize(n);
    for (int r=0; r<n; r++) memo[r].resize(4);

    
    
}