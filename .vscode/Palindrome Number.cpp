/*¹¦ÄÜ£º*/
#include<bits/stdc++.h>

using namespace std;

bool isPalindrome(int x) {
        if(x < 0) return false;
        string str = to_string(x);
        string str_copy = str;
        reverse(str.begin(),str.end());
        if(str == str_copy){
            return true;
        }
        return false;
    }
int main()
{
    
    return 0;
}
