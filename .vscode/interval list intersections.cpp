/*���ܣ�����������һЩ��������ɵ��б�ÿ�������б��ǳɶԲ��ཻ�ģ������Ѿ�����
���룺A = [[0,2],[5,10],[13,23],[24,25]], B = [[1,5],[8,12],[15,24],[25,26]]
�����[[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
ע�⣺��������������������������ɵ��б�������������б�

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/interval-list-intersections
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/
#include<bits/stdc++.h>

using namespace std;
class Solutionzhulin {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int i=0,j=0,left,right;
        vector<vector<int>> v;
        while(i<A.size()&&j<B.size()){
            left=max(A[i][0],B[j][0]);
            right=min(A[i][1],B[j][1]);
            if(left<=right) v.push_back({left,right});
            if(A[i][1]>B[j][1]) j++;
            else if(A[i][1]<B[j][1]) i++;
            else{
                i++;
                j++;
            }
        }
        return v;
    }
};



int main()
{
    // vector<vector<int>> A = {{0,2},{5,10},{13,23},{24,25}}, B = {{1,5},{8,12},{15,24},{25,26}};
    vector<vector<int>> A={{3,5},{9,20}}, B = {{4,5},{7,10},{11,12},{14,15},{16,20}};
    vector<vector<int>> vecres = intervalIntersection(A,B);
    return 0;
}
