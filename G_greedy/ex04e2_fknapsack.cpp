//
// Fractional Knapsack

#include <bits/stdc++.h>
using namespace std;

double totalWeight;
int noItems;
vector<double> priceList, weightList;
vector<pair<double, int>> valueList;
double totalValue = 0;

void print() {
    cout << "TEST\n";
    for (const auto &x: valueList) cout << x.first << " " << x.second << "\n";

}

int main() {
    cin >> totalWeight >> noItems;

    priceList.resize(noItems);
    weightList.resize(noItems);
    valueList.resize(noItems);

    for (int i=0; i<noItems; i++) cin >> priceList[i];
    for (int i=0; i<noItems; i++) {
        cin >> weightList[i];
        valueList[i] = make_pair(priceList[i] / weightList[i], i);
    }

    sort(valueList.rbegin(), valueList.rend());
    //print();

    int currPos = 0;
    for (currPos; currPos<noItems; currPos++) {
        if (weightList[valueList[currPos].second] >= totalWeight) break;
        totalWeight -= weightList[valueList[currPos].second];
        totalValue += priceList[valueList[currPos].second];
    }

    if (currPos != noItems) totalValue += valueList[currPos].first * totalWeight;
    std::cout << std::fixed << std::setprecision(4);
    cout << totalValue;
}