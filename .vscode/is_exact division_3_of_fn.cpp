/*
斐波拉契数列判断第n个能否整除3

输入：
3           //有几行测试数据
1 1 3       前两个是斐波拉契数列的开头两个，后一个是n
1 1 4
7 11 2
输出：
YES
NO
YES


a(n)=3*a(n-3)+2*a(n-4)
所以如果n-4项能被3整除，第n项就可以
*/

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
int n,A,B,N,i=0;
int main(){
    cin>>n;
    while(i<n){
        i++;
        cin>>A>>B>>N;
        int t=N%4;
        if(t==0) {
            if(A%3==0)printf("YES\n");
            else printf("NO\n");
        }
        else if(t==1) {
            if(B%3==0)printf("YES\n");
            else printf("NO\n");
        }
        else if(t==2){
            if(((A%3+B%3))%3==0)printf("YES\n");
            else printf("NO\n");
        }
        else
        {
            if(((A%3+2*(B%3)))%3==0)printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}

