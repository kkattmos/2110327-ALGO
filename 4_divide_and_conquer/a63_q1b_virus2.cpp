#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_divoc(vector<int>::iterator start,
                vector<int>::iterator end,
                int size) {

    if (size == 1) return true;
    
    auto mid = (end-start) / 2;
    int leftCount = count(start, start+mid, 1);
    int rightCount = count(start+mid, end, 1);

    if (abs(rightCount-leftCount) > 1) return false;

    bool isDivocLeft = is_divoc(start, start+mid, size-1);
    bool isDivocRight = is_divoc(start+mid, end, size-1);

    return isDivocLeft && isDivocRight;
}

int noQueries, length;
int main() {
    cin >> noQueries >> length;

    int lengthExpo = 2 << (length-1);

    vector<int> dna(lengthExpo);
    for (int i=0; i<noQueries; i++) {
        for (int j=0; j<lengthExpo; j++) cin >> dna[j];

        if (is_divoc(dna.begin(), dna.end(), length)) cout << "yes\n";
        else cout << "no\n";

    }
    


}