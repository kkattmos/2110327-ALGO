// 95.0
// Billboard Feng-Shui

#include <bits/stdc++.h>
using namespace std;

int roadLength, patternLength;
vector<int> peopleCount, pattern, state, suffixsum;

int bestSoFar = 0;

bool isForbidden() {
    if (state.size() < patternLength) return false;
    for (int i = 0; i < patternLength; i++) {
        if (pattern[i] != state[state.size() - patternLength + i]) return false; 
    }
    return true;
}

void loop(int currDist, int currSum) {
    bestSoFar = max(bestSoFar, currSum);
    if (currDist == roadLength) return;
    if (currSum + suffixsum[currDist] <= bestSoFar) return;

    if (currDist == 0 || state.back() == 0) {
        state.push_back(1);
        if (!isForbidden()) loop(currDist+1, currSum + peopleCount[currDist]);
        state.pop_back();
    }

    state.push_back(0);
    if (!isForbidden()) loop(currDist+1, currSum);
    state.pop_back();
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> roadLength >> patternLength;

    peopleCount.resize(roadLength);
    for (int i=0; i<roadLength; i++) cin >> peopleCount[i];

    suffixsum.resize(roadLength);
    suffixsum[roadLength-1] = peopleCount[roadLength-1];
    for (int i=roadLength-2; i>=0; i--) suffixsum[i] = suffixsum[i+1] + peopleCount[i];

    pattern.resize(patternLength);
    for (int i=0; i<patternLength; i++) cin >> pattern[i];

    loop(0, 0);
    cout << bestSoFar;
}