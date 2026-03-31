// DONE
// Jumping with Cost

#include <bits/stdc++.h>
using namespace std;

int length, jumpDistance;
vector<int> scores, cost;

int main() {
    cin >> length >> jumpDistance;

    scores.resize(length);
    cost.resize(jumpDistance+1);

    for (int i=0; i<length; i++) cin >> scores[i];
    for (int i=1; i<=jumpDistance; i++) cin >> cost[i];
    
    for (int i=1; i<length; i++) {
        int maxiter = -1e7;
        for (int j=1; j<=jumpDistance; j++) {
            if (i-j < 0) break;
            maxiter = max(maxiter, scores[i-j] - cost[j]);      
        }
        scores[i] += maxiter;
    }

    cout << scores[length-1];
}