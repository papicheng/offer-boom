//  �����������ʹ�ö�̬�滮�㷨
 
#include <iostream>
 
int mat[100][100];
 
int combinat(int m, int n) {
    int i, j;
    
    if(n == 0 || m == n)
        return 1;
    // һ��һ�еļ�����ȥ
    for(j = 0; j <= n; j++) { // ֻҪ����n�о����ˣ����ü�������
        mat[j][j] = 1;
        for(i = j+1; i <= m; i++) {
            if(j == 0)
                mat[i][j] = 1;
            else
                mat[i][j] = mat[i-1][j-1] + mat[i-1][j];
        } // ����Cmn
    }
    return mat[m][n];
}
 
int main(int argc, const char * argv[]) {
    // insert code here...
    int m, n;
    
    std::cout << "�������������m��n:";
    std::cin >> m >> n;
    std::cout << combinat(m, n) << std::endl;
    return 0;
}