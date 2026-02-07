// DONE
// Binomial Coefficient

// Solve using bottom up

#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<vector<int>> lookup;

int main() {
    cin >> n >> k;

    if (n == k) {
        cout << 1;
        return 0;
    }
    
    vector<int> tmp(k+1, -999999);
    tmp[0] = 1;
    lookup.assign(n+1, tmp);

    for (int i=1; i<=k; i++) lookup[i][i] = 1;

    for (int it_k=1; it_k<=k; it_k++) {
        for (int it_n = it_k+1; it_n<=n; it_n++) {
            lookup[it_n][it_k] = lookup[it_n-1][it_k-1] + lookup[it_n-1][it_k];
        }
    }

    cout << lookup[n][k];
}