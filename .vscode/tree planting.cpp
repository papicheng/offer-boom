
/*���ܣ�
�������⣺

����ĵ�һ��Ϊһ�����֣���ʾ���صĳ���;
����ĵڶ���Ϊһ����0��1��ɲ��Կո�ָ�����У���ʾ��������Ŀǰ����ֲ�����

����
5
1 0 0 0 0
���
2
*/
#include<bits/stdc++.h>

using namespace std;

/*
ÿһ��ѭ��һ�ν�����x���Ǵ��������ǰλ���ֻ�����1���Ļ�����ǰλ�ú�֮ǰ��
��λ�����ֻ�����������y���Ǵ��������ǰλ�ò��ֻ�����0���Ļ�����ǰλ�ú�
֮ǰ����λ�����ֻ���������
*/
/*����һ
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
////����һ������
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
    //�������/////////////////////////////////////////////
    int res;
    res = method1(n, A);
    cout<<res<<endl;
    res = method2(n, A);
    cout<< res<<endl;

    return 0;
}
