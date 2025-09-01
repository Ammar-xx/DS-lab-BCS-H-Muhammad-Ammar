#include <iostream>
using namespace std;

int main() {

    int deptCount;
    cout << "Enter number of departments: ";
    cin >> deptCount;

    int **payroll = new int*[deptCount];

    int *employeeCount = new int[deptCount];
    cout << "Enter number of employees in each department" << endl;
    for(int deptIdx = 0; deptIdx < deptCount; deptIdx++) {
        cout << deptIdx + 1 << ": ";
        cin >> employeeCount[deptIdx];
        payroll[deptIdx] = new int[employeeCount[deptIdx]];
    }

    cout << endl << "Enter salary for each employee" << endl;
    for(int deptIdx = 0; deptIdx < deptCount; deptIdx++) {
        cout << "Department " << deptIdx + 1 << endl;
        for(int empIdx = 0; empIdx < employeeCount[deptIdx]; empIdx++) {
            cout << "Employee " << empIdx + 1 << ": ";
            cin >> payroll[deptIdx][empIdx];
        }
        cout << endl;
    }

    cout << endl << "Displaying salary details for each Department" << endl;
    float maxAvgSalary = -1;
    for(int deptIdx = 0; deptIdx < deptCount; deptIdx++) {
        int maxSalary = -1;
        cout << "Department " << deptIdx + 1 << ": ";
        int totalSalary = 0;
        for(int empIdx = 0; empIdx < employeeCount[deptIdx]; empIdx++) {
            cout << payroll[deptIdx][empIdx] << " ";
            totalSalary += payroll[deptIdx][empIdx];
            maxSalary = max(payroll[deptIdx][empIdx], maxSalary);
        }
        cout << "| Highest Salary: " << maxSalary << endl;
        maxAvgSalary = max(maxAvgSalary, (float)totalSalary / employeeCount[deptIdx]);
    }

    cout << "-------------------------------" << endl << "Highest Department Avg Salary: " << maxAvgSalary << endl;

    cout << endl << "Deallocating memory" << endl;
    delete[] employeeCount;
    for(int deptIdx = 0; deptIdx < deptCount; deptIdx++) {
        delete[] payroll[deptIdx];
    }
    delete[] payroll;

}
