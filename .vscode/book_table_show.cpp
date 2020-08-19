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


// ����һ������ orders����ʾ�ͻ��ڲ�������ɵĶ�����ȷ�е�˵�� orders[i]=[customerNamei,tableNumberi,foodItemi] ������ customerNamei �ǿͻ���������tableNumberi �ǿͻ����ڲ��������ţ��� foodItemi �ǿͻ���Ĳ�Ʒ���ơ�

// ���㷵�ظò����� ���չʾ�� �������ű��У����е�һ��Ϊ���⣬���һ��Ϊ�������� ��Table�� ������ÿһ�ж��ǰ���ĸ˳�����еĲ�Ʒ���ơ�������ÿһ���е������ʾÿ�Ų�����������Ӧ��Ʒ��������һ��Ӧ�����Ӧ�����ţ�����������д�µ��Ĳ�Ʒ������

// ע�⣺�ͻ��������ǵ��չʾ���һ���֡����⣬���е�������Ӧ�ð����������������С�

// ��Դ�����ۣ�LeetCode��
// ���ӣ�https://leetcode-cn.com/problems/display-table-of-food-orders-in-a-restaurant
// ����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
vector<string> read_string(string str)
{
    for(int i=0;i<str.size();++i)
    {
        if(str[i]==',')
        {
            str[i]=' ';
        }
    }
    istringstream out(str);
    vector<string> res;
    for(int i=0;i<3;++i)
    {
        out>>res[i];
        res[i]=string(res[i].begin()+1,res[i].end()-1);
    }
    return res;
}

//��ʱ��
vector<vector<string>> displayTable_failed(vector<vector<string>>& orders) {
    map<string,map<string,int>> tabel;
    set<string> food;
    for(int i=0;i<orders.size();++i)
    {
        food.insert(orders[i][2]);
        if(tabel.find(orders[i][1])==tabel.end())
        {
            tabel[orders[i][1]][orders[i][2]]=1;
        }
        else
        {
            if(tabel[orders[i][1]].find(orders[i][2])==tabel[orders[i][1]].end())
            {
                tabel[orders[i][1]][orders[i][2]]=1;
            }
            else
            {
                tabel[orders[i][1]][orders[i][2]]+=1;
            }
        }
    }
    vector<string> clounm_name;
    clounm_name.push_back("Tabel");
    set<string>::iterator iter=food.begin();
    while(iter!=food.end())
    {
        clounm_name.push_back(*iter);
        iter++;
    }
    vector<vector<string>> res;
    res.push_back(clounm_name);
    map<string,map<string,int>> :: iterator it=tabel.begin();
    while(it!=tabel.end())
    {
        vector<string> temp;
        temp.push_back(it->first);
        iter=food.begin();
        while(iter!=food.end())
        {
            if(it->second.find(*iter)!=it->second.end())
            {
                temp.push_back(to_string(it->second[*iter]));
            }
            else
            {
                temp.push_back("0");
            }
            
            iter++;
        }
        res.push_back(temp);
    }
    return res;
}    
vector<vector<string>> displayTable(vector<vector<string>>& orders)
{
    set<string> foodList;
    map<int,map<string,int>> tableList;
    for(auto& o:orders)
    {
        foodList.insert(o[2]);
        tableList[stoi(o[1])][o[2]]++;
    }
    vector<vector<string>> ans;
    vector<string> title={"Table"};
    for(auto& s:foodList)
    {
        title.push_back(s);
    }
    ans.push_back(title);
    for(auto& p:tableList)
    {
        vector<string> t={to_string(p.first)};
        for(auto& s:foodList)
        {
            t.push_back(to_string(p.second[s]));
        }
        ans.push_back(t);
    }
    return ans;
}
int main()
{
    
    return 0;
}
