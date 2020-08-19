/*¹¦ÄÜ£º¶ÑÅÅÐò*/
#include<bits/stdc++.h>

using namespace std;

void HeapAdjust(int *a, int i, int size){
    int lchild = 2 * i;
    int rchild = 2 * i + 1;
    int max = i;
    if(i <= size / 2){
        if(lchild <= size && a[lchild] > a[max]) max = lchild;
        
    }
}

int main()
{
    
    return 0;
}
