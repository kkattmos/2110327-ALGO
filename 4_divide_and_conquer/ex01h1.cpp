//
//Self Describing Sequence

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

size_t noQueries, index;
vector<size_t> endIndex;
// [1, 3, 5, 8]
size_t cumulativeSum = 0; // For tracking

void calc(size_t index) {
    while (*(endIndex.end()-1) > index) {
        size_t currrentValue = endIndex.size();
        endIndex.push_back(1 + endIndex[])
    }
}

int main() {
    // cin >> noQueries;

    endIndex.push_back(1); // a(1) = 1
    calc(10);
    return 0;

    for (size_t i=0; i<noQueries; i++) {
        cin >> index;
        
        if (lower_bound(endIndex.begin(), endIndex.end(), index) == endIndex.end()) calc(index);
    }
}