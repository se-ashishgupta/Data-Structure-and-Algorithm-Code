#include <iostream>
using namespace std;
struct MyStack
{
    int *arr;
    int cap;
    int top;
    MyStack(int c)
    {
        cap = c;
        arr = new int[cap];
        top = -1;
    }
    void push(int x)
    {
        if (top == cap - 1)
        {
            cout << "Overflow" << endl;
            ;
        }
        else
        {
            top++;
            arr[top] = x;
        }
    }
    int pop()
    {
        if (top == -1)
        {
            cout << "Underflow" << endl;
        }
        else
        {
            int res = arr[top];
            top--;
            return res;
        }
    }
    int peek()
    {
        if (top == -1)
        {
            cout << "Empty Stack" << endl;
        }
        else
        {

            return arr[top];
        }
    }
    int size()
    {
        return top + 1;
    }
    bool isEmpty()
    {
        return (top == -1);
    }
};

int main()
{
    MyStack s(3);
    s.pop();
    s.peek();
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.size();
}