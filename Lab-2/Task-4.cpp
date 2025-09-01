#include <iostream>
using namespace std;

class ExpenseTracker {
    private:
        int* monthlyCosts;
        int count;
    public:
        ExpenseTracker(int months) : count(months) {
            monthlyCosts = new int[count];
            cout << "Enter monthly expenses" << endl;
            for(int idx = 0; idx < count; idx++) {
                cout << "Month " << idx + 1 << ": ";
                cin >> monthlyCosts[idx];
            }
            cout << endl;
        }
        void ExtendMonths(int additionalMonths) {
            int* oldCosts = monthlyCosts;
            monthlyCosts = new int[count + additionalMonths];
            for(int idx = 0; idx < count; idx++) {
                monthlyCosts[idx] = oldCosts[idx];
            }
            cout << "Enter monthly expenses for new months added (" << count << "-" << count + additionalMonths << ")" << endl;
            for(int idx = count; idx < count + additionalMonths; idx++) {
                cout << "Month " << idx + 1 << ": ";
                cin >> monthlyCosts[idx];
            }
            cout << endl;
            delete[] oldCosts;
            count += additionalMonths;
        }

        void ShowExpenses() {
            int sum = 0;
            cout << "Displaying expenses: " << endl;
            for (int idx = 0; idx < count; idx++) {
                cout << "Month " << idx + 1 << ": " << monthlyCosts[idx] << endl;
                sum += monthlyCosts[idx];
            }
            cout << "---------------------------" << endl;
            cout << "Total: " << sum << " | Average: " << (float)sum / count << endl;
        }

        ~ExpenseTracker() {
            delete[] monthlyCosts;
        }
};

int main() {
    ExpenseTracker tracker(3);
    tracker.ShowExpenses();

    tracker.ExtendMonths(2);
    tracker.ShowExpenses();
}
