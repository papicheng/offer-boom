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



int mySqrt(int x) {
        int half=x>>1;
        for(int i=0;i<half;++i)
        {
            if((i*i<=x)&&((i+1)*(i*1)>x))
            {
                return i;
            }
        }
    }



int main()
{
    int input=4;
    int output=mySqrt(input);
    cout<<output<<endl;
    return 0;
}
