// DONE
// Jumping

#include <bits/stdc++.h>
using namespace std;

int length;
vector<int> score;

int main() {
    cin >> length;

    score.resize(length+1);
    
    for (int i=0; i<length; i++) cin >> score[i];
    for (int i=1; i<length; i++) {
        if (i == 1) score[i] = score[i] + score[i-1];
        else if (i == 2) score[i] = score[i] + max(score[i-1], score[i-2]);
        else score[i] = score[i] + max(score[i-1], max(score[i-2], score[i-3]));
    }

    cout << score[length-1];
}