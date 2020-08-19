#include <iostream>
#include <bits/stdc++.h>
using namespace std;

float str2float(const char* str){
    float res = 0;
    int i = 0;
    int len = 0;
    while(str[len] != '\0'){
        len++;
    }
    float right = 0, left = 0;
    for(i = len - 1; i >= 0; i--){
        if(str[i] == '.') {
            res += right / 10.0;
            break;
        }
        right = right / 10.0 + (str[i] - '0');
    }

    for(i = i - 1; i >= 0; i--){
        left = left * 10 + (str[i] - '0');
    }
    res += left;
    return res;
}

int main() {
    char str[] = "3.14";
    cout<< str2float(str) <<endl;
}

