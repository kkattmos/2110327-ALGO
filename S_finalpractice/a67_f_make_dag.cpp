// DONE (?)
// Make DAG

#include <bits/stdc++.h>
using namespace std;

int noNodes, noEdges;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> noNodes >> noEdges;

    for (int i=0; i<noEdges; i++) {
        int a, b; cin >> a >> b;

        if (a > b) cout << "1 ";
        else cout << "0 ";
    }
}