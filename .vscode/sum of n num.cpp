/*功能：
牛牛现在在学习计算机，他想通过计算机计算n个数的和。
但是计算机计算数字的和是有花费的，比如计算x，y两个数的和，需要花费(c*x+c*y)(c∗x+c∗y)秒。
计算机一次只能计算一次，牛牛想知道自己怎么合理安排计算的顺序，可以使得花费的时间最短。
*/
#include<iostream>
#include<vector>
#include<queue>

using namespace std;


/**
     * 返回一个数字表示输出计算n个数字和的最小花费的时间。
     * @param n int整型 表示有n个数。
     * @param c int整型 参数c
     * @param a int整型vector ai表示第i个数的大小
     * @return long长整型
     */
long long solve(int n, int c, vector<int>& a) {
        // write code here
        priority_queue<int,vector<int>,greater<int>> q;///小项堆
        long long res=0;
        for (int i = 0; i < n; i++)
            q.push(a[i]);
        for(int i=0;i<n-1;i++)
        {
            //每次取两个最小的数出来运算，再压入堆
            long long min_1=q.top();
            q.pop();
            long long min_2=q.top();
            q.pop();
            long long sum=min_1+min_2;
            res+=c*sum;
            q.push(sum);
        }
        return res;
    }



int main()
{
    int n=5,c=76;
    vector<int>a={81,30,76,24,84};
    long long res=solve(n,c,a);
    cout<<"result= "<<res<<endl;
    return 0;
}
