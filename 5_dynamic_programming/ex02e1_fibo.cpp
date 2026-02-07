// DONE
// Fibonacci

// Solve using bottom up

#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> fibo_memo;

int main() {
    cin >> n;

    fibo_memo.assign(n+1, -1);
    fibo_memo[0] = 0;
    fibo_memo[1] = 1;

    for (int i=2; i<=n; i++) fibo_memo[i] = fibo_memo[i-1] + fibo_memo[i-2];

    cout << fibo_memo[n];
}