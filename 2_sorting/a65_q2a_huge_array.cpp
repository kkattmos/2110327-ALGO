#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

size_t noSets, noQuestions;
long long noStreak, number;
unsigned long long currentIndex = 0; // For index iterating
unsigned long long ask; // ask = the index we want to know its value

unordered_map<long long, unsigned long long> data_count; // {number_value: number_count}
vector<long long> data_members; // {number_value}
vector<pair<long long, long long>> actualArray; // sorted; {start_index_count: number_value}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL), cout.tie(NULL);

    cin >> noSets >> noQuestions;

    //1. Storing data in map, vector temporaily
    for (size_t i=0; i<noSets; i++) {
        cin >> number >> noStreak;

        if (data_count.find(number) == data_count.end()) { // Not exist at first
            data_count[number] = noStreak;
            data_members.push_back(number);
        }
        else { // Number already exists
            data_count[number] += noStreak;
        }

    }

    //2. Selection sort; iterating index count
    size_t data_members_size = data_members.size();
    for (size_t not_sorted = 0; not_sorted < data_members_size; not_sorted++) {
        long long min_id = data_members_size-1;
        
        for (size_t i=not_sorted; i < data_members_size; i++) {
            if (data_members[i] < data_members[min_id]) min_id = i; 
        }

        swap(data_members[not_sorted], data_members[min_id]);
        actualArray.push_back({currentIndex, data_members[not_sorted]});
        currentIndex += data_count[data_members[not_sorted]];

    }

    //3. Ask queries
    for (size_t i=1; i<=noQuestions; i++) {
        cin >> ask;

        auto it = lower_bound(actualArray.begin(), actualArray.end(), make_pair(ask, 0LL),
        [](const std::pair<long long, long long>& a, const std::pair<long long, long long>& b) {
        return a.first < b.first;
        });
        it--;
        //cout << "Test: " << i << " " << it->first << " " << it->second << "\n";
        cout << it->second << "\n";
    }
}