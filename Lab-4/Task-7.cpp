#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    int s = 1000;
    int array1[1000], array2[1000];

    srand(time(0));
    for(int i = 0; i < s; i++)
    {
        int val = rand() % 10000;
        array1[i] = val;
        array2[i] = val;
    }

    int swaps = 0;

    swaps = 0;
    for(int gap = s/2; gap > 0; gap /= 2)
    {
        for(int i = gap; i < s; i++)
        {
            int a = array1[i];
            int j = i;
            while(j >= gap && array1[j - gap] > a)
            {
                array1[j] = array1[j - gap];
                j -= gap;
                swaps++;
            }
            array1[j] = a;
        }
    }
    int shellSwaps = swaps;
    swaps = 0;
    for(int i = 1; i < s; i++)
    {
        int a = array2[i];
        int j = i - 1;
        while(j >= 0 && array2[j] > a)
        {
            array2[j + 1] = array2[j];
            j--;
            swaps++;
        }
        array2[j + 1] = a;
    }
    int insertionSwaps = swaps;

    cout << "Shell Sort swaps: " << shellSwaps << endl;
    cout << "Insertion Sort swaps: " << insertionSwaps << endl;

    return 0;
}
