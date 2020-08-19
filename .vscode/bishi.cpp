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

int countOne(int n)
{
    int sum=0;
    while(n)
    {
        n&=(n-1);
        sum++;
    }
    return sum;
}


int main()
{
    vector<vector<int>> vec;
    cin>>vec;
    for(int i=0;i<vec.size();++i)
    {
        cout<<vec[i]<<",";
    }
    return 0;
}
    // public int[][] reconstructQueue(int[][] people) {
    //     Arrays.sort(people, (o1, o2) -> o1[0] == o2[0] ? o1[1] - o2[1] : o2[0] - o1[0]);
    //     List<int[]> list=new LinkedList<>();
    //     for(int[] p:people)
    //         list.add(p[1],p);
    //     return list.toArray(people);
    // }
