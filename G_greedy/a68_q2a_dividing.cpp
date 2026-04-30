//
// Horse Dividing

#include <bits/stdc++.h>
using namespace std;

int noHorseGroups;
vector<pair<int, int>> group;

int spicaCount = 0;
int rigilCount = 0;

vector<int> ans;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> noHorseGroups;

    group.resize(noHorseGroups);
    for (int i=0; i<noHorseGroups; i++) {
        cin >> group[i].first;
        group[i].second = i+1;
        spicaCount += group[i].first;
    }
    sort(group.rbegin(), group.rend());

    //for (const auto &x: group) cout << x.first << " ";
    //return 0;

    for (int i=0; i<noHorseGroups; i++) {
        ans.push_back(group[i].second);
        spicaCount -= group[i].first;
        rigilCount += group[i].first;
        if (spicaCount < rigilCount) break;
    }

    cout << ans.size() << "\n";
    for (const auto &a : ans) cout << a << " ";
}