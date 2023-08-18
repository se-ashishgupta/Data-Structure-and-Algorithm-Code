#include <iostream>
#include <vector>
using namespace std;

// {Method 1}
void leftRotateByOne(vector<int> &arr, int n)
{

    int temp = arr[0];
    for (int i = 1; i < n; i++)
    {
        arr[i - 1] = arr[i];
    }
    arr[n - 1] = temp;
}
void leftRotatebyDNaive(vector<int> &arr, int n, int d)
{
    for (int i = 0; i < d; i++)
    {
        leftRotateByOne(arr, n);
    }
}

// {Method 2}
void leftRotatebyD(vector<int> &arr, int n, int d)
{
    vector<int> temp;

    for (int i = 0; i < d; i++)
    {
        temp.push_back(arr[i]);
    }

    // for (int i = 0; i < n - d; i++)
    // {
    //     arr[i] = arr[d + i];
    // }
    // or
    for (int i = d; i < n; i++)
    {
        arr[i - d] = arr[i];
    }

    for (int i = 0; i < d; i++)
    {
        arr[n - d + i] = temp[i];
    }
}

// {Method 3}
void reverse(vector<int> &arr, int l, int h)
{

    while (l < h)
    {
        // swap(arr[l], arr[h]);
        arr[l] = arr[l] + arr[h];
        arr[h] = arr[l] - arr[h];
        arr[l] = arr[l] - arr[h];
        l++;
        h--;
    }
}

void leftRotatebyDReversal(vector<int> &arr, int n, int d)
{
    reverse(arr, 0, d - 1);
    reverse(arr, d, n - 1);
    reverse(arr, 0, n - 1);
}

int main()
{
    vector<int> arr = {2, 0, 0, 54, 12, 15, 15};
    int n = arr.size();
    int d = 2;
    leftRotatebyDReversal(arr, n, d);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}