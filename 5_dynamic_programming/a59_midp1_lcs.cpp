// DONE
// Longest Common Subsequence (text)

#include <bits/stdc++.h>
using namespace std;

int lengthA, lengthB;
string A, B;
vector<vector<int>> table;
vector<char> ans;

void print() {
    cout << "TEST\n";
    for (const auto &x: table) {
        for (const auto &y: x) cout << y << " ";
        cout << "\n";
    }
}

int main() {
    cin >> lengthA >> lengthB >> A >> B;

    table.resize(lengthA+1);
    for (int i=0; i<=lengthA; i++) {
        table[i].resize(lengthB+1);
        for (int j=0; j<=lengthB; j++) cin >> table[i][j];
    }

    //print();

    int currRow = lengthA;
    for (int currCol = lengthB; currCol > 0; currCol--) {
        
        if (currRow < 1) break;
        if (table[currRow][currCol] == 0) break;

        cout << "Checking: " << currRow << " " << currCol << "\n";

        if (table[currRow-1][currCol-1] + 1 == table[currRow][currCol]) {
            cout << "FOUND " << B[currCol-1] << "\n";
            ans.push_back(B[currCol-1]);
            currRow--;
        }

    }

    for (int i=ans.size()-1; i>=0; i--) cout << ans[i];
}