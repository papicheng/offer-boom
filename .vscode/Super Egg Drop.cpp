/*���ܣ�
��������
ʾ�� 1��

���룺K = 1, N = 2
�����2
���ͣ�
������ 1 ¥���䡣��������ˣ����ǿ϶�֪�� F = 0 ��
���򣬼����� 2 ¥���䡣��������ˣ����ǿ϶�֪�� F = 1 ��
�����û�飬��ô���ǿ϶�֪�� F = 2 ��
��ˣ�����������������Ҫ�ƶ� 2 ����ȷ�� F �Ƕ��١�
ʾ�� 2��

���룺K = 2, N = 6
�����3
ʾ�� 3��

���룺K = 3, N = 14
�����4

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/super-egg-drop
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


*/
#include<bits/stdc++.h>

using namespace std;


int find(int K, int N) {
    if(K == 0 || N == 0) return 0;
    if(K == 1) return N;
    if(N == 1) return 1;
    int little = N + 1;
    for(int x = 1; x <= N; x ++){
        little = min(little, max(find(K, N-x), find(K-1, x-1)) + 1);
    }
    return little;
}

int main()
{
    int K,N;
    cin>>K>>N;
    int res = find(K, N);
    cout<<res;
    return 0;
}