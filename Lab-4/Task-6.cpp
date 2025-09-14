#include <iostream>
using namespace std;

int main()
{
    int s;
    cout << "Enter the size of the array\n";
    cin >> s;

    int array[100];
    for(int i = 0; i < s; i++)
    {
        cout << "Enter the element at the " << i + 1 << " position\n";
        cin >> array[i];
    }

    int gap = s;
    float shrink = 1.3;
    bool swapped = true;
    int comparisons = 0, swaps = 0;

    while(gap > 1 || swapped)
    {
        gap = int(gap / shrink);
        if(gap < 1) gap = 1;

        swapped = false;

        for(int i = 0; i + gap < s; i++)
        {
            comparisons++;
            if(array[i] > array[i + gap])
            {
                int temp = array[i];
                array[i] = array[i + gap];
                array[i + gap] = temp;
                swaps++;
                swapped = true;
            }
        }
    }

    cout << "Sorted array\n";
    for(int i = 0; i < s; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    cout << "Total comparisons: " << comparisons << endl;
    cout << "Total swaps: " << swaps << endl;

    return 0;
}
