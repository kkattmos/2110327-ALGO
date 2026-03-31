// DONE
// Linear Recurrence

#include <bits/stdc++.h>
using namespace std;

const int MOD = 32717;
int k, n;
vector<int> c, R;

int add(int a, int b) {return (a%MOD + b%MOD) % MOD;}
int mul(int a, int b) {return (a%MOD * b%MOD) % MOD;}

int main() {
    cin >> k >> n;

    c.resize(k+1);
    R.resize(n+1);

    for (int i=1; i<=k; i++) cin >> c[i];
    for (int i=0; i<k; i++) cin >> R[i];

    for (int ni=k; ni<=n; ni++) {
        int sum = 0;
        for (int ck=1; ck<=k; ck++) sum = add(sum, mul(c[ck], R[ni-ck]));
        R[ni] = sum;
    }

    cout << R[n]; 
}