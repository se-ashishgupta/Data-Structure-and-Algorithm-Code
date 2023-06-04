#include <iostream>
#include <stack>
using namespace std;
void printPrevGratNaive(int arr[], int n) // TC: O(n*n)
{
    for (int i = 0; i < n; i++)
    {
        int j;
        for (j = i - 1; j >= 0; j--)
        {
            if (arr[j] > arr[i])
            {
                cout << arr[j] << " ";
                break;
            }
        }
        if (j == -1)
            cout << -1 << " ";
    }
}
void printPrevGrat(int arr[], int n) // TC: O(n)
{
    stack<int> s;
    cout << -1 << " ";
    s.push(arr[0]);
    for (int i = 1; i < n; i++)
    {
        while (s.empty() == false && s.top() <= arr[i])
        {
            s.pop();
        }
        int pg = s.empty() ? -1 : s.top();
        cout << pg << " ";
        s.push(arr[i]);
    }
}
int main()
{
    int arr[] = {6, 2, 5, 4, 1, 5, 6};
    int n = 7;
    printPrevGrat(arr, n);
    return 0;
}
