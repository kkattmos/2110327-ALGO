// DONE
// Thanos (ดีดนิ้ว)

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int expoLength, noAvengers, baseDamage, avengersDamage;
map<long long, int> avengersCount;
vector<pair<long long, int>> avengersIndex;

// Idea: when the ranges does not contain avenger, simply return baseDamage

long long getNoAvengers(long long start, long long end) {
    int inboundAvengerCount = 0;
    auto currIT = lower_bound(avengersIndex.begin(), avengersIndex.end(), make_pair(start, 0)); 

    while (currIT->first <= end && currIT != avengersIndex.end()) {
        inboundAvengerCount += currIT->second;
        currIT++;
    }

    return inboundAvengerCount;
}

long long flick(long long start, long long end) {
    //cout << "Test2: " << start << " " << end << " " << inboundAvengerCount << "\n";
    long long inboundAvengerCount = getNoAvengers(start, end);
    if (inboundAvengerCount == 0) return baseDamage;
    else return (long long)avengersDamage * inboundAvengerCount * (end-start+1);
}

long long getDamage(long long start, long long end) {
    //cout << "Called: " << start << " " << end << "\n";
    if (end-start <= 0 || getNoAvengers(start, end) == 0) return flick(start, end);

    auto mid = start + (end-start) / 2;
    auto allDamage = flick(start, end);
    auto leftDamage = getDamage(start, mid);
    auto rightDamage = getDamage(mid+1, end);

    //cout << "Damage: " << start << " " << end << " " << allDamage << " " << leftDamage << " " << rightDamage << "\n";
    return min(allDamage, leftDamage + rightDamage);
}

int main() {
    cin >> expoLength >> noAvengers >> baseDamage >> avengersDamage;

    int tmp;
    for (int i=0; i<noAvengers; i++) {
        cin >> tmp;
        if (avengersCount.find(tmp) == avengersCount.end()) avengersCount[tmp] = 1;
        else avengersCount[tmp]++;
    }

    for (const auto &x: avengersCount) avengersIndex.push_back(make_pair(x.first, x.second));

    cout << getDamage(1, (1 << expoLength));
}