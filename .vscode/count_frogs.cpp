/*���ܣ�*/
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



// ����һ���ַ��� croakOfFrogs������ʾ��ͬ���ܷ��������������ַ��� "croak" ������ϡ�����ͬһʱ������ж�ֻ�����������죬����?croakOfFrogs �л��϶�� ��croak�� �����㷵��ģ���ַ����������������費ͬ���ܵ�������Ŀ��

// ע�⣺Ҫ�뷢������ "croak"�����ܱ��� ���� ��� ��c��, ��r��, ��o��, ��a��, ��k�� �� 5 ����ĸ�����û�����ȫ�������ĸ����ô���Ͳ��ᷢ��������

// ����ַ��� croakOfFrogs ������������Ч�� "croak" �ַ���϶��ɣ��뷵�� -1 ��

// ��Դ�����ۣ�LeetCode��
// ���ӣ�https://leetcode-cn.com/problems/minimum-number-of-frogs-croaking
// ����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
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