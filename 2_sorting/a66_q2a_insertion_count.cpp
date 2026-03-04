//
// Insertion Sort Count

#include <bits/stdc++.h>
using namespace std;

int noData, noQueries;
vector<int> values;
int toFind;

int main() {
    cin >> noData >> noQueries;

    values.resize(noData);
    for (int i=0; i<noData-1; i++) cin >> values[i];

    for (int _=0; _<noQueries; _++) {
        cin >> toFind;

        vector<int> tmp = values;
        int count = 0;

        for (int pos = values.size()-2; pos >= 0; pos--) {
            int toInsert = tmp[pos];
            size_t i = pos+1;
            while (i < tmp.size() && tmp[i] < toInsert) {
                tmp[i-1] = tmp[i];
                count++;
                i++;
            }
            tmp[i-1] = toInsert;
        }

        cout << count << "\n";
    }

}