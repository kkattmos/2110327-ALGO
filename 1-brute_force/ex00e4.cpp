//DONE

#include <iostream>
#include <vector>

using namespace std;

void recur(int length,
            int curr,
            vector<int> &letters,
            vector<bool> &used,
            pair<int, int> &lines) {
    
    if (curr < length) {
                if (lines.first != 0) {
                    letters[curr] = 1;
                    lines.first--;
                    recur(length, curr+1, letters, used, lines);
                    lines.first++;
                }
                if (lines.second != 0) {
                    letters[curr] = 0;
                    lines.second--;
                    recur(length, curr+1, letters, used, lines);
                    lines.second++;
                }
    }
    else {
        for (int i=0; i<length; i++) cout << letters[i];
        cout << "\n";
    }
}


int a, b;
int main() {
    cin >> a >> b;

    vector<int> letters(b);
    vector<bool> used(b);
    pair<int, int> lines = {a, b-a};

    recur(b, 0, letters, used, lines);


}