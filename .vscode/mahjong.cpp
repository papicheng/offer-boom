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

vector<int> card(9);
//���ʣ������Ƿ������n��˳�ӻ����
bool hasTribel(int n)
{
    if(n==0)
    {
        return true;
    }
    for(int i=0;i<card.size();++i)
    {
        //��Ϊ���Ǵ�1��ʼ��飬�������鵽������>=3����ض��ǿ���
        if(card[i]>2)
        {
            card[i]-=3;
            if(hasTribel(n-1))
            {
                //���ʣ�µ����ܷ����n-1��˳�ӻ��߿���
                card[i]+=3;
                return true;
            }
            card[i]+=3;
        }
        //����ֻ����˳��
        else if(i<card.size()-2&&card[i]>0&&card[i+1]>0&&card[i+2]>0)
        {
            card[i]--;
            card[i+1]--;
            card[i+2]--;
            if(hasTribel(n-1))
            {
                card[i]++;
                card[i+1]++;
                card[i+2]++;
                return true;
            }
            card[i]++;
            card[i+1]++;
            card[i+2]++;
        }
    }
    return false;
}
//����ܷ����
bool isWin()
{
    for(int i=0;i<9;++i)
    {
        //���ΰ�1-9��Ϊȸͷ�ó��������ʣ�µ�12�����ܷ����˳�ӻ��߿���
        if(card[i]<2)
        {
            continue;
        }
        card[i]-=2;
        if(hasTribel(4))
        {
            card[i]+=2;
            return true;
        }
        card[i]+=2;
    }
    return false;
}


int main()
{
    vector<int > res;
    int tmp;
    for(int i=0;i<13;++i)
    {
        cin>>tmp;
        card[tmp-1]++;
    }
    for(int i=0;i<9;++i)
    {
        if(card[i]>3)
        {
            continue;
        }
        card[i]++;
        if(isWin())
        {
            res.push_back(i+1);
        }
        card[i]--;
    }
    if(res.empty())
        {
            res.push_back(0);
        }
        for(int i=0;i<res.size();++i)
        {
            cout<<res[i]<<" ";
        }
    return 0;
}
