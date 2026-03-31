// [--PP-PPPPP]
// Pandemic

// TODO: fix the issue of -99 pushing

#include <bits/stdc++.h>
using namespace std;

int noRows, noCols, targetDay;
int infectedCount = 0;
int currDay = 1;

const vector<pair<int, int>> DIRS = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}
};

int main() {
    cin >> noRows >> noCols >> targetDay;

    bool isMountain[noRows][noCols] = {false}, isInfected[noRows][noCols] = {false};
    queue<pair<int, int>> toSpread;

    for (int i=0; i<noRows; i++) {
        for (int j=0; j<noCols; j++) {
            int tmp; cin >> tmp;
            if (tmp == 2) isMountain[i][j] = true; 
            else if (tmp == 1) {
                isInfected[i][j] = true;
                toSpread.push(make_pair(i, j));
                infectedCount++;
            }
        }
    }

    toSpread.push(make_pair(-99, -99)); // Indicate the next day

    while (currDay <= targetDay) {
        int currRow = toSpread.front().first;
        int currCol = toSpread.front().second;
        cout << "TEst: " << currRow << " " << currCol << "\n";
        toSpread.pop();

        if (currCol == -99 && currRow == -99) {            
            currDay++;
            toSpread.push(make_pair(-99, -99));
            continue;
        }

        for (const auto &d: DIRS) {
            if (currRow + d.first < 0 || currRow + d.first >= noRows) continue;
            if (currCol + d.second < 0 || currCol + d.second >= noCols) continue;
            if (isMountain[currRow + d.first][currCol + d.second]) continue;

            if (!isInfected[currRow + d.first][currCol + d.second]) {
                isInfected[currRow + d.first][currCol + d.second] = true;
                infectedCount++;
                toSpread.push(make_pair(currRow + d.first, currCol + d.second));
            }
        }
    }

    cout << infectedCount << "\n";

                
            for (int i=0; i<noRows; i++) {
        for (int j=0; j<noCols; j++) cout << (isInfected[i][j]? "I":"-") << " ";
        cout << "\n";
    }
    
}