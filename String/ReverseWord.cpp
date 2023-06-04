#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <stack>
using namespace std;
const int CHAR = 256;
void ReverseWord(string &str) // TC: O(n)   AS:O(1)
{
    int start = 0;
    for (int end = 0; end < str.length(); end++)
    {
        if (str[end] == ' ')
        {
            reverse(str.begin() + start, str.begin() + end);
            start = end + 1;
        }
    }
    reverse(str.begin() + start, str.end());
    reverse(str.begin(), str.end());
}
void ReverseWordNaive(string &str) // TC: O(n)   AS:O(n)
{
    stack<string> res;
    string temp = "";
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            res.push(temp);
            temp = "";
        }
        else
        {
            temp = temp + str[i];
        }
    }
    res.push(temp);

    while (!res.empty())
    {

        // Get the words in reverse order
        temp = res.top();
        cout << temp << " ";
        res.pop();
    }
    cout << endl;
}

int main()
{

    // string str = "abcabc";
    string str = "I Love To Code";
    ReverseWord(str);
    cout << str;

    return 0;
}