// [[P-PP-P][PPP][PPP][PPPP][PPPP]]
// Strange Pictures

#include <bits/stdc++.h>
using namespace std;

int length, noPlates;
vector<vector<bool>> collection;
vector<bool> isValid;

vector<int> score;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> length >> noPlates;

    length *= length;
    collection.resize(noPlates);
    score.assign(length, 0);
    for (int i=0; i<noPlates; i++) {
        collection[i].resize(length);
        for (int j=0; j<length; j++) {
            int tmp; cin >> tmp;
            collection[i][j] = (tmp);
            if (tmp) score[j]++;
        }
    }

    isValid.assign(noPlates, true);
    for (int i=0; i<length; i++) {
        int tmp; cin >> tmp;
        if (tmp) {
            // 1: If we cannot find plate that has 1, return -1 immediately
            bool flagged = true;
            for (int j=0; j<noPlates; j++) {
                if (collection[j][i]) {
                    flagged = false;
                    break;
                }
            }
            if (flagged) {
                cout << "-1";
                return 0;
            }
        }
        else {
            // 0; Remove plates that has 1
            for (int j=0; j<noPlates; j++) {
                if (collection[j][i]) {
                    if (score[i]) {
                        isValid[j] = false;
                        score[i]--;
                    }
                }
            }
        }
    }

    cout << count(isValid.begin(), isValid.end(), true) << "\n";
    for (int i=0; i<noPlates; i++) {
        if (isValid[i]) cout << i+1 << " ";
    }
}