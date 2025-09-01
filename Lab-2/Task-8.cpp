#include <iostream>
using namespace std;

int main() {
    int dayCount, readingCount;
    cout << "Enter number of days: ";
    cin >> dayCount;
    cout << "Enter number of readings per day: ";
    cin >> readingCount;

    float** temperatures = new float*[dayCount];
    for (int i = 0; i < dayCount; i++) {
        temperatures[i] = new float[readingCount];
    }

    cout << endl << "Enter temperature readings" << endl;
    for (int i = 0; i < dayCount; i++) {
        cout << "Day " << i + 1 << ":" << endl;
        for (int j = 0; j < readingCount; j++) {
            cout << "  Reading " << j + 1 << ": ";
            cin >> temperatures[i][j];
        }
    }

    float* dailyAverages = new float[dayCount];
    for (int i = 0; i < dayCount; i++) {
        float total = 0;
        for (int j = 0; j < readingCount; j++) {
            total += temperatures[i][j];
        }
        dailyAverages[i] = total / readingCount;
    }

    int warmestDay = 0, coldestDay = 0;
    for (int i = 1; i < dayCount; i++) {
        if (dailyAverages[i] > dailyAverages[warmestDay]) warmestDay = i;
        if (dailyAverages[i] < dailyAverages[coldestDay]) coldestDay = i;
    }

    cout << endl << "Daily Average Temperatures" << endl;
    for (int i = 0; i < dayCount; i++) {
        cout << "Day " << i + 1 << ": " << dailyAverages[i] << endl;
    }

    cout << endl << "Warmest Day: Day " << warmestDay + 1 << " (Average = " << dailyAverages[warmestDay] << ")" << endl;
    cout << "Coldest Day: Day " << coldestDay + 1 << " (Average = " << dailyAverages[coldestDay] << ")" << endl;

    cout << "Deallocating memory." << endl;
    for (int i = 0; i < dayCount; i++) {
        delete[] temperatures[i];
    }
    delete[] temperatures;
    delete[] dailyAverages;
}
