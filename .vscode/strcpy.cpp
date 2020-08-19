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
#include<stdlib.h>
#include<string.h>

using namespace std;





char * strcpy(char * des,char * src)
{
    if(des==NULL||src==NULL)
    {
        return NULL;
    }
    char * head=des;
    while ((*des++ =*src++)!='\0')
    {
        /* code */
    }
    return head;
}

int main()
{
    char src[]="this is a test!";
    char *dest=new char[strlen(src)+1];
    strcpy(dest,src);
    cout<<dest<<endl;
    return 0;
}
