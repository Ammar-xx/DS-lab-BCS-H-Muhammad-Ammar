#include <iostream>
using namespace std;

int main() {
    int rowCount, colCount;
    cout << "Enter number of rows: ";
    cin >> rowCount;
    cout << "Enter number of columns: ";
    cin >> colCount;

    int** dataMatrix = new int*[rowCount];
    for (int i = 0; i < rowCount; i++) {
        dataMatrix[i] = new int[colCount];
    }

    cout << "Enter elements of the matrix" << endl;
    for (int i = 0; i < rowCount; i++) {
        cout << "Row " << i << " :" << endl;
        for (int j = 0; j < colCount; j++) {
            cout << "Col " << j << ": ";
            cin >> dataMatrix[i][j];
        }
        cout << endl;
    }

    cout << "Displaying matrix in normal form" << endl;
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            cout << dataMatrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Displaying matrix in compressed form ([row][col]: value) - only for non-zero value" << endl;
    int zeroCount = 0;
    for(int i = 0; i < rowCount; i++) {
        for(int j = 0; j < colCount; j++) {
            if(dataMatrix[i][j] != 0) {
                cout << "[" << i << "]" << "[" << j << "]:" << dataMatrix[i][j] << endl;
            } else {
                zeroCount++;
            }
        }
    }
    cout << endl << "Rows: " << rowCount << ", Cols: " << colCount << " | Zeros: " << zeroCount << endl;

    cout << "Deallocating memory." << endl;
    for (int i = 0; i < rowCount; i++) {
        delete[] dataMatrix[i];
    }
    delete[] dataMatrix;
}
