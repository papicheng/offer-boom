#include<bits/stdc++.h>

using namespace std;

//����һ��Ͱ
vector<int> buket(1001, 0);
//Ͱ����
void buket_sort(vector<int> &arr){
    for(auto i : arr){
        buket[i]++;//��¼ÿ�������ֵĴ���
    }
    for(int i = 0 , j = 0; i < buket.size(); ++i){
        if(buket[i] != 0){
            for(int k = 0; k < buket[i]; ++k){
                arr[j++] = i;
            }
        }
    }
}
//ð������
void bubble_sort(vector<int> &arr){
    for(int i = 0; i < arr.size(); ++i){
        int flag = 0; ///�Ż�������Ѿ��ĺ����ˣ�����ľͲ���Ҫѭ����
        for(int j = 0; j < arr.size() - i - 1; ++j){
            if(arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
                flag = 1;
            }
        }
        if(flag == 0){
            break;
        }
    }
}

//ѡ������
void select_sort(vector<int> &arr){
    for(int i = 0; i < arr.size();++i){
        int min_index = i;
        for(int j = i + 1; j < arr.size();++j){
            if(arr[min_index] > arr[j]){
                min_index = j;
            }
        }
        swap(arr[i],arr[min_index] );
    }
}
void print(vector<int>& arr){
    for(auto i:arr){
        cout<<i<<" ";
    }
}
//��������
void insert_sort(vector<int>& arr){
    for(int i = 1; i < arr.size(); ++i){
        int preindex = i - 1;
        int current = arr[i];
        while(preindex >= 0 && arr[preindex] > current){
            arr[preindex + 1] = arr[preindex];
            preindex--;
        }
        arr[preindex + 1] = current;
    }
}

//�鲢����
void merge_sort(vector<int>& arr, int left, int right){
    //���õݹ�߽�
    if(left == right){
        return;
    }
    int mid = (right - left)/ 2 + left;
    //���������������������������
    merge_sort(arr, left, mid);
    merge_sort(arr,mid + 1, right);
    int lp = left, rp = mid + 1, index = 0;
    vector<int> brr(arr.size());
    //�ϲ���������
    while(lp <= mid && rp <= right){
        if(arr[lp] < arr[rp]){
            brr[index] = arr[lp];
            ++lp;
        }
        else{
            brr[index] = arr[rp];
            ++rp;
        }
        ++index;
    }
    //����������ʣ�������װ��b����
    while(lp <= mid){
        brr[index++] = arr[lp++];
    }
    while(rp <= right){
        brr[index++] = arr[rp++];
    }
    //��b���鸳ֵ��ԭ��������
    for(int i = left; i <= right ;++i){
        arr[i] = brr[i - left];
    }
}
void mergesort(vector<int> &a,int l,int r)
{
    //���õݹ�߽�
    if(l==r)
    {
        return;
    }
    //�����������������ų������
    int m=(l+r)>>1;
    mergesort(a,l,m);
    mergesort(a,m+1,r);
    int lp=l,rp=m+1,s=0;
	vector<int>b(a.size());
    ///�ϲ�����������
    while(lp<=m&&rp<=r)
    {
        if(a[lp]<a[rp])
        {
            b[s]=a[lp];
            ++lp;
        }
        else
        {
            b[s]=a[rp];
            ++rp;
        }
        ++s;
    }
    //����������ʣ�������װ��b����
    while (lp<=m)
    {
        b[s]=a[lp];
        ++lp;
        ++s;
    }
    while(rp<=r)
    {
        b[s]=a[rp];
        ++rp;
        ++s;
    }
    //��b���鸳ֵ��ԭ��������
    for(int i=l;i<=r;++i)
    {
        a[i]=b[i-l];
    }
}
int main(){
    vector<int> arr = {4,1,3,6,7,3,5,8,8,23,4,6,4,352};
    // buket_sort(arr);
    // cout<<"buket_sort: ";

    // cout<<"bubble: ";
    // bubble_sort(arr);

    // cout<<"select: ";
    // select_sort(arr);

    // cout<<"insert: ";
    // inset_sort(arr, 0, arr.size() - 1);

    cout<<"merge_sort:";
    merge_sort(arr, 0, arr.size() - 1);

    print(arr);
    return 0;
}