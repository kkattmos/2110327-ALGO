//
// Pressure Station

#include <bits/stdc++.h>
using namespace std;

int length, dist;
vector<int> costs;
vector<int> memo;
int minValue = 1e7;

void print() {
    cout << "TEst: ";
    for (const auto &x: memo) cout << x << " ";
    cout << "\n";
}
int main() {
    cin >> length >> dist;

    costs.assign(length+1, 0);
    for (int i=1; i<=length; i++) cin >> costs[i];

    memo.assign(length+1, 0);
    for (int i=1; i<=length; i++) {
        int minTmp = 1e7;
        if (i <= dist+1) {
            for (int j=1; j<=i; j++) minTmp = min(minTmp, costs[j]);
        }
        else {
            for (int j=1; j<=dist; j++) minTmp = min(minTmp, costs[i-j] + memo[i-j-1]);
        }
        memo[i] = minTmp;
    }

    print();
    cout << memo.back();
}