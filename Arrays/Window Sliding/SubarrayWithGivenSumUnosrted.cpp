#include <iostream>
#include <vector>
using namespace std;

int SubarrayWithGivenSumUnosrtedNaive(vector<int> &arr, int n, int k)
{

    for (int i = 0; i < n; i++)
    {
        int currSum = 0;
        for (int j = i; j < n; j++)
        {
            currSum += arr[j];
            if (currSum == k)
                return true;
        }
    }

    return false;
}
int SubarrayWithGivenSumUnosrted(vector<int> &arr, int n, int k)
{

    int currSum = arr[0], s = 0;
    for (int i = 1; i < n; i++)
    {
        while (currSum > k && s < i - 1)
        {
            currSum -= arr[s];
            s++;
        }
        if (currSum == k)
            return true;

        if (i < n)
        {
            currSum += arr[i];
        }
    }

    return currSum == k;
}

int main()
{
    vector<int> arr = {1, 4, 20, 2, 10, 5};
    int n = arr.size();
    int k = 33;
    cout << SubarrayWithGivenSumUnosrted(arr, n, k);
    return 0;
}
