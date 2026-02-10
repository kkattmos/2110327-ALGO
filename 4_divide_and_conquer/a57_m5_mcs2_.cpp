// DONE
// Maximum Contiguous Sum of Circular Subsequence

#include <bits/stdc++.h>
using namespace std;

int noData;
vector<int> prefixSum;

int getPrefixSum(int startIndex, int endIndex) {
    return prefixSum[endIndex+1] - prefixSum[startIndex];
}

int getMaxSS(int startIndex, int endIndex) {
    if (startIndex == endIndex) return getPrefixSum(startIndex, startIndex);

    int midIndex = (startIndex + endIndex) / 2;

    int r1 = getMaxSS(startIndex, midIndex);
    int r2 = getMaxSS(midIndex+1, endIndex);

    // Crawl from left side;
    int maxLeft = getPrefixSum(midIndex, midIndex);
    for (int i=startIndex; i<midIndex; i++) maxLeft = max(maxLeft, getPrefixSum(i, midIndex));

    // Crawl from right side;
    int maxRight = getPrefixSum(midIndex+1, midIndex+1);
    for (int i=midIndex+1; i<=endIndex; i++) maxRight = max(maxRight, getPrefixSum(midIndex+1, i));

    int r3 = maxLeft + maxRight;
    return max(r1, max(r2, r3));
    
}

int getMinSS(int startIndex, int endIndex) {
    if (startIndex == endIndex) return getPrefixSum(startIndex, startIndex);

    int midIndex = (startIndex + endIndex) / 2;

    int r1 = getMinSS(startIndex, midIndex);
    int r2 = getMinSS(midIndex+1, endIndex);

    //Crawl from left side;
    int minLeft = getPrefixSum(midIndex, midIndex);
    for (int i=startIndex; i<midIndex; i++) minLeft = min(minLeft, getPrefixSum(i, midIndex));

    //Crawl from right side;
    int minRight = getPrefixSum(midIndex+1, midIndex+1);
    for (int i=midIndex+1; i<=endIndex; i++) minRight = min(minRight, getPrefixSum(midIndex+1, i));

    int r3 = minLeft + minRight;
    return min(r1, min(r2, r3));
}

int main() {
    cin >> noData;
    //numbers.assign(noData, 0);
    prefixSum.assign(noData+1, 0);

    for (int i=0; i<noData; i++) {
        cin >> prefixSum[i+1];
        prefixSum[i+1] += prefixSum[i];
    }

    int maxLinear = getMaxSS(0, noData-1);
    int minLinear = getMinSS(0, noData-1);
    int total = prefixSum[noData];

    if (maxLinear < 0) cout << maxLinear;
    else cout << max(maxLinear, total - minLinear);

    //Test:
    // for (const auto &x: prefixSum) cout << x << " ";

    // cout << "\nTestGetPrefixSum: ";
    //              endIndex+1      startIndex
    // cout << prefixSum[5] - prefixSum[1]; // 9

}