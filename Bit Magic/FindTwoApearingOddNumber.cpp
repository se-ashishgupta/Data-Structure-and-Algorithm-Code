#include <iostream>
#include <vector>
using namespace std;

void OddApNoNaive(vector<int> arr) // O(n)
{

    for (int y : arr)
    {
        int count = 0;
        for (int x : arr)
        {
            if (y == x)
                count++;
        }
        if (count % 2 == 1)
            cout << y << " ";
    }
}
void OddApNo(vector<int> arr) // O(n)
{

    int x = 0, res1 = 0, res2 = 0;
    for (int y : arr)
    {
        x = x ^ y;
    }

    int sn = x & ~(x - 1); // find rightmost set bit

    for (int y : arr)
    {
        if (y & sn != 0)
            res1 = res1 ^ y;
        else
            res2 = res2 ^ y;
    }

    cout << res1 << " " << res2;
}

int main()
{
    vector<int> arr = {3, 4, 3, 4, 5, 4, 4, 6, 7, 7};
    OddApNoNaive(arr);
    return 0;
}