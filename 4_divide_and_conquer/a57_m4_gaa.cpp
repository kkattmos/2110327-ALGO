// [PPP][PPP][PPP][PPP][PPP][xxx][xxx][xxx][xxx][xxx]
// GAA

#include <bits/stdc++.h>
using namespace std;

int target;
vector<int> gIndex = {1};
int totalLength = 3;

void generate(int k) {
    if (totalLength > target) return;

    int originalLength = totalLength;
    int toAdd = gIndex.size();

    gIndex.push_back(*(gIndex.end()-1) + 3);
    totalLength += (k+3);
    
    if (totalLength > target) return;
    for (int i=0; i<toAdd; i++) gIndex.push_back(*(gIndex.begin()+i)+totalLength);
    totalLength += originalLength;

    generate(k+1);
}

int main() {
    cin >> target;
    generate(1);

    if (*(lower_bound(gIndex.begin(),gIndex.end(), target)) == target) cout << 'g';
    else cout << 'a';
}