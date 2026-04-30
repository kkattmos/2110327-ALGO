// DONE
// Degrees

#include <bits/stdc++.h>
using namespace std;

int noVertices;
vector<int> degreeCount;
int maxDegree = 0;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> noVertices;
    degreeCount.assign(noVertices+1, 0);

    for (int i=0; i<noVertices; i++) {
        int currCount = 0;
        int tmp;
        for (int j=0; j<noVertices; j++) {
            cin >> tmp;
            if (tmp) currCount++;
        }
        degreeCount[currCount]++;
        maxDegree = max(maxDegree, currCount);
    }

    for (int i=0; i<=maxDegree; i++) cout << degreeCount[i] << " ";
}