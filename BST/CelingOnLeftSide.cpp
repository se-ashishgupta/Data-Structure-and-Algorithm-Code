#include <iostream>
#include <set>
using namespace std;
void ceilingOnLeftNaive(int arr[], int n) // TC: O(n*n)  AS:(1)
{
    cout << -1 << " ";

    for (int i = 1; i < n; i++)
    {
        int diff = INT16_MAX;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] >= arr[i])
            {
                diff = min(diff, arr[j] - arr[i]);
            }
        }
        if (diff == INT16_MAX)
            cout << -1 << " ";
        else
            cout << (arr[i] + diff) << " ";
    }
}
void ceilingOnLeft(int arr[], int n) // TC: O(n*log(n))  AS:(n)
{
    cout << -1 << " ";
    set<int> s;
    s.insert(arr[0]);
    for (int i = 1; i < n; i++)
    {
        if (s.lower_bound(arr[i]) != s.end())
        {
            cout << *(s.lower_bound(arr[i])) << " ";
        }
        else
            cout << -1 << " ";

        s.insert(arr[i]);
    }
}
int main()
{
    int arr[] = {2, 8, 30, 15, 25, 12};
    ceilingOnLeftNaive(arr, 6);
}