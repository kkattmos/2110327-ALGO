// DONE
// Number Triangle

#include <bits/stdc++.h>
using namespace std;

int level;
vector<int> memo, currEntries;
int maxValue = -1e7;

void print() {
    cout << "TEST: ";
    for (const auto &x: memo) cout << x << " ";
    cout << "\n";
}

int main() {
    cin >> level;
    
    memo.assign(level, 0);
    currEntries.resize(level);

    for (int i=0; i<level; i++) {
        
        for (int j=0; j<=i; j++) cin >> currEntries[j];
        if (i == 0) {
            memo[0] = currEntries[0];
            continue;
        }
        for (int j=i; j>=0; j--) {
            if (j == i) memo[j] = memo[j-1] + currEntries[j];
            else if (j == 0) memo[j] += currEntries[j];
            else memo[j] = max(memo[j-1], memo[j]) + currEntries[j];

            maxValue = max(maxValue, memo[j]);
        }

    }

    cout << maxValue;

}