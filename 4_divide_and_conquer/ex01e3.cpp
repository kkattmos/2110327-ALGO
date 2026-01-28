#include <iostream>
#include <vector>

using namespace std;

//     n        m
size_t noArray, noQueries;
size_t value;


// ลองมองในมุมที่ว่า ถ้าต้องการใส่ value นี้ลงใน array เพิ่ม จะใส่ ก่อนหน้า ช่องไหน


int looping(vector<size_t>::iterator start,
                vector<size_t>::iterator end,
                size_t valueCheck) {

    size_t arraySize = end - start;
    //cout << "Test size: " << arraySize << "\n";

    size_t middle = arraySize >> 1;

    if (valueCheck == *(start+middle)) return valueCheck;

    else if (arraySize == 1) return *(start);

    else {
        if (valueCheck < *(start + middle)) return looping(start, start+middle, valueCheck);
        else return looping(start+middle, end, valueCheck); 
    }
    
    /*
    if (arraySize == 1) { // Only 1 data left
        if (valueCheck == *(start)) return valueCheck;
        else return *(start-1);
    }
    else {
        size_t middle = arraySize >> 1;

        if (valueCheck >= *(start + middle)) return looping(start, start+middle-1, valueCheck);
        else return looping(start+middle, end, valueCheck);
    }
    */
}

size_t looping2(vector<size_t> data, size_t valueCheck){
    
    if (data.size() == 1) {

        if (valueCheck == data[0]) {
            return valueCheck;
        }
        else return 999;
    } 
    else {
        size_t middle = data.size() >> 1;

        if (valueCheck >= data[middle]) {
            vector<size_t> newData(data.begin(), data.begin()+middle);
            return looping2(newData, valueCheck);
        } else {
            vector<size_t> newData(data.begin()+middle, data.end());
            return looping2(newData, valueCheck);
        }
        
    }
}

int main() {
    cin >> noArray >> noQueries;

    vector<size_t> stored(noArray);
    for (size_t i=0; i<noArray; i++) cin >> stored[i];

    for (size_t i=0; i<noQueries; i++) {
        cin >> value;

        //Edge case: when value is smaller than first data, print -1
        if (value < stored[0]) cout << "-1\n";

        //Edge case: when value is larger than last data, print last data
        else if (value > stored[stored.size()-1]) cout << stored[stored.size()-1] << "\n";

        else cout << looping(stored.begin(), stored.end(), value) << "\n";

    }

}