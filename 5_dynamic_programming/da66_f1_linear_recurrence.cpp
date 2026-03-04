// DONE (Top-up)
// Linear Recurrence

#include <bits/stdc++.h>
using namespace std;

int k, n;
vector<int> c, a;
vector<pair<bool, int>> memo;

const int MODULO = 32717;

int add(int a, int b) {
    return ((a % MODULO) + (b % MODULO)) % MODULO;
}

int mul(int a, int b) {
   return ((a % MODULO) * (b % MODULO)) % MODULO;
}

int R(int n) {
    if (memo[n].first) return memo[n].second;

    if (n < k) return a[n];

    int sum = 0;
    for (int i=1; i<=k; i++) sum = add(sum, mul(c[i], R(n-i)));
    
    memo[n] = {true, sum};
    return sum;
}

int main () {
    cin >> k >> n;
    c.assign(k+1, 0);
    a.assign(k, 0);

    pair<int, int> tmp = {false, 0};
    memo.assign(n+1, tmp);

    for (int i=0; i<k; i++) cin >> c[i+1];
    for (int i=0; i<k; i++) cin >> a[i];

    cout << R(n);
}