#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;
struct Interval
{
    int st, end;
};
int myCamp(Interval p1, Interval p2)
{
    return p1.st < p2.st;
}

void mergeIntervals(Interval arr[], int n)
{
    sort(arr, arr + n, myCamp);
    int res = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[res].end >= arr[i].st)
        {
            arr[res].end = max(arr[res].end, arr[i].end);
            arr[res].st = min(arr[res].st, arr[i].st);
        }
        else
        {
            res++;
            arr[res] = arr[i];
        }
    }

    for (int i = 0; i <= res; i++)
    {
        cout << "{" << arr[i].st << "," << arr[i].end << "}" << endl;
    }
}

// void NaivemergeIntervals(vector<pair<int, int>> &p)
// {

//     for (auto i = p.begin(); i != p.end(); i++)
//     {

//         for (auto j = p.begin(); j != p.end(); j++)
//         {

//             if ((*i).first <= (*j).first)
//             {

//                 (*i).first = min((*i).first, (*j).first);
//                 (*i).second = max((*i).second, (*j).second);
//                 p.erase(j);
//             }
//         }
//     }

//     for (auto x : p)
//         cout << "{" << x.first << "," << x.second << "}" << endl;
// }
int main()
{
    Interval arr[] = {{5, 10}, {2, 3}, {6, 8}, {1, 7}};
    vector<pair<int, int>> p = {{5, 10}, {2, 3}, {6, 8}, {1, 7}};
    mergeIntervals(arr, 4);
    // NaivemergeIntervals(p);

    return 0;
}