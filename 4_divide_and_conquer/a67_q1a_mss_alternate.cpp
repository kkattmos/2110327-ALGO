//
// Maximum Subarray Alternating Sum

#include <bits/stdc++.h>
using namespace std;

int noItems;
vector<int> prefixSum;

int getPrefixSum(int startIndex, int endIndex) {
    return prefixSum[endIndex+1] - prefixSum[startIndex];
}

int getMSAS(int startIndex, int endIndex) {
    if (startIndex == endIndex) return getPrefixSum(startIndex, startIndex);

    int midIndex = (startIndex + endIndex) / 2;

    int maxLeft = getMSAS(startIndex, midIndex);
    int maxRight = getMSAS(midIndex+1, endIndex);

    


}

int main() {
    cin >> noItems;
    prefixSum.assign(noItems+1, 0);

    for (int i=0; i<noItems; i++) {
        cin >> prefixSum[i+1];
        prefixSum[i+1] += prefixSum[i];
    }

    cout << getMSAS(0, noItems-1);
}