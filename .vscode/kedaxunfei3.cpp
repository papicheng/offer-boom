#include<bits/stdc++.h>

using namespace std;

int main(){
    int a[8];
    for(int i = 0; i < 8; i++){
        cin >> a[i];
    }
    if((((a[0] >= a[4] && a[0] < a[6]) || (a[4] >= a[0] && a[4] <= a[2])) && ((a[1] >= a[5] && a[1] < a[7]) || (a[5] >= a[1] && a[5] <= a[3])))) {
        cout<<1<<endl;
    }
    else cout<<0<<endl;
}