// DONE (but needs review)
// Bit String With 1’s far apart

#include <bits/stdc++.h>
using namespace std;

const int MOD = 100000007;
int length, dist;

int add(int a, int b) { return (a%MOD + b%MOD) % MOD; }

int main() {
    cin >> length >> dist;

    int memo[length+1];

    memo[0] = 1;
    for (int i=1; i<dist; i++) memo[i] = i+1;
    for (int i=dist; i<=length; i++) memo[i] = add(memo[i-1], memo[i-dist]);
    
    cout << memo[length];
}