//
// Lawn Moving

#include <iostream>
#include <vector>

using namespace std;

int length, noQueries, tireConstant;
int startIndex;
long long budgetLimit;
vector<int> grassSum;

int getGrassAmount(int startIndex, int endIndex) {
    //cout << "Checking: " << startIndex << " " << endIndex << '\n';
    int result = grassSum[endIndex] - grassSum[startIndex];
    //cout << "TestGrass; " << endIndex << " " << startIndex << " " << result << "\n";
    return result;
}

long long calculateBudget(int startIndex, int endIndex) {
    return (long long)getGrassAmount(startIndex, endIndex) + (long long)tireConstant * (long long)(endIndex-startIndex+1);
}

// TODO: Store budget infomation per run

int getMostPossibleGrass(int endIndex) {
    if (endIndex == length) return getGrassAmount(startIndex, endIndex);
    if (calculateBudget(startIndex, endIndex+1) > budgetLimit) return getGrassAmount(startIndex, endIndex);
    return getMostPossibleGrass(endIndex+1);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> length >> noQueries >> tireConstant;
    grassSum.assign(length+1, 0);
    for (int i=1; i<=length; i++) {
        cin >> grassSum[i];
        if (i != 0) grassSum[i] += grassSum[i-1];
    }

    for (int _=0; _<noQueries; _++) {
        cin >> startIndex >> budgetLimit;
        cout << getMostPossibleGrass(startIndex) << "\n";
    }
}