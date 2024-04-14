#include <iostream>
using namespace std;
int partition(int arr[], int s, int e, int pivot)
{
    int index = s;
    for (int i = s; i <= e; i++)
    {
        if (arr[i] <= pivot)
        {
            swap(arr[index], arr[i]);
            index++;
        }
    }
    index--;
    return index;
}
void quickSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int pivot = arr[end];
        int p = partition(arr, start, end, pivot);
        quickSort(arr, start, p - 1);
        quickSort(arr, p + 1, end);
    }
}

int main()
{
    int arr[] = {8, 7, 6, 5, 4, 3, 2, 1};
    int n = 8;
    quickSort(arr, 0, n - 1);
    cout << "Sorted array is :" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}