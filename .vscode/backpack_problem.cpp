/*���ܣ�
0-1��������
����n������Ϊw1,w2,w3...,wn,��ֵΪv1,v2,..,vn����Ʒ������ΪC�ı������������Ʒ��һ�����м�ֵ���Ӽ���ʹ�������㱳����������ǰ���£����ڵ��ܼ�ֵ���
��������������������������������
��Ȩ����������ΪCSDN���������볡����ԭ�����£���ѭCC 4.0 BY-SA��ȨЭ�飬ת���븽��ԭ�ĳ������Ӽ���������
ԭ�����ӣ�https://blog.csdn.net/chanmufeng/article/details/82955730
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//1���Ʒ���

/**
     * �����������ĵݹ麯��
     *
     * @param w        ��Ʒ����������
     * @param v        ��Ʒ�ļ�ֵ����
     * @param index    ��ǰ��ѡ�����Ʒ����
     * @param capacity ��ǰ������Ч����
     * @return ����ֵ
     */
int solveKS(vector<int> w,vector<int> v,int index,int capacity)
{
    //�Զ����µķ�ʽ�������Ѿ��ߵ����һ��
    //��׼���������������Ч�����������㣬ֱ�ӷ��ص�ǰ��ֵ0
    if(index<0||capacity<=0)
        return 0;
    //���ŵ�index����Ʒ���ü�ֵ
    int res=solveKS(w,v,index-1,capacity);
    //�ŵ�index ����Ʒ���ü�ֵ��ǰ���ǣ���index����Ʒ���Է��£�
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
///1.���Ʒ���������������������������������������������������


///2.���仯����
/*�ݹ��㷨�ᵼ�²�ֹһ�ν�����������⣬���Ч�����൱���µġ�
���Խ��Ѿ���õ�������Ľ������������������������ֻ�����һ�Σ�����Ǽ��仯������

��������������Ļ����ϼ��ϼ��仯������
*/
int solveKS(vector<int>w,vector<int>v,int index,int capacity,vector<vector<int>> memoryFlag)
{
    //��׼���������������Ч�����������㣬ֱ�ӷ��ص�ǰ��ֵ0
    if(index<0||capacity<1)
        return 0;
    //������������Ѿ���������ֱ�ӷ����ϴ����Ľ��
    if(memoryFlag[index][capacity])
    {
        return memoryFlag[index][capacity];
    }
    //���ŵ�index����Ʒ���ü�ֵ
    int res=solveKS(w,v,index-1,capacity);
    //�ŵ�index����Ʒ���ü�ֵ��ǰ���ǣ���index����Ʒ���Էŵ��£�
    if(w[index]<=capacity)
    {
        res=max(res,v[index]+ solveKS(w,v,index-1,capacity-w[index]));
    }
    //���������Ľ⣬�����´�ֱ��ʹ��
    memoryFlag[index][capacity]=res;
    return res;
}
int knapSack_memo(vector<int>w ,vector<int> v,int c,vector<vector<int>> memoryFlag)
{
    int size=w.size();
    return solveKS(w,v,size-1,c,memoryFlag);
}
///2.��������������������������������������������������������
///3. ��̬�滮
int knapSack_dp(vector<int> w,vector<int>v,int c)
{
    int size=w.size();
    if(size==0)
        return 0;
    vector<int> dp(c+1);
    //��ʼ��һ��
    //����������Ϊc�ı����ŵ�0����Ʒ�����
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
