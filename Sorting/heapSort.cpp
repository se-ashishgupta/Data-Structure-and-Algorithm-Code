#include <iostream>
using namespace std;

// TC of buildheap is O(n)

void maxHeapify(int arr[], int n, int i)
{
    int largest = i, left = 2 * i + 1, right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        maxHeapify(arr, n, largest);
    }
}
void buildHeap(int arr[], int n)
{
    for (int i = (n - 2) / 2; i >= 0; i--)
    {
        maxHeapify(arr, n, i);
    }
}
void heapSort(int arr[], int n)
{
    buildHeap(arr, n);
    for (int i = n - 1; i >= 1; i--)
    {
        swap(arr[0], arr[i]);
        maxHeapify(arr, i, 0);
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int a[] = {10, 15, 50, 4, 20};
    int n = sizeof(a) / sizeof(a[0]);

    heapSort(a, n);
    return 0;
}

// uses concept of heap sort and it takes O(nlogn) in all cases time while selkection sort takes O(n2)
// Mearge sort and quick sort takes less time then heap sort in practical thats why mrage and quick sort uses more

//