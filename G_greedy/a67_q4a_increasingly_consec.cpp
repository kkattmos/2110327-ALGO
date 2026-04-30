// DONE
// Increasingly Consecutive

#include <bits/stdc++.h>
using namespace std;

int noCards;
vector<unsigned long long> cardsCount(1000002, 0);

int maxValueRecorded = -1;

unsigned long long ans = 0;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> noCards;

    for (int i=0; i<noCards; i++) {
        int tmp; cin >> tmp;
        cardsCount[tmp]++;
        maxValueRecorded = max(maxValueRecorded, tmp);
    }

    cardsCount.resize(maxValueRecorded+1);
    sort(cardsCount.begin(), cardsCount.end());

    auto it = lower_bound(cardsCount.begin(), cardsCount.end(), 2);
    while (it != cardsCount.end()) {
        ans += pow(*(it), 2);
        it++;
    }

    cout << ans;
}