// DONE
// Fibonacci Number

#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> fibo = {0, 1};

int main() {
    cin >> n;

    fibo.resize(n+1);
    for (int i=2; i<=n; i++) fibo[i] = fibo[i-1] + fibo[i-2];
    cout << fibo[n];
}