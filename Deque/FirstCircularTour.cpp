#include <iostream>
#include <deque>
using namespace std;
int FirstTourNaive(int petrol[], int dist[], int n) // TC: O(n*n)  AS:O(1)
{

    for (int start = 0; start < n; start++)
    {
        int curr_pet = 0;
        int end = start;
        while (true)
        {
            curr_pet += (petrol[end] - dist[end]);
            if (curr_pet < 0)
                break;
            end = (end + 1) % n;
            if (end == start)
                return (start + 1);
        }
    }
}
int FirstTour(int petrol[], int dist[], int n) // TC: O(n)  AS:O(n)
{
    deque<int> dq;
}
int FirstTour1(int petrol[], int dist[], int n) // TC: O(n)  AS:O(1)
{
    int start = 0, curr_pet = 0, prev_pet = 0;
    for (int i = 0; i < n; i++)
    {
        curr_pet += (petrol[i] - dist[i]);
        if (curr_pet < 0)
        {
            start = i + 1;
            prev_pet += curr_pet;
            curr_pet = 0;
        }
    }
    return ((curr_pet + prev_pet) > 0) ? (start + 1) : -1;
}

int main()
{
    int petrol[] = {50, 10, 60, 100};
    int dist[] = {30, 20, 100, 10};
    int n = 4;
    cout << FirstTourNaive(petrol, dist, n);
    return 0;
}