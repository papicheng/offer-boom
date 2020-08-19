#include<bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    getline(cin, str);
    istringstream is(str);
    char ch;
    string ans = "";
    while (is >> ch)
    {
        if ((ch == '-')||(ch >= '0'&&ch <= '9')) ans += ch;
    }
    cout<< ans <<endl;
    return 0;
}