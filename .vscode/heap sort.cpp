/*功能：实现堆排序*/
//还有点bug
#include<bits/stdc++.h>

using namespace std;

const int maxn = 100;
int heap[maxn], n = 10;
//对heap数组在[low, high]范围进行向下调整
//其中low为欲调整的数组下标，high一般为堆的最后一个元素的数组下标
//大顶堆
void downAjust(int low, int high){
    int i = low, j = i * 2;//i为欲调整节点，j为其左孩子
    while(j <= high){//存在孩子节点
        //如果右孩子存在，且右孩子的值大于左孩子
        if(j + 1 <= high && heap[j + 1] > heap[j]){
            j = j + 1;
        }
        if(heap[j] > heap[i]){//孩子中最大的权值比欲调整节点i大
            swap(heap[j] , heap[i]);
            i = j;//保持i为欲调整节点，j为i的左孩子
            j = i * 2;
        }
        else break;//孩子的权值均比欲调整节点i小，调整结束
    }
}
//建堆
void createHeap(){//倒着枚举保证大顶堆
    for(int i = n / 2;i >=1 ; i--){
        downAjust(i, n);
    }
}
//删除堆顶元素
void deleteTop(){
    heap[1] = heap[n--];//用最后一个元素覆盖堆顶元素，并让元素个数减一
    downAjust(1, n);//向下调整堆顶元素
}
/////////////////////
//对heap数组在[low, high]范围进行向上调整
//其中low一半设置为1， high表示与调整结构的数组下标
void upAdjust(int low, int high){
    int i = high, j = i / 2;//i为欲调整节点，j为其父亲
    while(j >= low){
        if(heap[j] < heap[i]){
            swap(heap[j] , heap[i]);
            i = j;
            j = i / 2;
        }
        else
        {
            break;
        }
        
    }
}

//添加元素
void insert(int x){
    heap[++n] = x;
    upAdjust(1, n);
}
void print(){
    for(int i = 0; i< n; ++i){
        cout<<heap[i] <<" ";
    }
    cout<< endl;
}
//堆排序
void heapSort(){
    createHeap();
    print();
    for(int i = n; i> 1;i--){
        swap(heap[i], heap[1]);
        downAjust(1, i - 1);
    }
    print();
}
int main()
{   
    srand(0);
    for(int i = 0 ;i < n; ++i){
        heap[i] = rand() % 100;
    }
    heapSort();
    return 0;
}
