/*¹¦ÄÜ£º*/
#include<bits/stdc++.h>

using namespace std;


int translateNum(int num) {
        string str = to_string(num);
        int len = str.size();
        vector<int> vec(len + 1, 0);
        vec[1] = 1;
        for(int i =1; i<len;++i){
            string sub = str.substr(i - 1, 2);
            if( sub <= "25" && sub >= "10"){
                vec[i + 1] = vec[i] + vec[i - 1];
            }
            else
            {
                vec[i+1] = vec[i] + 1;
            }
            
        }
        return vec.back();
    }

int main()
{
    int num = 12258;
    int res = translateNum(num);
    cout<<res;
    return 0;
}

