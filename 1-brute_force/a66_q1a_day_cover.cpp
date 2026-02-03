// 
// Day Cover

#include <iostream>
#include <vector>

using namespace std;

int noDays, noStudents;
int noVacantDays; // For tracking no of vacant days for each student
int x; //กุคิดชื่อตัวแปรไม่ออก แต่มันจะเก็บว่าว่างวันที่เท่าไหร่ของแต่ละ student
int minStudent;
vector<vector<int>> vacantData; // Stores isEmpty (1) for each day for each student

int loop()

int main() {
    cin >> noDays >> noStudents;
    minStudent = noStudents;
    
    for (int i=0; i<noStudents; i++) {
        vector<int> studentVacant(noDays);

        cin >> noVacantDays;
        for (int j=0; j<noVacantDays; j++) {
            cin >> x;
            studentVacant[x-1] = 1;
        }
        vacantData.push_back(studentVacant);
    }

    //Test 
    /*
    for (int a=0; a<noStudents; a++) {
        for (int b=0; b<noDays; b++) {
            cout << vacantData[a][b] << " ";
        }
        cout << "\n";
    }
    */

    loop()
    
}