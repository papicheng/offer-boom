/*功能：
你有两个字符串，即pattern和value。 pattern字符串由字母"a"和"b"组成，用于描述字符串中的模式。例如，字符串"catcatgocatgo"匹配模式"aabab"（其中"cat"是"a"，"go"是"b"），该字符串也匹配像"a"、"ab"和"b"这样的模式。但需注意"a"和"b"不能同时表示相同的字符串。编写一个方法判断value字符串是否匹配pattern字符串。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/pattern-matching-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
输入： pattern = "abba", value = "dogcatcatdog"
输出： true
*/
#include<bits/stdc++.h>

using namespace std;

bool patternMatching(string pattern , string value){
    int plen = pattern.size(), vlen = value.size();
    if(plen == 0 && vlen == 0) return true;
    if(plen == 0) return false;

    int ac = 0, bc = 0;
    for(int i = 0; i < plen; ++i){
        if(pattern[i] == 'a') ac++;
        else bc++;
    }
    int la = 0, lb = 0;
    if(ac != 0) la = vlen / ac;
    if(bc != 0) lb = vlen / bc;

    for(int i = 0; i <= la; ++i){
        for(int j = 0; j <= lb; ++j){
            if(i * ac + j * bc == vlen){
                string sa = "#";
                string sb = "#";
                int index = 0;
                for(int k = 0; k < plen; ++k){
                    if(pattern[k] == 'a'){
                        if(sa == "#") sa = value.substr(index, i);
                        else{
                            if(sa!= value.substr(index, i)) break;
                        }
                        index +=i;
                    }
                    else{
                        if(sb == "#") sb = value.substr(index, j);
                        else{
                            if(sb != value.substr(index, j)) break;
                        }
                        index += j;
                    }
                }
                if(index == vlen && sa != sb) return true;
            }
        }
    }
    return false;
}

int main()
{
    
    return 0;
}
