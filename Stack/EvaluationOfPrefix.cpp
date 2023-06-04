#include <iostream>
#include <string>
#include <stack>
using namespace std;

int evaluatePostfix(string S)
{
    // Your code here
    stack<int> s;
    for (int i = S.length() - 1; i >= 0; i--)
    {
        if (S[i] >= 48 && S[i] <= 57)
            s.push(S[i] - 48);
        else
        {

            int op1 = s.top();
            s.pop();
            int op2 = s.top();
            s.pop();

            if (S[i] == '+')
            {
                s.push(op1 + op2);
            }
            else if (S[i] == '-')
            {
                s.push(op1 - op2);
            }
            else if (S[i] == '*')
            {
                s.push(op1 * op2);
            }
            else if (S[i] == '/')
            {
                s.push(op1 / op2);
            }
        }
    }

    return s.top();
}
int main()
{
    string s = "*+123";
    cout << evaluatePostfix(s);
    return 0;
}