#include <iostream>
#include <vector>

using namespace std;

//  n              m
int arrayCapacity, noTarget;
long long arrayValue, targetValue;

vector<long long> numbers;

bool loop(int arrayCapacity, 
            long long currentValue,
            int len, 
            vector<bool> &used) {
    if (len < 3) {
        for (int i=1; i<=arrayCapacity; i++) {
            if (!used[i]) {
                used[i] = true;
                currentValue += numbers[i];
                cout << numbers[i] << " ";
                loop(arrayCapacity, currentValue, len+1, used);
                used[i] = false;
            }
        }
    }
    else {
        if (targetValue == currentValue) {
            cout << "YES\n";
            return true;
        }
        else {
            cout << "NO\n";
            return false;
        }
    }
}


void start(long long targetValue) {
    long long currSol;
    vector<bool> used(arrayCapacity);
    loop(arrayCapacity, 0, 0, used);
}



int main() {
    cin >> arrayCapacity >> noTarget;
    for (int i=0; i<arrayCapacity; i++) {
        cin >> arrayValue;
        numbers.push_back(arrayValue);
    }
    for (int i=0; i<noTarget; i++) {
        cin >> targetValue;
        start(targetValue);
        cout << "=========\n";
    }
}