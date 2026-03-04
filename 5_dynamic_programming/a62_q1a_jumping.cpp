// DONE (Bottom-up)
// Jumping

#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> points;
vector<int> memo;

int main() {
    cin >> n;

    points.resize(n+1);
    for (int i=1; i<=n; i++) cin >> points[i];

    memo.resize(n+1);

    for (int i=1; i<=n; i++) {
        if (i == 1) memo[i] = points[i];
        else if (i == 2) memo[i] = points[i] + points[i-1];
        else if (i == 3) memo[i] = points[i] + max(memo[i-1], memo[i-2]);
        else memo[i] = points[i] + max(memo[i-1], max(memo[i-2], memo[i-3]));
    }

    cout << memo[n];

    //Debug
    cout << "\n";
    for (const auto &x: memo) cout << x << " ";


}