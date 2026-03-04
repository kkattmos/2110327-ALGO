// DONE
// Advertising Placement

#include <bits/stdc++.h>
using namespace std;

int noBillboards;
vector<int> views;

int main() {
    cin >> noBillboards;

    views.resize(noBillboards);

    for (int i=0; i<noBillboards; i++) {
        cin >> views[i];
        if (i < 2) continue;

        int maxValue = -1e7;
        for (int j=0; j<i-1; j++) {
            maxValue = max(maxValue, views[j]);
        }
        views[i] += maxValue;
    }

    cout << max(views[noBillboards-1], views[noBillboards-2]);
}