/*¹¦ÄÜ£º*/
#include<bits/stdc++.h>

using namespace std;
class  Solutionzhulin  {
public:
        vector<vector<int>>  insert(vector<vector<int>>&  intervals,  vector<int>&  newInterval)  {
                vector<vector<int>>  vecres;
                int  left=newInterval[0],right=newInterval[1];
                bool  flag=true;
                for(int  i  =  0;  i  <  intervals.size();  ++i){
                        if(intervals[i][1]<newInterval[0])  vecres.push_back(intervals[i]);
                        else  if(intervals[i][0]>newInterval[1])  {
                                if(flag)  {
                                        vecres.push_back({left,right});
                                        flag=false;
                                }
                                vecres.push_back(intervals[i]);
                        }
                        else{
                                if(intervals[i][0]<left)  left=intervals[i][0];
                                if(intervals[i][1]>right)  right=intervals[i][1];
                        }
                }
                if(flag)  vecres.push_back({left,right});
                return  vecres;
        }
};
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> vecres;
        if(intervals.size() == 0 ){
            vecres.push_back(newInterval);
            return vecres;
        }
        int flag = 0;
        if(newInterval[1] < intervals[0][0]){
                vecres.push_back(newInterval);
                flag = 1;
            }
        if(newInterval[0] > intervals[intervals.size() - 1][1]){
            flag = 2;
        }
        if(flag){
            if(flag == 1){
                for(int i = 0; i < intervals.size(); ++i){
                    vecres.push_back(intervals[i]);
                }
                return vecres;
            }
            else{
                intervals.push_back(newInterval);
                return intervals;
            }
        }

        for(int i = 0;i < intervals.size(); ++i){
            if(intervals[i][1] < newInterval[0]){
                vecres.push_back(intervals[i]);
            }
            if(flag!=2 && intervals[i][1] < newInterval[0] && newInterval[1] < intervals[i+1][0]){
                vecres.push_back(newInterval);
            }
            if(intervals[i][1] >= newInterval[0] && intervals[i][0] <= newInterval[1]){
                while(i < intervals.size() && intervals[i][1] >= newInterval[0] && intervals[i][0] <= newInterval[1] ){
                    newInterval[0] = min(newInterval[0], intervals[i][0]);
                    newInterval[1] = max(newInterval[1], intervals[i][1]);
                    ++i;
                }
                vecres.push_back(newInterval);
            }
            if(i < intervals.size() && intervals[i][0] > newInterval[1]){
                vecres.push_back(intervals[i]);
            }
            if(newInterval[0] > intervals[intervals.size() - 1][1]){
                vecres.push_back(newInterval);
            }
        }
        return vecres;
    }

int main()
{
    vector<vector<int>> intervals = {{1,5}};
    vector<int> newInterval = {6,8};
    vector<vector<int>> res = insert(intervals,newInterval);
    return 0;
}


