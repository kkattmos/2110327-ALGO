// DONE
// Make Zero

#include <iostream>

using namespace std;

long long x;
const long long TARGET_NUMBER = 16777216;

long long action1(long long k) {
    return (k + 1) % TARGET_NUMBER;
}
long long action2(long long k) {
    return (k * 2) % TARGET_NUMBER;
}

int loop(long long x, int noActions) {

    if (x == 0) return noActions;
    if (noActions >= 24) return -1;

    for (int i=1; i<=2; i++) {
        long long new_x = (i == 1) ? action1(x) : action2(x);
        //cout << "Test: " << new_x << "\n";
        int res_new_x = loop(new_x, noActions+1);
        if (res_new_x != -1) return res_new_x;
    }

    return -1;
    
}


int main() {
    cin >> x;
    cout << loop(x, 0);
}