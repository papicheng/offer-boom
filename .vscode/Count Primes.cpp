/*���ܣ�
ͳ������С�ڷǸ����� n ��������������

ʾ��:

����: 10
���: 4
����: С�� 10 ������һ���� 4 ��, ������ 2, 3, 5, 7 ��

*/
#include<bits/stdc++.h>

using namespace std;


bool iszhishu(int n){
        int m = sqrt(n);
        for(int i = 2; i <= m; ++i){
            if(n % i == 0){
                return false;
            }
        }
        return true;
    }
    int countPrimes(int n) {
        if( n < 2) return 0;
        int count = 0;
        for( int i = 2; i <= n; ++ i){
            if(iszhishu(i)){
                ++count;
                cout<< i<<"  ";
            }
        }
        return count;
    }

int main()
{
    int n = 10;
    int res = countPrimes(n);
    return 0;
}
