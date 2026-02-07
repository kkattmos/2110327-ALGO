// DONE
// Self Describing Sequence

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int noQueries, i;
vector<int> sequence = {1, 3};

int getIndex(int x) {
    auto it = lower_bound(sequence.begin(), sequence.end(), x);
    return it - sequence.begin() + 1;
}

void generate(int x) {
    if (*(sequence.end()-1) > 2000000000) return;
    sequence.push_back(getIndex(x) + *(sequence.end()-1));
    generate(x+1);
}

int main() {
    
    generate(3);
    cin >> noQueries;
    for (int _=0; _<noQueries; _++) {
        cin >> i;
        cout << getIndex(i) << "\n";
    }
}