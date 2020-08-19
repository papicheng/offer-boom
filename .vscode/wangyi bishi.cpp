#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<int>> res;
void help(vector<vector<int>>& v,int n){
    if(n==1){
        res.push_back({1,1});
        return ;
    }
    int min_p=INT_MAX,min_q=INT_MAX;
    ll sum_max=0x7fffffffffffffff;
    vector<vector<ll>> temp(n,vector<ll>(n));
    temp[0][0]=v[0][0];
    for(int i=1;i<n;i++){
        temp[i][0]=v[i][0]+temp[i-1][0];
        temp[0][i]=v[0][i]+temp[0][i-1];
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            temp[i][j]=v[i][j]+temp[i-1][j]+temp[i][j-1]-temp[i-1][j-1];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ll s1=(i==0||j==0)?0:temp[i-1][j-1];
            ll s2=(j==0)?0:temp[n-1][j-1]-temp[i][j-1];
            ll s3=(i==0)?0:temp[i-1][n-1]-temp[i-1][j];
            ll s4=temp[n-1][n-1]+temp[i][j]-temp[n-1][j]-temp[i][n-1];
            ll sum=s1+s2+s3+s4;
            //cout<<n<<" "<<i<<" "<<j<<" "<<s1<<" "<<s2<<" "<<s3<<" "<<s4<<" "<<sum<<endl;
            if(sum<sum_max){
                sum_max=sum;
                min_p=i;
                min_q=j;
            }
            else if(sum==sum_max){
                if(i<min_p){
                    min_p=i;
                    min_q=j;
                }
                else if(i==min_p){
                    if(j<min_q){
                        min_p=i;
                        min_q=j;
                    }
                }
                else{}
            }
            else{}
        }
    }
    vector<vector<ll>>().swap(temp);
    res.push_back({min_p+1,min_q+1});
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            if(i>=min_p&&j>=min_q){
                v[i][j]=v[i+1][j+1];
            }
            else if(i>=min_p){
                v[i][j]=v[i+1][j];
            }
            else if(j>=min_q){
                v[i][j]=v[i][j+1];
            }
            else{}
        }
    }
    help(v,n-1);
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> v(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>v[i][j];
        }
    }
    help(v,n);
    for(auto i:res){
        cout<<i[0]<<" "<<i[1]<<endl;
    }
    return 0;
}