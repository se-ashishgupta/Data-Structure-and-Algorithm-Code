#include <iostream>
#include <vector>
using namespace std;

int MaxSumSub(vector<int> arr) // Tc=O(n*n)  AS=O(n)
{
    int n = arr.size();
    vector<int> msin(n);

    for (int i = 0; i < n; i++)
    {
        msin[i] = arr[i];
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
                msin[i] = max(msin[i], msin[j] + arr[i]);
        }
    }

    int res = msin[0];
    for (int x : msin)
        res = max(res, x);

    return res;
}

int main()
{
    vector<int> arr = {3, 20, 4, 6, 7, 30};
    cout << MaxSumSub(arr);
    return 0;
}
