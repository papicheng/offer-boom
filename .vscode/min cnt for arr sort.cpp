/*¹¦ÄÜ£º*/
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int num = 1, max = 1;
    int n;
    cin>> n;
    vector<int> vec(n);
    vector<int> vec2(n);
    int tmp;
    for(int i = 0; i < n; ++i){
        cin>> tmp;
        vec[i] = tmp;
    }
    for(int i = 0 ; i < n; ++i){
        vec2[i] = vec[i];
        for(int j = i + 1;  j <n; ++j){
            vec2[j] = vec[j];
            if(vec2[i] + 1 == vec2[j]){
                num += 1;
                vec2[i] = vec2[j];
            }
        }
        if(num > max){
            max = num;
        }
        num = 1;
    }
    cout<< n - max;
    return 0;
}
