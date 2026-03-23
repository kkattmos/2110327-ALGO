// DONE
// Buffet

#include <bits/stdc++.h>
using namespace std;

int noFoods, dist, length;
vector<int> foodIndex;

int main() {
    cin >> noFoods >> dist >> length;

    foodIndex.resize(noFoods);
    for (int i=0; i<noFoods; i++) cin >> foodIndex[i];

    sort(foodIndex.begin(), foodIndex.end());

    int lampCount = 0;
    int endLight = 0;
    for (int i=0; i<noFoods; i++) {
        if (foodIndex[i] > endLight) {
            lampCount++;
            endLight = foodIndex[i] + 2*dist;
            //cout << "Test: " << endLight << "\n";
        }
    }
    cout << lampCount;
}