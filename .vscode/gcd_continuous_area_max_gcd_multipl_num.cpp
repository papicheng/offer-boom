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
int gcd(int a,int b){
    if(a==b||b==0) return a;
    if(a<b) return gcd(a,b%a);
    else return gcd(b,a%b);
}

int main(){
    // int n=5;
    // int a[n]={3,6,2,2,2};

    int m,n;
    cin>>n;
    vector<int> a;
    int i=0;
    while(i<n){
        i++;
        cin>>m;
        a.push_back(m);
    }
    int res=0;
    for(int i=0;i<n;i++){
        int m=a[i];
        for(int j=i;j<n;j++){
            m=gcd(m,a[j]);
            if(m*(j-i+1)>res) res=m*(j-i+1);
        }
    }
    printf("%d\n",res);
    return 0;
}