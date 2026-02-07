// DONE
// Shoot ‘em up control

#include <bits/stdc++.h>

using namespace std;

int noSeconds, width, startPosition;
vector<char> ans;
vector<vector<char>> ansList;
vector<int> used;

vector<pair<char, int>> moves = {
    make_pair('D', -1),
    make_pair('S', 0),
    make_pair('U', 1)

};

void generate(int currPosition, int currTime) {
    if (currPosition < 1 || currPosition > width) return; // Crash into boundary

    if (currTime == noSeconds) {
        ansList.push_back(ans);
        return;
    }

    for (const auto &m: moves) {
        if (ans[currTime] == '-') {
            ans[currTime] = m.first;
            generate(currPosition + m.second, currTime+1);
            ans[currTime] = '-';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> noSeconds >> width >> startPosition;

    ans.assign(noSeconds, '-');
    used.assign(noSeconds, 0);
    generate(startPosition, 0);

    for (const auto &x: ansList){
        for (const auto i: x) cout << i;
        cout << "\n";
    }
}