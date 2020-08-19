/*功能：找出数组中左边第一个比它大的数*/
#include<bits/stdc++.h>

using namespace std;        

vector<int> leftFirstMax(vector<int> arr){
    stack<int> st;
    vector<int> res(arr.size(), -1);
    for(int i =0; i < arr.size(); i++){
        while(st.size() && st.top() <= arr[i]){
            st.pop();
        }
        if(st.size()){
            res[i] = st.top();
        }
        st.push(arr[i]);
    }
    return res;
}

int main(){
    vector<int> arr = {5, 4, 3, 2, 1};
    vector<int> res = leftFirstMax(arr);
    for(auto i : res){
        cout<< i << " ";
    }
    // vector<int> leftFirstMax(arr.size(), -1);
    // int length = arr.size();
    // stack<int> st;
    // for (int index = 0; index < length; index++) {
    //     while (st.size() && arr[index] >= st.top()) {
    //         st.pop();
    //     }
    //     if (st.size()) {
    //         leftFirstMax[index] = st.top();
    //     }
    //     st.push(arr[index]);
    // }
    // for (size_t i = 0; i < length; i++)
    // {
    //     cout<< leftFirstMax[i] << " ";
    // }
    return 0;
}