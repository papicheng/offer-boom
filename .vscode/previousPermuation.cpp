/*���ܣ�*/
#include<bits/stdc++.h>

using namespace std;

vector<int> previousPermuation(vector<int> &nums) {
        // write your code here
         if (nums.size() < 1) {
             return {};
         }
         int i = 0;
        // ��������������ҵ���һ���ȵ�ǰֵ��ģ�Ȼ������λ������ұ���С������ӽ���ֵ��������
        // Ȼ����������Ҫ�Ӵ�С����
        for (i = nums.size() - 1; i >= 1; --i) {
            if (nums[i] < nums[i - 1]) {
                // Ѱ�Ҵ�iλ�ÿ�ʼ����i-1λ��С������ӽ���ֵ
                int flag = i;
                int dis = nums[i - 1] - nums[i]; // > 0
                for (int j = i; j < nums.size(); j++) {
                    if ((nums[i - 1] - nums[j] > 0) && (nums[i - 1] - nums[j] < dis)) {
                        dis = nums[i - 1] - nums[j];
                        flag = j;
                    }
                }
                // ����
                swap(nums[i-1], nums[flag]);
                
                // i --> end()����������
                // �ֲ�ð������
                for (int k = i; k < nums.size(); k++) {
                    for (int l = k + 1; l < nums.size(); l++) {
                        if (nums[k] < nums[l]) {
                            swap(nums[k], nums[l]);
                        }
                    }
                }
                break;
            }
        }
        if (i == 0) {
            reverse(nums.begin(), nums.end());
        }
        return nums;
    }
int main()
{
    string n;
    cin>> n;
    vector<int> vec;
    for(auto ch : n){
        vec.push_back(ch - '0');
    }
    vector<int> res = previousPermuation(vec);
    string ans = "";
    for(auto i : res){
        ans += to_string(i);
    }
    if(n == ans || ans > n){
        cout<<"Not found"<<endl;
        return 0;
    }
    cout<< ans<< endl;
    return 0;
}
