#include <iostream>
#include <stack>
using namespace std;

void printSpanNaive(int arr[], int n) // O(n*n)
{
    for (int i = 0; i < n; i++)
    {
        int span = 1;
        for (int j = i - 1; j >= 0 && arr[j] <= arr[i]; j--)
            span++;
        cout << span << " ";
    }
}
void printSpan(int arr[], int n) // O(n*n)
{
    stack<int> s;
    s.push(0);
    cout << 1 << " ";
    for (int i = 1; i < n; i++)
    {
        while (s.empty() == false && arr[s.top()] <= arr[i])
            s.pop();
        int span = s.empty() ? i + 1 : i - s.top();
        cout << span << " ";
        s.push(i);
    }
}
 
int main()
{
    int arr[] = {13, 15, 12, 14, 16, 8, 6, 4, 10, 30};
    int n = 10;
    printSpan(arr, n);
    return 0;
}