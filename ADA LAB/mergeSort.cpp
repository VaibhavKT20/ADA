// MERGE SORT
#include <iostream>
using namespace std;
void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int l[n1], r[n2];
    for (int i = 0; i < n1; i++)
    {
        l[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++)
    {
        r[i] = arr[mid + 1 + i];
    }
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (l[i] <= r[j])
        {
            arr[k] = l[i];
            i++;
        }
        else
        {
            arr[k] = r[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = l[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = r[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int left, int right)
{
    int mid;
    if (left < right)
    {
        mid = (right + left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
int main()
{
    int arr[] = {8, 7, 6, 5, 4, 3, 2, 1};
    int n = 8;
    mergeSort(arr, 0, n - 1);
    cout << " Sorted array is :\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}