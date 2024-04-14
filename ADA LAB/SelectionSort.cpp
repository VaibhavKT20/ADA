#include <iostream>
using namespace std;
void SelectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[minIndex] > arr[j])
            {
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}
int main()
{
    int arr[] = {29, 322, 12, 43, 25, 65, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Original array is :\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    clock_t start, end;
    start = clock();
    cout << "\nSorted Array is: \n";
    SelectionSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "\nTime taken :" << time_spent << endl;
    return 0;
}
