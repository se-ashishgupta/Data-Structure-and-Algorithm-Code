#include <iostream>
#include <unordered_set>
#include <unordered_map>
using namespace std;
// Total no of window is n-k+1
void CountDistinctElementinEveryWindow(int arr[], int n, int k) // O(n)    AS:O(n)
{
    // for (int i = 0; i <= n - k; i++)
    // {
    //     unordered_set<int> s(arr + i, arr + i + k);
    //     cout << s.size() << " ";
    // }

    unordered_map<int, int> freq;
    for (int i = 0; i < k; i++)
    {
        freq[arr[i]]++;
    }
    cout << freq.size() << " ";
    for (int i = k; i < n; i++)
    {

        freq[arr[i - k]]--;
        if (freq[arr[i - k]] == 0)
            freq.erase(arr[i - k]);

        freq[arr[i]]++;
        cout << freq.size() << " ";
    }
}

void CountDistinctElementinEveryWindowNaive(int arr[], int n, int k) // O(n*n)
{
    for (int i = 0; i <= n - k; i++)
    {
        int count = 0;
        for (int j = 0; j < k; j++)
        {
            bool flag = false;
            for (int p = 0; p < j; p++)
            {
                if (arr[i + j] == arr[i + p])
                {
                    flag = true;
                    break;
                }
            }
            if (flag == false)
                count++;
        }
        cout << count << " ";
    }
}

int main()
{
    int arr[] = {10, 20, 10, 10, 30, 40};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k = 4;
    CountDistinctElementinEveryWindow(arr, size, k);
    return 0;
}