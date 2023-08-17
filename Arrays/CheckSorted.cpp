#include <iostream>
using namespace std;
bool checkSorted(int arr[], int n)
{

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
            return false;
    }

    return true;
}
int main()
{
    int arr[] = {2, 54};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << checkSorted(arr, n);
    return 0;
}