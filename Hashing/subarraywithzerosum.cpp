#include <iostream>
#include <unordered_set>
#include <unordered_map>
using namespace std;
bool SubArraywithSumZero(int arr[], int n) // O(n)
{
    unordered_set<int> s;
    int prefSum = 0;
    for (int i = 0; i < n; i++)
    {
        prefSum += arr[i];
        if (s.find(prefSum - 0) != s.end())
            return true;
        if (prefSum == 0)
            return true;
        s.insert(prefSum);
    }
    return false;
}

bool SubArraywithSumZeroNaive(int arr[], int n) // O(n*n)
{
    for (int i = 0; i < n; i++)
    {
        int curr = 0;
        for (int j = i; j < n; j++)
        {
            curr += arr[j];

            if (curr == 0)
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int arr[] = {1, 4, 13, -3, -10, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << SubArraywithSumZeroNaive(arr, size);
    return 0;
}