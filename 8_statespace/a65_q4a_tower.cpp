//
// Tower Defense 2

#include <bits/stdc++.h>
using namespace std;

int length, noMonsters, noTurrets, range;
vector<pair<int, int>> monstersInfo; // <count, totalHealth>
vector<int> monsterPosition;

vector<bool> placed;
int minPossible = INT_MAX/2;

void calc() {
    
}

void place(int turretCount) {
    if (turretCount > noTurrets) return;
    calc();

    for (int i=1; i<=noTurrets; i++) {
        if (!placed[i]) {
            placed[i] = true;
            place(turretCount+1);
            placed[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> length >> noMonsters >> noTurrets >> range;

    monstersInfo.assign(length+1, {0, 0});
    monsterPosition.assign(noMonsters, -1);
    for (int i=0; i<noMonsters; i++) cin >> monsterPosition[i];
    for (int i=0; i<noMonsters; i++) {
        int h; cin >> h;
        monstersInfo[monsterPosition[i]].first++;
        monstersInfo[monsterPosition[i]].second += h;
    }
    monsterPosition.clear();

    placed.assign(length+1, false);
    place(0);

    cout << minPossible;
}