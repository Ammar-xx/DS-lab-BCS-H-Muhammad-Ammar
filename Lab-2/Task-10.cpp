#include <iostream>
using namespace std;

class Library {

    private:
        int** bookCollection;
        int categoryCount;
        int* bookCount;
        string* categoryNames;

    public:
        Library(int n) {
            categoryCount = n;
            bookCollection = new int*[categoryCount];
            bookCount = new int[categoryCount];
            categoryNames = new string[categoryCount];

            for (int i = 0; i < categoryCount; i++) {
                cout << "Enter name of category " << i + 1 << ": ";
                cin >> categoryNames[i];

                cout << "Enter number of books in " << categoryNames[i] << ": ";
                cin >> bookCount[i];

                bookCollection[i] = new int[bookCount[i]];
                cout << "Enter book IDs for " << categoryNames[i] << endl;
                for (int j = 0; j < bookCount[i]; j++) {
                    cout << "  Book " << j + 1 << ": ";
                    cin >> bookCollection[i][j];
                }
            }
        }

        void findBook(int id) {
            for (int i = 0; i < categoryCount; i++) {
                for (int j = 0; j < bookCount[i]; j++) {
                    if (bookCollection[i][j] == id) {
                        cout << "Book with ID " << id << " found in category " << categoryNames[i] << endl;
                        return;
                    }
                }
            }
            cout << "Book " << id << " not found in library records." << endl;
        }

        ~Library() {
            cout << "Deallocating memory." << endl;
            for (int i = 0; i < categoryCount; i++) {
                delete[] bookCollection[i];
            }
            delete[] bookCollection;
            delete[] bookCount;
            delete[] categoryNames;
        }
};

int main() {
    int categoryCount;
    cout << "Enter number of categories: ";
    cin >> categoryCount;

    Library lib(categoryCount);

    int searchID;
    cout << "Enter Book ID to search: ";
    cin >> searchID;

    lib.findBook(searchID);

    return 0;
}
