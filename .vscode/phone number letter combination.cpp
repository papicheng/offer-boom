/*功能：电话号码能构成的字母组合*/
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
        //结束条件
        if(digits.size() == index){
            res.push_back(s);
        }
        //for每个位置当下选择的字母in每个位置可选择的字母集合
        for(int i = 0; i < phoneString[digits[index]].size(); ++i){
            //第index个位置选择的字母
            s += phoneString[digits[index]][i];
            //为下一个位置选择字母
            backTrace(digits, index + 1);
            //撤销上一次的为字母选择
            s.pop_back();
        }
    }
};


int main()
{
    
    return 0;
}
