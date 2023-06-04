#include <iostream>
#include <queue>
using namespace std;
struct Stack
{
    queue<int> q1, q2;
    int top()
    {
        return q1.front();
    }
    int size()
    {
        return q1.size();
    }
    int pop()
    {
        return q1.front();
    }
    void push(int x)
    {
        while (q1.empty() == false)
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);
        while (q2.empty() == false)
        {
            q1.push(q2.front());
            q2.pop();
        }
    }
};

int main()
{
    return 0;
}