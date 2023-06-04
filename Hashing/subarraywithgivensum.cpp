#include <iostream>
#include <unordered_set>
#include <unordered_map>
using namespace std;
bool SubArraywithGivenSum(int arr[], int n, int sum) // O(n)
{
    unordered_set<int> s;
    int prefSum = 0;
    for (int i = 0; i < n; i++)
    {

        prefSum += arr[i];

        if (prefSum == sum)
            return true;

        if (s.find(prefSum - sum) != s.end())
            return true;
        s.insert(prefSum);
    }

    return false;
}

bool SubArraywithGivenSumNaive(int arr[], int n, int sum) // O(n*n)
{
    for (int i = 0; i < n; i++)
    {
        int curr = 0;
        for (int j = i; j < n; j++)
        {
            curr += arr[j];

            if (curr == sum)
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int arr[] = {1, 2, 4, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    int sum = 3;
    cout << SubArraywithGivenSum(arr, size, sum);
    return 0;
}