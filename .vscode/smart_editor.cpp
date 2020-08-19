/*¹¦ÄÜ£º*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <sstream>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <math.h>

using namespace std;



int main()
{
    int T=1;
    //cin>>T;
    vector<string> res;
    while (T)
    {
        string str="woooooooow";
        //cin>>str;
        string str_temp="";
        for(auto i : str)
        {
            if(str_temp.size()<2)
            {
                str_temp+=i;
                continue;
            }
            if(str_temp.size()>=2)
            {
                if(i==str_temp[str_temp.size()-1]&&i==str_temp[str_temp.size()-2])
                {
                    continue;
                }
            }
            if(str_temp.size()>=3)
            {
                if(i==str_temp[str_temp.size()-1]&&str_temp[str_temp.size()-2]==str_temp[str_temp.size()-3])
                {
                    continue;
                }
            }
            str_temp+=i;
        }
        res.push_back(str_temp);
        --T;
    }
    for(int i=0;i<res.size();++i)
    {
        cout<<res[i]<<endl;
    }
    return 0;
}
