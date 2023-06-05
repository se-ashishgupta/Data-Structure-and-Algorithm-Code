#include <iostream>
using namespace std;

void maxHeapify(int arr[], int n, int i)
{
    int largest = i, left = 2 * i + 1, right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void buildHeap(int arr[], int n) // TC :O(n)
{
    for (int i = (n - 2) / 2; i >= 0; i--)
    {
        maxHeapify(arr, n, i);
    }
}

void heapSort(int arr[], int n)
{
    buildHeap(arr, n);
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        maxHeapify(arr, i, 0);
    }
}
int main() // TC :O(nlogn)
{
    int arr[] = {5, 1, 2, 58, 9};
    heapSort(arr, 5);
    for (int x : arr)
    {
        cout << x << " ";
    }
    return 0;
}
