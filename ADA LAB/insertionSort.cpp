// INSERTION SORT

#include <iostream>
using namespace std;
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            swap(arr[j + 1], arr[j]);
            j--;
        }
        arr[j + 1] = temp;
    }
}
int main()
{
    int arr[] = {10, 21, 3, 204, 1, 34, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Original array:\n ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    clock_t start, end;
    start = clock();
    cout << "\nSorted array:\n";
    insertionSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "\nTime spent is " << time_spent << endl;
    return 0;
}