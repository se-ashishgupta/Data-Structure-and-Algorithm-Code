#include <iostream>
#include <vector>
#include <unordered_map>
#include <math.h>
using namespace std;

void FreqInSortedArray(vector<int> &arr, int n) // Naive
{
    int f = 1, i = 1;
    while (i < n)
    {

        while (i < n && arr[i - 1] == arr[i])
        {
            f++;
            i++;
        }
        cout << arr[i - 1] << " " << f << endl;
        i++;
        f = 1;
    }
    if (n == 1 || arr[n - 1] != arr[n - 2])
    {
        cout << arr[n - 1] << " " << 1 << endl;
    }
}
void FreqInSortedArrayVector(vector<int> &arr, int n) // Naive
{
    unordered_map<int, int> mp;

    for (int &x : arr)
    {
        mp[x]++;
    }

    for (auto &x : mp)
    {
        cout << x.first << " " << x.second << endl;
    }
}

int main()
{
    vector<int> arr = {10, 10, 10, 30, 30, 40};
    int n = arr.size();
    FreqInSortedArrayVector(arr, n);
    return 0;
}