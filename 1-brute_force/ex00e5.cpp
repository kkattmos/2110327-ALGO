#include <iostream>
#include <vector>

using namespace std;

void combi(int n, int k, vector<int> &sol, int curr, int oneConsecutive, int maxConsecutive) {
    if (curr < n) {
        sol[curr] = 0;
        combi(n, k, sol, curr+1, 0, maxConsecutive);
        sol[curr] = 1;
        combi(n, k, sol, curr+1, oneConsecutive+1, max(oneConsecutive+1, maxConsecutive));
    }  
    else {
        if (maxConsecutive < k) return;
        for (int i=0; i<n; i++) {
            cout << sol[i];
        }
        cout << "\n";
    }
}

int n, k;

int main() {
    ios_base::sync_with_stdio(true);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    vector<int> result(n);
    
    combi(n, k, result, 0, 0, 0);
}