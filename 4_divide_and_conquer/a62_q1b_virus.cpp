//DONE

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool is_divoc(vector<int>::iterator start,
                vector<int>::iterator end, 
                int length) {
    
    if (length == 1) {
        return (*(start) == 0 && *(end-1) == 1);
    }

    int half = 1 << (length - 1);
    auto mid = start + half;

    if (!is_divoc(mid, end, length-1)) return false;

    if (is_divoc(start, mid, length-1)) return true;
    
    reverse(start, mid);
    bool result = is_divoc(start, mid, length-1);
    reverse(start, mid);
    return result;

} 


int length, noQueries;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> noQueries >> length;
    int lengthExpo = 2 << (length-1);
    //cout << "Test: " << lengthExpo << "\n";

    vector<int> dna(lengthExpo);

    for (int i=0; i<noQueries; i++) {
        for (int j=0; j<lengthExpo; j++) cin >> dna[j];

        if (is_divoc(dna.begin(), dna.end(), length)) cout << "yes\n";
        else cout << "no\n";

    }
    //cout << "Program Finished\n";
}