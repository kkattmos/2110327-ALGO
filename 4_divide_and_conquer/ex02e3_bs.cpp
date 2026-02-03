//DONE

#include <iostream>
#include <vector>

using namespace std;

//     n        m
size_t noArray, noQueries;
size_t value;

size_t looping(vector<size_t>::iterator start,
                vector<size_t>::iterator end,
                vector<size_t>::iterator origin,
                size_t valueToCheck) {
    
    size_t arraySize = end - start;
    size_t mid = arraySize >> 1;

    
    if (arraySize == 1) {
        return start - origin;
    }
    else {
        if (valueToCheck < *(start + mid)) return looping(start, start+mid, origin, valueToCheck);
        else return looping(start+mid, end, origin, valueToCheck);
    }

}


int main() {
    cin >> noArray >> noQueries;

    vector<size_t> numbers(noArray);
    for (size_t i=0; i<noArray; i++) cin >> numbers[i];

    for (size_t i=0; i<noQueries; i++) {
        cin >> value;
        
        
        //Edge case: when num is lower than first value
        if (value < numbers[0]) cout << "-1\n";
        
        //Edge case: when value is higher that last value
        else if (value >= numbers[numbers.size()-1]) cout << numbers.size()-1 << "\n";

        else cout << looping(numbers.begin(), numbers.end(), numbers.begin(), value) << "\n";

    }
    

}