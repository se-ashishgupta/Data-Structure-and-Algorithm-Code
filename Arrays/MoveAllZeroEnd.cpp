#include <iostream>
#include <vector>
using namespace std;
void moveAllZeroEnd(vector<int> &arr, int n)
{

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[count]);
            count++;
        }
    }
}
int main()
{
    vector<int> arr = {2, 0, 0, 54, 12, 15, 15};
    int n = arr.size();
    moveAllZeroEnd(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}