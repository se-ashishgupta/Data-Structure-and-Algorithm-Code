#include <iostream>
#include <vector>
using namespace std;

vector<int> ldsTab(vector<int> arr) // Tc=O(n*n)  AS=O(n)
{
    int n = arr.size();
    vector<int> lds(n);

    lds[n - 1] = 1;

    for (int i = n - 2; i >= 0; i--)
    {
        lds[i] = 1;
        for (int j = n - 1; j > i; j--)
        {
            if (arr[j] < arr[i])
                lds[i] = max(lds[i], lds[j] + 1);
        }
    }

    return lds;
}

vector<int> lisTab(vector<int> arr) // Tc=O(n*n)  AS=O(n)
{
    int n = arr.size();
    vector<int> lis(n);

    lis[0] = 1;

    for (int i = 1; i < n; i++)
    {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
                lis[i] = max(lis[i], lis[j] + 1);
        }
    }

    return lis;
}

int bitonicSub(vector<int> arr) // TC:O(n*n) AS:O(n)
{
    vector<int> lis = lisTab(arr);
    vector<int> lds = ldsTab(arr);

    int res = 0;
    for (int i = 0; i < arr.size(); i++)
    {

        res = max(res, (lis[i] + lds[i] - 1));
    }
    return res;
}

int main()
{
    vector<int> arr = {1, 11, 2, 10, 4, 5, 2, 1};

    cout << bitonicSub(arr);
    return 0;
}
