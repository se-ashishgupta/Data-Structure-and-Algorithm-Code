#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

int main()
{

    // char str[6] = "gfg";
    // char str[] = "gfg";
    // cout << str << endl;

    // char str[5];
    // str = "gfg"; // not Posible str to be in left
    // strcpy(str, "gfg");

    // cout << sizeof(str) << endl;

    // char str1[] = {'g', 'f', 'g', '\0'};
    // cout << str1;

    // string str = "geeksforgeeks";
    // cout << str << endl;
    // cout << str.length() << endl;
    // cout << str + "xyz" << endl;
    // cout << str << endl;
    // cout << str.substr(1, 3) << endl;
    // cout << str.find("ee") << endl;

    // string s1 = "abc";
    // string s2 = "bcd";
    // if (s1 == s2)
    //     cout << "Same";
    // else if (s1 < s2)
    //     cout << "Smaller";
    // else
    //     cout << "Greater";

    // string str;
    // cout << "Enter your Name" << endl;
    // // cin >> str;
    // getline(cin, str);
    // cout << "Your Name is" << str << endl;

    string str = "thecreativeprogrammer";
    for (int i = 0; i < str.length(); i++)
    {
        cout << str[i];
    }
    for (char x : str)
        cout << x;
    return 0;
}