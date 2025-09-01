#include <iostream>
using namespace std;

int** generateMatrix(int rowCount, int colCount) {
    int** mat = new int*[rowCount];
    for (int i = 0; i < rowCount; i++) {
        mat[i] = new int[colCount];
    }
    return mat;
}

void populateMatrix(int** mat, int rowCount, int colCount, string label) {
    cout << "Enter values for " << label << ":" << endl;
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            cout << label << "[" << i << "][" << j << "]: ";
            cin >> mat[i][j];
        }
    }
}

void printMatrix(int** mat, int rowCount, int colCount) {
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int** addMatrices(int** matrix1, int** matrix2, int rowCount, int colCount) {
    int** result = generateMatrix(rowCount, colCount);
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return result;
}

int** subtractMatrices(int** matrix1, int** matrix2, int rowCount, int colCount) {
    int** result = generateMatrix(rowCount, colCount);
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    return result;
}

void releaseMatrix(int** mat, int rowCount) {
    for (int i = 0; i < rowCount; i++) {
        delete[] mat[i];
    }
    delete[] mat;
}

int main() {
    int rowCount, colCount;
    cout << "Enter number of rows: ";
    cin >> rowCount;
    cout << "Enter number of columns: ";
    cin >> colCount;

    int** matA = generateMatrix(rowCount, colCount);
    int** matB = generateMatrix(rowCount, colCount);

    populateMatrix(matA, rowCount, colCount, "Matrix A");
    populateMatrix(matB, rowCount, colCount, "Matrix B");

    cout << endl << "Matrix A" << endl;
    printMatrix(matA, rowCount, colCount);

    cout << endl << "Matrix B" << endl;
    printMatrix(matB, rowCount, colCount);

    int** sumMatrix = addMatrices(matA, matB, rowCount, colCount);
    cout << endl << "Addition (A + B)" << endl;
    printMatrix(sumMatrix, rowCount, colCount);

    int** diffMatrix = subtractMatrices(matA, matB, rowCount, colCount);
    cout << endl << "Subtraction (A - B)" << endl;
    printMatrix(diffMatrix, rowCount, colCount);

    releaseMatrix(matA, rowCount);
    releaseMatrix(matB, rowCount);
    releaseMatrix(sumMatrix, rowCount);
    releaseMatrix(diffMatrix, rowCount);

    return 0;
}
