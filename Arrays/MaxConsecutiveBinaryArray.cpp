#include <iostream>
#include <vector>
using namespace std;

int MaxConsBinaryArrayNaive(vector<int> &arr, int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int temp = 0;
        while (arr[i] == 1)
        {
            temp++;
            i++;
        }

        res = max(res, temp);
    }

    return res;
}
int MaxConsBinaryArray(vector<int> &arr, int n)
{
    int res = 0;
    int curr = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            curr = 0;
        }
        else
        {

            curr++;
            res = max(res, curr);
        }
    }

    return res;
}

int main()
{
    vector<int> arr = {1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1};
    int n = arr.size();
    cout << MaxConsBinaryArray(arr, n);
    return 0;
}