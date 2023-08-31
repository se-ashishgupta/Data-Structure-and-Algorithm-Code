#include <iostream>
#include <vector>
using namespace std;

void PrefisSum(vector<int> &arr, int n)
{

    for (int i = 1; i < n; i++)
    {

        arr[i] = arr[i - 1] + arr[i];
    }
}

int main()
{
    vector<int> arr = {1, 8, 30, -5, 20, 7};
    int n = arr.size();
    PrefisSum(arr, n);

    for (int &x : arr)
    {
        cout << x << " ";
    }
    return 0;
}
