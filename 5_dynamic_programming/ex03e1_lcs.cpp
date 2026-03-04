// DONE
// Longest Common Subsequence

#include <bits/stdc++.h>
using namespace std;

string A, B;
vector<vector<int>> table;

void print() {
    cout <<"TEST\n";
    for (const auto &x: table) {
        for (const auto &y: x) cout << y << " ";
        cout << "\n";
    }
    cout << "\n";
}

int main() {
    cin >> A >> B;

    int lengthA = A.length();
    int lengthB = B.length();

    table.resize(lengthA+1);
    for (int i=0; i<=lengthA; i++) table[i].resize(lengthB+1);

    for (int i=1; i<=lengthA; i++) {
        for (int j=1; j<=lengthB; j++) {
            //cout << "Comparing: " << A[i] << " " << B[j] << "\n";
            if (A[i-1] == B[j-1]) table[i][j] = table[i-1][j-1] + 1;
            else table[i][j] = max(table[i][j-1], table[i-1][j]);
        }
    }

   // print();
    cout << table[lengthA][lengthB];

}