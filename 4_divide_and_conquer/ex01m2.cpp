//
//Inversion
// Solve using brute force

#include <iostream>
#include <vector>

using namespace std;

int capacity;
int inversionCount; // For tracking
int main() {
    cin >> capacity;
    vector<int> data(capacity);

    for (int i=0; i<capacity; i++) cin >> data[i];

    for (int i=0; i<capacity; i++) {
        for (int j=i; j<capacity; j++) {
            if (data[i] > data[j]) inversionCount++;
        }
    }

    cout << inversionCount;
}