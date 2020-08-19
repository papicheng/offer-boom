/*功能：
0-1背包问题
给定n个重量为w1,w2,w3...,wn,价值为v1,v2,..,vn的物品和容量为C的背包，求这个物品中一个最有价值的子集，使得在满足背包的容量的前提下，包内的总价值最大
————————————————
版权声明：本文为CSDN博主「跑码场」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/chanmufeng/article/details/82955730
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//1递推方法

/**
     * 解决背包问题的递归函数
     *
     * @param w        物品的重量数组
     * @param v        物品的价值数组
     * @param index    当前待选择的物品索引
     * @param capacity 当前背包有效容量
     * @return 最大价值
     */
int solveKS(vector<int> w,vector<int> v,int index,int capacity)
{
    //自顶向下的方式，假设已经走到最后一步
    //基准条件：如果索引无效或者容量不足，直接返回当前价值0
    if(index<0||capacity<=0)
        return 0;
    //不放第index个物品所得价值
    int res=solveKS(w,v,index-1,capacity);
    //放第index 个物品所得价值（前提是：第index个物品可以放下）
    if(w[index]<=capacity)
    {
        res=max(res,v[index]+solveKS(w,v,index-1,capacity-w[index]));
    }
    return res;
}
int knapSack(vector<int> w,vector<int> v, int c)
{
    int size=w.size();
    return solveKS(w,v,size-1,c);
}
///1.递推方法结束、、、、、、、、、、、、、、、、、、、、、、


///2.记忆化搜索
/*递归算法会导致不止一次解决公共子问题，因此效率是相当低下的。
可以将已经求得的子问题的结果保存下来，这样对子问题只会求解一次，这便是记忆化搜索。

下面在上述代码的基础上加上记忆化搜索。
*/
int solveKS(vector<int>w,vector<int>v,int index,int capacity,vector<vector<int>> memoryFlag)
{
    //基准条件：如果索引无效或者容量不足，直接返回当前价值0
    if(index<0||capacity<1)
        return 0;
    //如果此子问题已经求解过，则直接返回上次求解的结果
    if(memoryFlag[index][capacity])
    {
        return memoryFlag[index][capacity];
    }
    //不放第index个物品所得价值
    int res=solveKS(w,v,index-1,capacity);
    //放第index个物品所得价值（前提是：第index个物品可以放得下）
    if(w[index]<=capacity)
    {
        res=max(res,v[index]+ solveKS(w,v,index-1,capacity-w[index]));
    }
    //添加子问题的解，便于下次直接使用
    memoryFlag[index][capacity]=res;
    return res;
}
int knapSack_memo(vector<int>w ,vector<int> v,int c,vector<vector<int>> memoryFlag)
{
    int size=w.size();
    return solveKS(w,v,size-1,c,memoryFlag);
}
///2.记忆搜索结束、、、、、、、、、、、、、、、、、、、、、、
///3. 动态规划
int knapSack_dp(vector<int> w,vector<int>v,int c)
{
    int size=w.size();
    if(size==0)
        return 0;
    vector<int> dp(c+1);
    //初始第一行
    //仅考虑容量为c的背包放第0个物品的情况
    for(int i=0;i<=c;++i)
        dp[i]=w[0]<=i?v[0]:0;
    for(int i=1;i<size;++i)
    {
        for(int j=c;j>=w[i];--j)
        {
            dp[j]=max(dp[j],v[i]+dp[j-w[i]]);
        }
    }
    return dp[c];
}

int main()
{
    vector<int> w={2,1,3,2};
    vector<int> v={12,10,20,15};
    const int c=5;
    vector<vector<int>> memoryFlag(w.size(),vector<int>(c+1));
    int res=knapSack(w,v,c);
    cout<<"recursion:"<<res<<endl;
    int res_memo=knapSack_memo(w,v,c,memoryFlag);
    cout<<"memory search:"<<res_memo<<endl;
    int res_dp=knapSack_dp(w,v,c);
    cout<<"dp:"<<res_dp<<endl;
    return 0;
}
