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




int main()
{
    vector<int> vec;
    string line;
    string item;
    getline(cin,line);
    istringstream items(line);
    while (items>>item)
    {
        vec.push_back((atoi( item.c_str() )));
    }
    

    return 0;
}
