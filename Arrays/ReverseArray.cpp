#include <iostream>
#include <vector>
using namespace std;
void reverse(vector<int> &arr, int n)
{

    int l = 0, h = n - 1;
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
int main()
{
    vector<int> arr = {2, 54, 12, 15};
    int n = arr.size();
    reverse(arr, n);
    for (int &x : arr)
        cout
            << x << " ";
    return 0;
}