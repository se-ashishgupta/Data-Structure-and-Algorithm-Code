#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool myCamp(pair<int, int> p1, pair<int, int> p2)
{
    return p1.second < p2.second;
}
int activitySelection(vector<pair<int, int>> &activity)
{

    sort(activity.begin(), activity.end(), myCamp);
    int prev = 0, res = 1;

    for (int curr = 1; curr < activity.size(); curr++)
    {

        if (activity[prev].second <= activity[curr].first)
        {
            res++;
            prev = curr;
        }
    }
    return res;
}
int main()
{
    vector<pair<int, int>> activity = {{2, 3}, {1, 4}, {5, 8}, {6, 10}};

    cout << activitySelection(activity);
    return 0;
}