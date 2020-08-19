/*���ܣ�ʵ�ֶ�����*/
//���е�bug
#include<bits/stdc++.h>

using namespace std;

const int maxn = 100;
int heap[maxn], n = 10;
//��heap������[low, high]��Χ�������µ���
//����lowΪ�������������±꣬highһ��Ϊ�ѵ����һ��Ԫ�ص������±�
//�󶥶�
void downAjust(int low, int high){
    int i = low, j = i * 2;//iΪ�������ڵ㣬jΪ������
    while(j <= high){//���ں��ӽڵ�
        //����Һ��Ӵ��ڣ����Һ��ӵ�ֵ��������
        if(j + 1 <= high && heap[j + 1] > heap[j]){
            j = j + 1;
        }
        if(heap[j] > heap[i]){//����������Ȩֵ���������ڵ�i��
            swap(heap[j] , heap[i]);
            i = j;//����iΪ�������ڵ㣬jΪi������
            j = i * 2;
        }
        else break;//���ӵ�Ȩֵ�����������ڵ�iС����������
    }
}
//����
void createHeap(){//����ö�ٱ�֤�󶥶�
    for(int i = n / 2;i >=1 ; i--){
        downAjust(i, n);
    }
}
//ɾ���Ѷ�Ԫ��
void deleteTop(){
    heap[1] = heap[n--];//�����һ��Ԫ�ظ��ǶѶ�Ԫ�أ�����Ԫ�ظ�����һ
    downAjust(1, n);//���µ����Ѷ�Ԫ��
}
/////////////////////
//��heap������[low, high]��Χ�������ϵ���
//����lowһ������Ϊ1�� high��ʾ������ṹ�������±�
void upAdjust(int low, int high){
    int i = high, j = i / 2;//iΪ�������ڵ㣬jΪ�丸��
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

//���Ԫ��
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
//������
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
