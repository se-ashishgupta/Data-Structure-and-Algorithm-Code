#include <iostream>
#include <unordered_set>
#include <unordered_map>
using namespace std;
void frequency(int arr[], int n)
{
    unordered_map<int, int> m;
    // for (int i = 0; i < n; i++)
    // {
    //     if (m.find(arr[i]) == m.end())
    //         m.insert({arr[i], 1});
    //     else
    //         m[arr[i]]++;
    // }

    for (int i = 0; i < n; i++)
    {
        m[arr[i]]++;
    }

    for (auto x : m)
        cout << x.first << " " << x.second << endl;
}

void frequencyNaive(int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        bool flag = false;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] == arr[j])
            {
                flag = true;
                break;
            }
        }
        if (flag == true)
        {
            continue;
        }
        int freq = 1;
        for (int k = i + 1; k < n; k++)
        {
            if (arr[i] == arr[k])
            {
                freq++;
            }
        }

        cout << arr[i] << " " << freq << endl;
    }
}
int main()
{
    int arr[] = {50, 50, 10, 40, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    frequency(arr, size);

    return 0;
}