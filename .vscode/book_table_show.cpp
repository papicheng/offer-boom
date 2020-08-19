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


// 给你一个数组 orders，表示客户在餐厅中完成的订单，确切地说， orders[i]=[customerNamei,tableNumberi,foodItemi] ，其中 customerNamei 是客户的姓名，tableNumberi 是客户所在餐桌的桌号，而 foodItemi 是客户点的餐品名称。

// 请你返回该餐厅的 点菜展示表 。在这张表中，表中第一行为标题，其第一列为餐桌桌号 “Table” ，后面每一列都是按字母顺序排列的餐品名称。接下来每一行中的项则表示每张餐桌订购的相应餐品数量，第一列应当填对应的桌号，后面依次填写下单的餐品数量。

// 注意：客户姓名不是点菜展示表的一部分。此外，表中的数据行应该按餐桌桌号升序排列。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/display-table-of-food-orders-in-a-restaurant
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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

//超时了
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
