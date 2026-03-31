// DONE
// Longest Increasing Subsequence

#include <bits/stdc++.h>
using namespace std;

int length;
vector<int> numbers;

int main() {
    cin >> length;

    numbers.resize(length);
    for (int i=0; i<length; i++) cin >> numbers[i];

    vector<int> sortedNumbers(numbers.begin(), numbers.end());
    sort(sortedNumbers.begin(), sortedNumbers.end());

    int memo[length+1][length+1];

    for (int r=0; r<=length; r++) {
        for (int c=0; c<=length; c++) {
            if (r == 0 || c == 0) memo[r][c] = 0;
            else if (numbers[r-1] == sortedNumbers[c-1]) memo[r][c] = memo[r-1][c-1] + 1;
            else memo[r][c] = max(memo[r-1][c], memo[r][c-1]);  
        }
    }
    
    cout << memo[length][length];
}