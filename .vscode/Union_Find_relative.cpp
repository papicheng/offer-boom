/*���ܣ�*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <sstream>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <math.h>

using namespace std;

/*
���룺
6 5 3
1 2
1 5
3 4
5 2
1 3
1 4
2 3
5 6

�����
Yes
Yes
No
*/


using namespace std;
int n,m,q,f[10010],c,d,a,b;
int fd(int x)//�ҳ�x�ҵĴ��� Ҳ���Ƕ����������Ƚڵ�
{
	if(f[x]==x)//x��x�İְ֣��򵥵���˵����xû�ְ���
    
    //���Ǽ������Ĵ��У����Է��ص�x����������������Ƚڵ�
	return x;
	else 
	return  f[x]=fd(f[x]);//x�������Լ��İְ֣����������滹
    //�аְ֣����ǵ�Ŀ�������Ƚڵ㣬�������Ǵ�ʱҪ����������
    //�ְֵİְ���˭������ʹ��һ��fd��find����������ʵ����һ���ݹ����
}
void hb(int x,int y)
{
	f[fd(y)]=fd(x);//�ϲ�x�Ӽ���y�Ӽ���ֱ�Ӱ�x�Ӽ������Ƚ�
    //����y�Ӽ������Ƚڵ�����������ͨ�׵���˵���ǰ�x�������
    //�ȱ��y�Ӽ�������ȵİְ�
	return ;
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)
	f[i]=i;
	for(int i=1;i<=m;i++)
	{
	     scanf("%d%d",&c,&d);
	     hb(c,d);
	}
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d",&a,&b);
		if(fd(a)==fd(b))//���a�����Ӽ��Ĵ���[ǰ���Ѿ����͹���]��b�����Ӽ��Ĵ���һ��������֪a��b��ͬһ������
		printf("Yes\n");
		else
		printf("No\n");
	}
	return 0;
}
