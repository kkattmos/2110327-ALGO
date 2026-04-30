// DONE (please review)
// One Two Apart

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

int n;
vector<pair<ull, ull>> memo;

const ull MOD = 100000007;

ull add(ull a, ull b) {
    return (a%MOD + b%MOD) %MOD;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;

    memo.assign(n+3, {0, 0});
    memo[0] = {0, 0};
    memo[1] = {1, 2};
    memo[2] = {3, 4};

    for (int i=3; i<=n; i++) {
        memo[i].first = add(memo[i-1].first,memo[i-1].second);
        memo[i].second = add(memo[i].first, memo[i-2].first);
    }

    cout << add(memo[n].first, memo[n].second);
}