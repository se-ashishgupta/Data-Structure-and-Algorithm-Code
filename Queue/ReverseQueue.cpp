#include <iostream>
#include <queue>
#include <stack>
using namespace std;
void reverse(queue<int> &q)
{
    stack<int> s;
    while (q.empty() == false)
    {
        s.push(q.front());
        q.pop();
    }
    while (s.empty() == false)
    {
        q.push(s.top());
        s.pop();
    }
}
void reverse1(queue<int> &q)
{
    if (q.empty())
        return;
    int x = q.front();
    q.pop();
    reverse(q);
    q.push(x);
}

int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    reverse1(q);
    while (q.empty() == false)
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}