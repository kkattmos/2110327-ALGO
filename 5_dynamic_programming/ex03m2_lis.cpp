// DONE
// Longest Increasing Subsequence

#include <bits/stdc++.h>
using namespace std;

int noItems;
vector<int> sequence, sortedSequence;
vector<vector<int>> table;

void print() {
    cout << "TEST";
    for (const auto &x: table) {
        for (const auto &y: x) cout << y << " ";
        cout << "\n";
    }
}

int main() {
    cin >> noItems;
    
    sequence.resize(noItems);
    sortedSequence.resize(noItems);
    for (int i=0; i<noItems; i++) {
        cin >> sequence[i];
        sortedSequence[i] = sequence[i];
    }

    sort(sortedSequence.begin(), sortedSequence.end());

    table.resize(noItems+1);
    for (int i=0; i<=noItems; i++) table[i].resize(noItems+1);

    for (int i=1; i<=noItems; i++) {
        for (int j=1; j<=noItems; j++) {
            if (sequence[i-1] == sortedSequence[j-1]) table[i][j] = table[i-1][j-1] + 1;
            else table[i][j] = max(table[i-1][j], table[i][j-1]); 
        }
    }

    print();
    cout << table[noItems][noItems];
}