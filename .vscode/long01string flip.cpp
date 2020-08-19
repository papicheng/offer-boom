/*¹¦ÄÜ£º*/
#include<bits/stdc++.h>

using namespace std;


int main()
{
    int cnt = 1;
    int n;
    cin>>n;
    string s;
    cin>>s;
    for (int i = 0;i < n - 1;i++) {
        if (s[i] != s[i + 1]) cnt++;
    }
    if (cnt < n - 1) cout << cnt + 2 << endl;
    else cout << n << endl;
    return 0;
}
