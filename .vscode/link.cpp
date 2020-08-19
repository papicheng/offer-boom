/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
///1 通过快慢指针找到中间节点，
///2 反转后面一半的节点
///3 合并两部分
/*功能：*/
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
        //快慢指针找到中间节点
        ListNode *fast=head;
        ListNode *slow=head;
        while(fast->next&&fast->next->next)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        // cout<<"mid node :"<<slow->val<<endl;
        ///反转后面的节点
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
        ///合并两个链表
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
    link * p=NULL;//创建头指针
    link * temp = (link*)malloc(sizeof(link));//创建首元节点
    //首元节点先初始化
    temp->val = 1;
    temp->next = NULL;
    p = temp;//头指针指向首元节点
    //从第二个节点开始创建
    for (int i=2; i<10; i++) {
     //创建一个新节点并初始化
        link *a=(link*)malloc(sizeof(link));
        a->val=i;
        a->next=NULL;
        //将temp节点与新建立的a节点建立逻辑关系
        temp->next=a;
        //指针temp每次都指向新链表的最后一个节点，其实就是 a节点，这里写temp=a也对
        temp=temp->next;
    }
    //返回建立的节点，只返回头指针 p即可，通过头指针即可找到整个链表
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

