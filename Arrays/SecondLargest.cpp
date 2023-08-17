#include <iostream>
using namespace std;
int secondLargest(int arr[], int n)
{
    int firstLargest = 0, secondLargest = -1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[firstLargest])
        {
            secondLargest = firstLargest;
            firstLargest = i;
        }
        else if (arr[i] != arr[firstLargest])
        {

            if (secondLargest == -1 || arr[i] > arr[secondLargest])
            {
                secondLargest = i;
            }
        }
    }

    return arr[secondLargest];
}
int main()
{
    int arr[] = {2, 54, 15, 88, 99, 12, 25, 88, 90, 100};
    int n = 10;
    cout << secondLargest(arr, n);
    return 0;
}