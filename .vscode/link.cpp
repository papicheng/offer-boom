/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
///1 ͨ������ָ���ҵ��м�ڵ㣬
///2 ��ת����һ��Ľڵ�
///3 �ϲ�������
/*���ܣ�*/
#include<iostream>
#include<malloc.h>
using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };


#define link ListNode

class Solution {
public:
    void reorderList(ListNode *head) {
        if(!head||!head->next) return;
        //����ָ���ҵ��м�ڵ�
        ListNode *fast=head;
        ListNode *slow=head;
        while(fast->next&&fast->next->next)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        // cout<<"mid node :"<<slow->val<<endl;
        ///��ת����Ľڵ�
        ListNode *after=slow->next;
        slow->next=NULL;
        ListNode *pre=NULL;
        while(after)
        {
            ListNode* temp=after->next;
            after->next=pre;
            pre=after;
            after=temp;
        }
        ///�ϲ���������
        ListNode *first =head;
        after=pre;
        while(first &&after)
        {
            ListNode * aftertemp=after->next;
            ListNode * firsttemp=first->next;
            first->next=after;
            first=firsttemp;
            after->next=first;
            after=aftertemp;
        }
    }
};

link * initLink()
{
    link * p=NULL;//����ͷָ��
    link * temp = (link*)malloc(sizeof(link));//������Ԫ�ڵ�
    //��Ԫ�ڵ��ȳ�ʼ��
    temp->val = 1;
    temp->next = NULL;
    p = temp;//ͷָ��ָ����Ԫ�ڵ�
    //�ӵڶ����ڵ㿪ʼ����
    for (int i=2; i<10; i++) {
     //����һ���½ڵ㲢��ʼ��
        link *a=(link*)malloc(sizeof(link));
        a->val=i;
        a->next=NULL;
        //��temp�ڵ����½�����a�ڵ㽨���߼���ϵ
        temp->next=a;
        //ָ��tempÿ�ζ�ָ������������һ���ڵ㣬��ʵ���� a�ڵ㣬����дtemp=aҲ��
        temp=temp->next;
    }
    //���ؽ����Ľڵ㣬ֻ����ͷָ�� p���ɣ�ͨ��ͷָ�뼴���ҵ���������
    return p;
}
void print( link *head)
{
    while (head)
    {
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
}
int main()
{
    link *p=initLink();
    link *head=p;
    print(head);
    Solution s;
    s.reorderList(head);
    print(head);
    return 0;
}

