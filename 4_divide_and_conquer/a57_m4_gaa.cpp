// DONE
// GAA

#include <bits/stdc++.h>
using namespace std;

int target;
bool isOverbound = false;
bool isG = false;
int currentGPosition = 1;

void check() {
    if (target == currentGPosition) {
        isG = true;
        isOverbound = true;
    }
    else if (target < currentGPosition) {
        isOverbound = true;
    }
}

void updateGPosition(int k) {
    
    if (k == 2) {
        currentGPosition += k + 1;
        check();
        return;
    }
    if (!isOverbound) updateGPosition(k-1);
    
    currentGPosition += k + 1;
    check();

    if (!isOverbound) updateGPosition(k-1);
}

int main() {
    cin >> target;
    //cout << "Initital: " << currentGPosition << "\n";
    updateGPosition(100);

    if (isG) cout << 'g';
    else cout << 'a';
}