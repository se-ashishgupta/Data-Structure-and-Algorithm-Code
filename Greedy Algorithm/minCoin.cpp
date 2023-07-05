#include <iostream>
#include <algorithm>
using namespace std;

int minCoin(int arr[], int n, int amount)
{
    sort(arr, arr + n);
    reverse(arr, arr + n);

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= amount)
        {
            int c = amount / arr[i];
            res = res + c;
            amount = amount - c * arr[i];
        }
        if (amount == 0)
            break;
    }
    return res;
}
int main()
{
    int arr[] = {5, 10, 2, 1};
    cout << minCoin(arr, 4, 57);
    return 0;
}