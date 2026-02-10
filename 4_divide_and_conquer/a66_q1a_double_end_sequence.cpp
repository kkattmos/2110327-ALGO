// [PPPPPPPP-P-P[PP---P-P]]
// Maximum Double End Sequence Sum

#include <bits/stdc++.h>
using namespace std;

int noItems;
vector<int> items;
vector<int> prefixSum;

int getPrefixSum(int startIndex, int endIndex) {
    return prefixSum[endIndex+1] - prefixSum[startIndex];
}

int getMSS(int startIndex, int endIndex) {
    if (startIndex == endIndex) return getPrefixSum(startIndex, startIndex);

    int midIndex = (startIndex + endIndex) / 2;
    
    int r1 = getMSS(startIndex, midIndex);
    int r2 = getMSS(midIndex+1, endIndex);

    int r3 = -2e9;

    for (int i=startIndex; i<=midIndex; i++) {

        for (int j=endIndex; j>midIndex; j--) {
            if (items[i] == items[j]) {
                r3 = max(r3, getPrefixSum(i, j));
                break;
            }
        }
    }

    return max(r1, max(r2, r3));

}

int main() {
    cin >> noItems;

    items.assign(noItems, 0);
    prefixSum.assign(noItems+1, 0);

    for (int i=0; i<noItems; i++) {
        cin >> items[i];
        prefixSum[i+1] = items[i] + prefixSum[i];
    }

    cout << getMSS(0, noItems-1);

    
}