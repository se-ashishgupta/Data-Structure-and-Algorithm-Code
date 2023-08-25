#include <iostream>
#include <vector>
#include <unordered_map>
#include <math.h>
using namespace std;

int BuyStockProblemNaive(vector<int> &arr, int start, int end) // Naive
{

    if (end <= start)
        return 0;

    int profit = 0;

    for (int i = start; i < end; i++)
    {

        for (int j = i + 1; j <= end; j++)
        {

            if (arr[j] > arr[i])
            {
                int curr_profit = arr[j] - arr[i] + BuyStockProblemNaive(arr, start, i - 1) + BuyStockProblemNaive(arr, j + 1, end);

                profit = max(curr_profit, profit);
            }
        }
    }

    return profit;
}
int BuyStockProblem(vector<int> &arr, int n)
{
    int profit = 0;

    for (int i = 1; i < n; i++)
    {
        if (arr[i - 1] < arr[i])
        {
            profit += arr[i] - arr[i - 1];
        }
    }

    return profit;
}

int main()
{
    vector<int> arr = {1, 5, 3, 8, 12};
    int n = arr.size();
    // cout << BuyStockProblem(arr, n);
    cout << BuyStockProblemNaive(arr, 0, n - 1);
    return 0;
}