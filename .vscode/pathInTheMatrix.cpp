/*功能：矩阵中的路径
请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。 例如 \begin{bmatrix} a & b & c &e \\ s & f & c & s \\ a & d & e& e\\ \end{bmatrix}\quad 
   矩阵中包含一条字符串"bcced"的路径，但是矩阵中不包含"abcb"路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。

*/
#include<iostream>

using namespace std;
bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        bool * flag=new bool [rows*cols];
        for(int i=0;i<rows;++i)
        {
            for(int j=0;j<cols;++j)
            {
                if(hasPath(matrix,rows,cols,str,i,j,flag,0))
                    return true;
            }
        }
        delete [] flag;
        return false;
    }
bool hasPath(char* matrix,int rows,int cols,char* str,int i,int j,bool* flag,int k)
{
    int index=i*cols+j;
    if(flag[index]||i<0||i>rows||j<0||j>cols||matrix[index]!=str[k])
        return false;
    if(str[k+1]=='\0')
        return true;
    flag[index]=true;
    if(
        hasPath(matrix,rows,cols,str,i,j+1,flag,k+1)||
        hasPath(matrix,rows,cols,str,i,j-1,flag,k+1)||
        hasPath(matrix,rows,cols,str,i+1,j,flag,k+1)||
        hasPath(matrix,rows,cols,str,i-1,j,flag,k+1))
        return true;
    flag[index]=false;
    return false;
}
int main()
{
    
    return 0;
}
