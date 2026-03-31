// DONE (but needs review)
// 0-1 Knapsack Problem

#include <bits/stdc++.h>
using namespace std;

int noItems, weightLimit;

int main() {
    cin >> noItems >> weightLimit;

    int price[noItems], weight[noItems];
    for (int i=0; i<noItems; i++) cin >> price[i];
    for (int i=0; i<noItems; i++) cin >> weight[i];

    int memo[noItems+1][weightLimit+1];
    for (int r=0; r<=noItems; r++) {
        for (int c=0; c<=weightLimit; c++) cin >> memo[r][c];
    }

    vector<int> ans;
    int currRow = noItems;
    int currCol = weightLimit;

    while (currRow > 0 && currCol > 0) {
        if (memo[currRow][currCol] != memo[currRow-1][currCol]) {
            ans.push_back(currRow);
            currCol -= weight[currRow-1];
        }
        currRow--;
    }

    cout << ans.size() << "\n";
    for (const auto &x: ans) cout << x << " ";
}