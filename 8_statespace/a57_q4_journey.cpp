// [PPPPPTTTTT]
// Journey

#include <bits/stdc++.h>
using namespace std;

int noCities;
vector<vector<int>> score;
vector<bool> used;
vector<int> maxPossible;

int bestSoFar = -1e7;

void loop(int citiesVisited, int prevCityID, int currScore) {
    int potentialScore = currScore;
    for (int i=1; i<noCities; i++) {
        if (!used[i] || i == prevCityID) potentialScore += maxPossible[i];
    }
    if (potentialScore <= bestSoFar) return;
    
    if (prevCityID == noCities-1) {
        if (citiesVisited == noCities-1) bestSoFar = max(bestSoFar, currScore);
        return;
    }

    for (int i=1; i<noCities; i++) {
        if (!used[i]) {
            used[i] = true;
            loop(citiesVisited+1, i, currScore + score[prevCityID][i]);
            used[i] = false;
        }
    }
}

int main() {
    cin >> noCities;

    score.assign(noCities, vector<int>(noCities, -1));
    maxPossible.assign(noCities, -1e7);
    for (int i=0; i<noCities; i++) {
        for (int j=0; j<noCities; j++) {
            cin >> score[i][j];
            if (i != j) maxPossible[i] = max(maxPossible[i], score[i][j]);
        }
    }

    used.assign(noCities, false);
    used[0] = false;
    loop(0, 0, 0);

    cout << bestSoFar;
}