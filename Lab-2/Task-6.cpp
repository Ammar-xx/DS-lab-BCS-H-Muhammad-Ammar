#include <iostream>
using namespace std;

class ManagedPointer {
    private:
        int* ptr;
    public:
        ManagedPointer() {
            ptr = new int(0);
        }

        void assignValue(int value) {
            if(ptr) {
                *ptr = value;
            }
        }

        int retrieveValue() const {
            if (ptr) {
                return *ptr;
            } else {
                cerr << "Error: Pointer is null or already released" << endl;
                return 0;
            }
        }

        void free() {
            if (ptr != nullptr) {
                delete ptr;
                ptr = nullptr;
            }
        }

        ~ManagedPointer() {
            free();
        }
};

int main() {
    const int studentCount = 5;
    ManagedPointer studentMarks[studentCount];

    cout << "Enter marks for " << studentCount << " students" << endl;
    for (int idx = 0; idx < studentCount; idx++) {
        int mark;
        cout << "Student " << idx + 1 << ": ";
        cin >> mark;
        studentMarks[idx].assignValue(mark);
    }

    cout << "Displaying safely stored marks:" << endl;
    for (int idx = 0; idx < studentCount; idx++) {
        cout << "Student " << idx + 1 << ": " << studentMarks[idx].retrieveValue() << endl;
    }
}
