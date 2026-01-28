#include <iostream>

using namespace std;

pair<long long, int> getUpperBound(long long &x) {
    int k=0; 
    long long result = 1;
    while (result < x) {
        k++;
        result *= 2;
    }
    return {result, k};
}

long long x;
int main() {
    cin >> x;
    
    if (x == 0) {
        cout << 0;
        return 0;
    }

    pair<long long, int> res = getUpperBound(x);
    cout << res.first - x + 24 - res.second;
    cout << "\nDebug: " << res.first << " " << res.second;
}