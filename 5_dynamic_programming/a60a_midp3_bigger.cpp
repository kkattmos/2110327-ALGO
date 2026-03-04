// DONE
// Bigger Billboard

#include <bits/stdc++.h>
using namespace std;

int roadLength;
vector<int> values;
int maxCount = -1e7;

void print() {
    cout << "Test: ";
    for (const auto &x: values) cout << x << " ";
    cout << "\n";
}

int main() {
    cin >> roadLength;

    values.resize(roadLength);
    for (int i=0; i<roadLength; i++) {
        cin >> values[i];
        if (i >= 3) {
            int maxValue = -1e7;
            for (int j=0; j<i-2; j++) maxValue = max(maxValue, values[j]);
            values[i] += maxValue;
        }
        maxCount = max(maxCount, values[i]);
    }
    print();
    cout << maxCount;
}