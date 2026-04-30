// DONE
// Clique

#include <bits/stdc++.h>
using namespace std;

int noPeople;
vector<int> power, currentCombination, suffixsum;
vector<vector<bool>> isRelated;

int bestSoFar = 0;

bool isSafe(vector<int> s, int count) {
    if (s[count] != 1) return true;
    for (int i=0; i<count; i++) {
        if (s[i] == 1 && !isRelated[i][count]) return false;
    }
    return true;
}

void loop(int idConsidering, int currentSum) {
    //cout << "pass\n";
    bestSoFar = max(bestSoFar, currentSum);
    if (idConsidering == noPeople) return;

    if (currentSum + suffixsum[idConsidering] <= bestSoFar) return;

    bool joinable = true;
    for (const auto &p: currentCombination) {
        if (!isRelated[idConsidering][p]) {
            joinable = false;
            break;
        }
    }

    if (joinable) {
        currentCombination.push_back(idConsidering);
        loop(idConsidering+1, currentSum + power[idConsidering]);
        currentCombination.pop_back();
    }

    loop(idConsidering+1, currentSum);


}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> noPeople;

    power.resize(noPeople);
    for (int i=0; i<noPeople; i++) cin >> power[i];

    suffixsum.assign(noPeople, 0);
    suffixsum[noPeople-1] = power[noPeople-1];
    for (int i=noPeople-2; i>=0; i--) suffixsum[i] = suffixsum[i+1] + power[i]; 

    isRelated.assign(noPeople, vector<bool>(noPeople, false));
    for (int i=0; i<noPeople; i++) {
        for (int j=0; j<noPeople; j++) {
            int tmp; cin >> tmp;
            isRelated[i][j] = (tmp == 1? true:false);
        }
    }

    //cout << "pass\n";
    loop(0, 0);
    cout << bestSoFar;
}