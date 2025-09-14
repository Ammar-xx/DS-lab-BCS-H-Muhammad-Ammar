#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter the number of elements: ";
    cin >> size;

    int a[100];
    cout << "Enter " << size << " elements: ";
    for(int i = 0; i < size; i++) {
        cin >> a[i];
    }


    for(int i = 1; i < size; i++) {
        int j = i - 1;
        int x = a[i];
        while(j >= 0 && a[j] > x) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = x;
    }


    int target;
    cout << "Enter element to search: ";
    cin >> target;

    int start = 0;
    int end = size - 1;
    int index = -1;

    while(start <= end) {
        if(a[start] == a[end]) {
            if(a[start] == target) {
                index = start;
            }
            break;
        }
        int pos = start + (((target - a[start]) * (end - start)) / (a[end] - a[start]));

        if(a[pos] == target) {
            index = pos;
            break;
        } else if(a[pos] > target) {
            end = pos - 1;
        } else {
            start = pos + 1;
        }
    }
    cout << "\nSorted Array: ";
    for(int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    if(index != -1) {
        cout << "Element found at index: " << index << endl;
    } else {
        cout << "Element not found!" << endl;
    }

    return 0;
}
