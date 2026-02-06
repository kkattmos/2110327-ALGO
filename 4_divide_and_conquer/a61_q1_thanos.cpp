//
// Thanos (ดีดนิ้ว)

#include <iostream>
#include <vector>
#include <map>
#include <numeric>

using namespace std;

int expoLength, noAvengers, baseDamage, avengersDamage;
int actualLength;

vector<int> avengersCount;
int totalDamage = 0;

int avengersAttack(vector<int>::iterator start, vector<int>::iterator end) {
    int avCount = accumulate(start, end+1, 0);
    cout << "test: " << avCount << "\n";
    return avengersDamage * avCount * (end-start+1);
}

void updateDamage(int damage) {
    totalDamage += damage;
}

int attack(vector<int>::iterator start, vector<int>::iterator end) {
    if (avengersAttack(start, end) == 0) return baseDamage;
    return avengersAttack(start, end);

}

int destroy(vector<int>::iterator begin, 
                vector<int>::iterator start,
                vector<int>::iterator end) {

    if (avengersAttack(start, end) == 0) return baseDamage;
    int allDamage = attack(start, end);

    if (start == end) {
        updateDamage(allDamage);
        return allDamage;
    }
    
    int length = end - start + 1;
    auto mid = start + length / 2;

    int leftDamage = destroy(begin, start, mid-1);
    int rightDamage = destroy(begin, mid, end);

    return min(allDamage, leftDamage + rightDamage);
}

int main() {
    cin >> expoLength >> noAvengers >> baseDamage >> avengersDamage;
    actualLength = 1 << expoLength;
    avengersCount.assign(actualLength, 0);

    int tmp;
    for (int i=0; i<noAvengers; i++) {
        cin >> tmp;
        avengersCount[tmp-1]++;
    }

    cout << destroy(avengersCount.begin(), avengersCount.begin(), avengersCount.end());
}