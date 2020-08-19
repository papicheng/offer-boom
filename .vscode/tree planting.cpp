
/*功能：
种树问题：

输入的第一行为一个数字，表示土地的长度;
输入的第二行为一个由0和1组成并以空格分割的数列，表示该土地上目前的种植情况。

输入
5
1 0 0 0 0
输出
2
*/
#include<bits/stdc++.h>

using namespace std;

/*
每一次循环一次结束，x就是代表如果当前位置种花（置1）的话，当前位置和之前所
有位置能种花的最大个数，y就是代表如果当前位置不种花（置0）的话，当前位置和
之前所有位置能种花的最大个数
*/
/*方法一
import java.util.*;

public class Main{
    static int N = 100010;
    static int[] a = new int[N];
    public static void main(String[] args){
        Scanner cin = new Scanner(System.in);
        int n = cin.nextInt();
        
        for (int i = 1; i <= n; i ++){
            a[i] = cin.nextInt();
        }
        
        int cnt = 0;
        
        for (int i = 1; i <= n;){
            if (a[i] == 0){
                if (a[i - 1] == 0 && a[i + 1] == 0) cnt ++;
                i += 2;
            }else{
                i += 2;
            }
        }
        
        System.out.print(cnt);
    }
}
*/
////方法一有问题
int method1(int n, vector<int>& B){
    vector<int> A(B);
    A.push_back(0);
    A.push_back(0);
    int count = 0;
    for(int i = 1; i <= n; i += 2){
        if(A[i] == 0 && A[i - 1] == 0 && A[i + 1] == 0){
            ++count;
        }
    }
    return count;
}
int method2(int n, vector<int>& A){
    int x = 0, y = 0;
    for( int i = 0; i < n; ++i){
        int temp_x, temp_y;
        if(A[i] == 1){
            temp_x = y;
            temp_y = -1;
        }
        else{
            temp_x = y + 1;
            temp_y = max(x, y);
        }
        x = temp_x;
        y = temp_y;
    }
    return max(x, y);
}
int main() {
    int n;
    // cin>> n;
    n  = 8;
    vector<int> A;
    for(int i = 0;i < n; ++i){
        int t = 0;
        // cin>>t;
        A.push_back(t);
    }
    A[0] = 1;
    A[6] = 1;
    //输入结束/////////////////////////////////////////////
    int res;
    res = method1(n, A);
    cout<<res<<endl;
    res = method2(n, A);
    cout<< res<<endl;

    return 0;
}
