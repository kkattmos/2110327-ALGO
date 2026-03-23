// DONE
// Interval

#include <bits/stdc++.h>
using namespace std;

int noClasses;
vector<pair<int, int>> usage;
int availableCount = 0;

void print() {
    for (const auto &x: usage) cout << x.first << " " << x.second << "\n";
}

int main() {
    cin >> noClasses;

    usage.resize(noClasses);
    for (int i=0; i<noClasses; i++) cin >> usage[i].second;         // Start time
    for (int i=0; i<noClasses; i++) cin >> usage[i].first;          // Stop time

    sort(usage.begin(), usage.end());

    int last = -1;
    for (int i=0; i<noClasses; i++) {
        if (usage[i].second >= last) {
            availableCount++;
            last = usage[i].first;
        }
    }

    cout << availableCount;
}