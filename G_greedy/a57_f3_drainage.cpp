// DONE
// Drainage

#include <bits/stdc++.h>
using namespace std;

int noHoles, plateLength;
vector<int> holesList;

int main() {
    cin >> noHoles >> plateLength;

    holesList.resize(noHoles);
    for (int i=0; i<noHoles; i++) cin >> holesList[i];

    sort(holesList.begin(), holesList.end());

    int plateCount = 0;
    int endIndex = 0;
    for (int i=0; i<noHoles; i++) {
        if (holesList[i] > endIndex) {
            plateCount++;
            endIndex = holesList[i] + plateLength - 1;
        }
    }
    
    cout << plateCount;
}