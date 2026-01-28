#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

//  n            m
int noDaysTotal, noStudents;
int noFreeDays, freeDays;
const int MAX_NO_DAYS = 1001; // For std::bitset

void combi(int ) {
    // ตอนแรกเราจะ gen ก่อนว่ามี student คนไหนบ้าง
    // หลังจากนั้นค่อย ๆ union ด้วย bitset<>[i]
    // ถ้าทุกตัวเป็น 1 ก็บันทึก result เป็นค่านั้น + return เลย
    // ถ้ามันเกิน current result ตัดออก (Pruning)

    
} 


int main() {

    // 0. Receive Input
    cin >> noDaysTotal >> noStudents;

    vector<bitset<MAX_NO_DAYS>> vacantData;

    for (int i=0; i<noStudents; i++) {
        cin >> noFreeDays;
        for (int j=0; j<noFreeDays; j++) {
            cin >> freeDays;
            vacantData[i].set(freeDays - 1);
        }
    }

    int result = noStudents;
    bitset<MAX_NO_DAYS> unionResult;
    combi();
}