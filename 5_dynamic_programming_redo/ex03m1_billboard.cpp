//
// Advertising Placement

#include <bits/stdc++.h>
using namespace std;

int length;

int main() {
    cin >> length;

    int viewCount[length];
    for (int i=0; i<length; i++) {
        cin >> viewCount[i];
        if (i < 2) continue;

        int maxCount = -1e7;
        for (int j=0; j<i-1; j++) maxCount = max(maxCount, viewCount[j]);
        viewCount[i] += maxCount;
    }

    cout << max(viewCount[length-1], viewCount[length-2]);
}