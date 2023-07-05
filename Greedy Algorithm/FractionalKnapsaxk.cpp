#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool myCamp(pair<int, int> p1, pair<int, int> p2)
{
    double r1 = (double)p1.second / p1.first;
    double r2 = (double)p2.second / p2.first;
    return r1 > r2;
}
double knapSack(vector<pair<int, int>> &arr, int capacity)
{

    sort(arr.begin(), arr.end(), myCamp);
    double res = 0.0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i].first <= capacity)
        {
            res += arr[i].second;
            capacity -= arr[i].first;
        }
        else
        {
            res += (arr[i].second) * ((double)capacity / arr[i].first);
            break;
        }
    }
    return res;
}
int main()
{
    vector<pair<int, int>> arr = {{50, 600}, {20, 500}, {30, 400}};

    cout << knapSack(arr, 70);
    return 0;
}