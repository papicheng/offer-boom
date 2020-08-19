/*���ܣ��绰�����ܹ��ɵ���ĸ���*/
#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
    vector<string> letterCombinations(string digits){
        if(digits.length() == 0) return res;
        backTrace(digits, 0);
        return res;
    }
    private:
    unordered_map<char, string> phoneString{
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    public:
    string s;
    vector<string> res;
    void backTrace(string digits, int index){
        //��������
        if(digits.size() == index){
            res.push_back(s);
        }
        //forÿ��λ�õ���ѡ�����ĸinÿ��λ�ÿ�ѡ�����ĸ����
        for(int i = 0; i < phoneString[digits[index]].size(); ++i){
            //��index��λ��ѡ�����ĸ
            s += phoneString[digits[index]][i];
            //Ϊ��һ��λ��ѡ����ĸ
            backTrace(digits, index + 1);
            //������һ�ε�Ϊ��ĸѡ��
            s.pop_back();
        }
    }
};


int main()
{
    
    return 0;
}
