/*
����Ŀ����
����һ���ַ�������β������һ��Բ�������Ƿ��ܹ���ĳ���жϺ����һ
�����ġ�
ͨ������������Yes,�������No
��������: 
���������ַ��� S
�������:
S��������ж�����ַ���Yes��������� No��

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
bool f(string s){
    int n=s.size();
    for(int i=0;i<n;i++){
        int j=i;
        int k=(j==n-1)?0:j+1;
        bool flag=true;
        for(int u=0;u<n/2;u++){
            if(s[j]==s[k]){
                j=(j==0)?n-1:j-1;
                k=(k==n-1)?0:k+1;
            }
            else{
                flag=false;
                break;
            }
        }
        if(flag) {
            return true;
        }
    }
    return false;
}
int main(){
    string s;
    cin>>s;
    if(f(s)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}