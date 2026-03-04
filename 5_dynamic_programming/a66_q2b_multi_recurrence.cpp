// 70.0
// Multi Recurrence

#include <bits/stdc++.h>
using namespace std;

int n, k, pi;
vector<int> a;
vector<int> b;

vector<pair<bool, int>> memo;

const int MODULO = 32717;

int add(int a, int b) {
    return ((a % MODULO) + (b % MODULO)) % MODULO;
}

int R(int n) {
    if (n <= 0) return 0;
    if (n <= k) return a[n];
    
    if (memo[n].first) return memo[n].second;
    
    int sum = 0;
    for (int i=0; i< b.size(); i++) {
        sum = add(sum, R(n - b[i]));
    }
    
    memo[n] = {true, sum};
    return sum;
}

int main() {
    cin >> n >> k;
 
    a.resize(k+1);
    for (int i=1; i<=k; i++) cin >> a[i];

    b.resize(n+1);
    memo.assign(n+1, {false, 0});

    for (int i=1; i<= n; i++) {
        if (i >= k+1) {
            cin >> pi;
            b.resize(pi);
            for (int j=0; j<pi; j++) cin >> b[j];
        }

        cout << R(i) << " ";
        b.clear();
    }

}