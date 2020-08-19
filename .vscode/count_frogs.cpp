/*功能：*/
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



// 给你一个字符串 croakOfFrogs，它表示不同青蛙发出的蛙鸣声（字符串 "croak" ）的组合。由于同一时间可以有多只青蛙呱呱作响，所以?croakOfFrogs 中会混合多个 “croak” 。请你返回模拟字符串中所有蛙鸣所需不同青蛙的最少数目。

// 注意：要想发出蛙鸣 "croak"，青蛙必须 依序 输出 ‘c’, ’r’, ’o’, ’a’, ’k’ 这 5 个字母。如果没有输出全部五个字母，那么它就不会发出声音。

// 如果字符串 croakOfFrogs 不是由若干有效的 "croak" 字符混合而成，请返回 -1 。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/minimum-number-of-frogs-croaking
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
int minNumberOfFrogs(string croakOfFrogs) {
    int res=0;
    for(int i=0;i<croakOfFrogs.size();++i)
    {
        if(croakOfFrogs[i]=='c')
        {
            
        }
    }
}

int main()
{
    
    return 0;
}
class Solution {
public:
    int multiply(int A, int B) {
        int sum=0;
        int count=0;
        while(B>0){
            if((B>>1)<<1!=B) sum=sum+(A<<count);
            count++;
            B=B>>1;
        }
        return sum;
    }
};