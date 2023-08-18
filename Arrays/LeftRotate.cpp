#include <iostream>
#include <vector>
using namespace std;
void leftRotate(vector<int> &arr, int n)
{

    int temp = arr[0];
    for (int i = 1; i < n; i++)
    {
        arr[i - 1] = arr[i];
    }
    arr[n - 1] = temp;
}
int main()
{
    vector<int> arr = {2, 0, 0, 54, 12, 15, 15};
    int n = arr.size();
    leftRotate(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}