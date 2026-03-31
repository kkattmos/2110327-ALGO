//
// Difference Less than

#include <bits/stdc++.h>
using namespace std;

int noItems, target;

int main() {
    cin >> noItems >> target;

    vector<int> values(noItems);
    for (int i=0; i<noItems; i++) cin >> values[i];

    vector<int> sortedValues(values.begin(), values.end());
    sort(sortedValues.begin(), sortedValues.end());

    long long diffCount = 0;
    for (int i=1; i<noItems; i++) {
            auto low = lower_bound(sortedValues.begin(), sortedValues.end(), values[i] - target);
            auto high = upper_bound(sortedValues.begin(), sortedValues.end(), values[i] + target);

            diffCount += high - low;
            
            //if (abs(values[i] - values[j]) <= target) currCount++;
        }    

    cout << diffCount;
}