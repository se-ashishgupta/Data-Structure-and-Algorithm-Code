#include <iostream>
#include <vector>
using namespace std;
int removeDuplicates(vector<int> &arr, int n)
{

    int res = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] != arr[i - 1])
        {
            arr[res] = arr[i];
            res++;
        }
    }
    return res;
}
int main()
{
    vector<int> arr = {2, 2, 2, 54, 12, 15, 15};
    int n = arr.size();
    int res = removeDuplicates(arr, n);
    for (int i = 0; i < res; i++)
    {
        cout << arr[i] << " ";
    }

       return 0;
}