/*功能：给定两个由一些闭区间组成的列表，每个区间列表都是成对不相交的，并且已经排序。
输入：A = [[0,2],[5,10],[13,23],[24,25]], B = [[1,5],[8,12],[15,24],[25,26]]
输出：[[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
注意：输入和所需的输出都是区间对象组成的列表，而不是数组或列表。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/interval-list-intersections
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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
