//
// MCS with Width Constraint 

#include <bits/stdc++.h>
using namespace std;

int noItems, widthLimit;
vector<int> prefixSum;

int getPrefixSum(int startIndex, int endIndex) {
    return prefixSum[endIndex+1] - prefixSum[startIndex];
}

int getMCSW(int startIndex, int endIndex) {
    if (startIndex >= endIndex) return getPrefixSum(endIndex, endIndex);

    int r1 = getMCSW(startIndex+1, endIndex);

    int r2 = getPrefixSum(startIndex, startIndex);
    for (int i=2; i<=widthLimit; i++) {
        if (startIndex+i >= noItems) break;
        r2 = max(r2, getPrefixSum(startIndex, startIndex+i));
    }

    return max(r1, r2);
}

int main() {
    cin >> noItems >> widthLimit;

    prefixSum.assign(noItems+1, 0);
    for (int i=0; i<noItems; i++) {
        cin >> prefixSum[i+1];
        prefixSum[i+1] += prefixSum[i];
    }

    cout << getMCSW(0, noItems-1);


}