// DONE
// Stable Sort Check

#include <bits/stdc++.h>
using namespace std;

int noItems, noQueries;
vector<pair<int, int>> values; // value, counter
map<int, int> counter;
vector<int> toCheck;

void print() {
    cout << "TEST: \n";
    for (const auto &x: values) {
        cout << x.first << " " << x.second << "\n";
    }
}

int main() {
    cin >> noItems >> noQueries;

    values.assign(noItems, {0, 1});
    for (int i=0; i<noItems; i++) {
        cin >> values[i].first;

        if (counter.find(values[i].first) == counter.end()) counter[values[i].first] = 1;
        else values[i].second = ++counter[values[i].first];
        
    };

    //print();
    
    toCheck.resize(noItems+1);
    for (int _=0; _<noQueries; _++) {
        for (int i=0; i<noItems; i++) {
            cin >> toCheck[i];
            toCheck[i]--;
        }

        int isSorted = 1;
        int isStable = 1;

        for (int i=0; i<noItems-1; i++) {
            //cout << "Comparing: " << values[toCheck[i]] << " " <<  << "\n";
            
            //Checking if "เรียงกัน"
            if (values[toCheck[i]].first > values[toCheck[i+1]].first) {
                isSorted = 0;
                isStable = 0;
                break;
            }

            // Checking if "เสถียร"
            if (!isStable) continue;
            //cout << "Comparing1: " << values[toCheck[i]].first << " " << values[toCheck[i+1]].first << "\n";
            if (values[toCheck[i]].first == values[toCheck[i+1]].first) {
                //cout << "Comparing2: " << values[toCheck[i]].second << " " << values[toCheck[i+1]].second << "\n";
                if (values[toCheck[i]].second > values[toCheck[i+1]].second) {
                    isStable = 0;
                }
            }
        }

        cout << isSorted << " " << isStable << "\n";
    }
}