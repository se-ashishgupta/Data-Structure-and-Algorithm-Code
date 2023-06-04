#include <iostream>
#include <unordered_set>
#include <unordered_map>
using namespace std;
bool count(int arr[], int n, int sum)
{
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
        if (s.find(sum - arr[i]) != s.end())
            return true;
        else
            s.insert(arr[i]);
    }
    return false;
}

bool countNaive(int arr[], int n, int sum)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == sum)
                return true;
        }
    }
    return false;
}
int main()
{
    int arr[] = {11, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    int sum = 10;
    cout << countNaive(arr, size, sum);
    return 0;
}