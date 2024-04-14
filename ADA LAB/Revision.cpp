#include <iostream>
using namespace std;
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[minIdx] > arr[j])
            {
                minIdx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;
    }
}
int main()
{
    int arr[] = {10, 21, 0, 1, 22, 23, 1, 2, 5, 6, 3, 8, 7, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Original array is : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\nSorted array is : ";
    clock_t start, end;
    start = clock();
    selectionSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "\nTime spent is : " << time_spent << endl;
    return 0;
}