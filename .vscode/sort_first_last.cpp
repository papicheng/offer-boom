#include<map>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
int main()
  {
     int n,temp;
     cin>>n;
     vector<int> v;
     map<int,int> m;
     for(int i=0;i<n;i++)
       {  cin>>temp;
          v.push_back(temp);
          m[temp]=i;
       }
     sort(v.begin(),v.end());
     int t=n,count=0;
     for(int i=0;i<n-1;i++)
       {
           if (m[v[i]]>m[v[i+1]])
              {
                 m[v[i+1]]=t++;
                 count++;
              }
       }
     cout<<count<<endl;
  }