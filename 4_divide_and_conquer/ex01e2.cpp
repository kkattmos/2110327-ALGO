// DONE
// Maximum Contiguous Sum of Subsequence

#include <iostream>
#include <vector>

using namespace std;

int noItems;
vector<int> items;
vector<int> prefix_sum;

int get_sum(int start, int end) {
    return prefix_sum[end+1] - prefix_sum[start];
}

int mss(int start, int end) {
    
    if (start > end) return 0;
    if (start == end) return items[start];
    int mid = start + (end-start)/2;

    int max_left = mss(start, mid);
    int max_right = mss(mid+1, end);
    
    int max_sum_left = get_sum(mid, mid);
    for (int i=mid; i>=start; i--) max_sum_left = max(max_sum_left, get_sum(i, mid));

    int max_sum_right = get_sum(mid+1, mid+1);
    for (int i=mid+1; i<=end; i++) max_sum_right = max(max_sum_right, get_sum(mid+1, i));

    int max_center = max_sum_left + max_sum_right;
    return max(max_left, max(max_center, max_right));

}

int main() {
    cin >> noItems;

    items.assign(noItems, 0);
    prefix_sum.assign(noItems+1, 0);

    for (int i=0; i<noItems; i++) {
        cin >> items[i];
        prefix_sum[i+1] = items[i] + prefix_sum[i];
    }
    cout << mss(0, noItems-1);
}