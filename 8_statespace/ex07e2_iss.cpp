//
// Incresing sequence sum

#include <bits/stdc++.h>
using namespace std;

int target;

int counter = 0;

void nextState(int remaining, int lastVal) {
    for (int i=lastVal; i<=target; i++) {
        if (remaining - i == 0) counter++;
        if (remaining - i > 0) nextState(remaining-i, i);
    }
}

int main() {
    cin >> target;
    nextState(target, 1);
    cout << counter;
}