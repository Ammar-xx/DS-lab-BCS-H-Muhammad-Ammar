#include <iostream>
using namespace std;

int main() {

    int studentCount;
    cout << "Enter number of students: ";
    cin >> studentCount;

    int **scores = new int*[studentCount];

    int *courseCount = new int[studentCount];
    cout << "Enter number of courses for each student" << endl;
    for(int s = 0; s < studentCount; s++) {
        cout << s + 1 << ": ";
        cin >> courseCount[s];
        scores[s] = new int[courseCount[s]];
    }

    cout << "Enter marks for each student" << endl;
    for(int s = 0; s < studentCount; s++) {
        cout << "Student " << s + 1 << endl;
        for(int c = 0; c < courseCount[s]; c++) {
            cout << "Course " << c + 1 << ": ";
            cin >> scores[s][c];
        }
        cout << endl;
    }

    cout << "Displaying marks & average for each Student" << endl;
    for(int s = 0; s < studentCount; s++) {
        cout << "Student " << s + 1 << ": ";
        int sum = 0;
        for(int c = 0; c < courseCount[s]; c++) {
            cout << scores[s][c] << " ";
            sum += scores[s][c];
        }
        cout << "| Average: " << (float)sum / courseCount[s] << endl;
    }

    delete[] courseCount;
    for(int s = 0; s < studentCount; s++) {
        delete[] scores[s];
    }
    delete[] scores;

}
