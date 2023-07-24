#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool myCamp(pair<int, int> p1, pair<int, int> p2)
{
    return p1.second > p2.second;
}
void jobSeq(vector<pair<int, int>> &job)
{
    int n = job.size();
    sort(job.begin(), job.end(), myCamp);

    vector<int> result(n);
    vector<bool> slot(n, false);

    for (int i = 0; i < n; i++)
    {
        for (int j = min(n, job[i].first) - 1; j >= 0; j--)
        {
            if (slot[j] == false)
            {
                result[j] = i;
                slot[j] = true;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++)
        if (slot[i])
            cout << job[result[i]].second << " ";
}
int main()
{
    vector<pair<int, int>> job = {{2, 100}, {1, 50}, {2, 10}, {1, 20}, {3, 30}};

    jobSeq(job);
    return 0;
}