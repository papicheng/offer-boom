//  计算组合数：使用动态规划算法
 
#include <iostream>
 
int mat[100][100];
 
int combinat(int m, int n) {
    int i, j;
    
    if(n == 0 || m == n)
        return 1;
    // 一列一列的计算下去
    for(j = 0; j <= n; j++) { // 只要计算n列就行了，不用计算后面的
        mat[j][j] = 1;
        for(i = j+1; i <= m; i++) {
            if(j == 0)
                mat[i][j] = 1;
            else
                mat[i][j] = mat[i-1][j-1] + mat[i-1][j];
        } // 计算Cmn
    }
    return mat[m][n];
}
 
int main(int argc, const char * argv[]) {
    // insert code here...
    int m, n;
    
    std::cout << "请输入组合数的m和n:";
    std::cin >> m >> n;
    std::cout << combinat(m, n) << std::endl;
    return 0;
}