// DONE
// Multi Recurrence

#include <bits/stdc++.h>
using namespace std;

const int MOD = 32717;
int n, k;
vector<int> R, tmp;

int add(int a, int b) { return (a%MOD + b%MOD) % MOD; }
int mul(int a, int b) { return (a%MOD * b%MOD) % MOD; }

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k;

    R.assign(n+1, -2);
    R[0] = 0;
    for (int i=1; i<=k; i++) cin >> R[i];
    
    for (int i=k+1; i<=n; i++) {
        int pi; cin >> pi;
        int tmp, sum = 0;
        for (int j=0; j<pi; j++) {
            cin >> tmp;
            if (i >= tmp) sum = add(sum, R[i-tmp]);
        } 
        R[i] = sum;
    }

    for (int i=1; i<=n; i++) cout << R[i] << " ";
}