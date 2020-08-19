/*¹¦ÄÜ£º*/
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

class Solution {
public:
    
};

void dfs(vector<vector<int>> &image,int sr,int sc,int newColor,int val)
{
    if(sr<0||sr>=image.size()||sc<0||sc>=image[0].size()||image[sr][sc]!=val||newColor==val)
    {
        return;
    }
    else
    {
        image[sr][sc]=newColor;
    }
    dfs(image,sr,sc+1,newColor,val);
    dfs(image,sr-1,sc,newColor,val);
    dfs(image,sr+1,sc,newColor,val);
    dfs(image,sr,sc-1,newColor,val);
}
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    dfs(image,sr,sc,newColor,image[sr][sc]);
    return image;
    }
int main()
{

    return 0;
}
