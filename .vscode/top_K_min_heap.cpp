//    Top-K������һ��ʮ�־�������⣬һ�����������ַ�ʽ���������⣺��10�ڵ�������ҳ���������100������������һ������n�������������У��ҳ�����100������

/*
*�������STL�е���С���ȶ���ʵ�֣�����STL���Դ���С���ȶ��У���ײ���Ƕ����ʵ�֣�
*���ԾͲ�����д������ˡ���С���ȶ��ж���Ԫ�����Ƕ�������С��Ԫ�أ�Ҳ���Ƕ���ѶѶ���
*/
 
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
 
/*����STL�Դ����ȶ�����Ĭ��������ȵģ������Լ�д��һ���ȽϺ����������Ϊ��С����*/
struct cmp1 {
	bool operator ()(int &a, int &b) {
		return a<b;											//��Сֵ����
	}
};
 
int main() {
	//�����������ԣ������ʽ����������Ҫ������K�����е�Kֵ������������������
	int K = 0;
	cin >> K;
	int tmp = 0;
	int i = 0;
	priority_queue<int,vector<int>,cmp1> minHeap;			//������С���ȶ���
	while (cin >> tmp) {									//ѭ������������
		if (i < K) {										//�Ƚ���һ��K����С�����ȶ��У�Ҳ����K��С�Ķ����
			minHeap.push(tmp);
		}
		else {												//�㷨ʵ��
			if (tmp <= minHeap.top())
				continue;
			else if (tmp > minHeap.top()) {
				minHeap.pop();
				minHeap.push(tmp);
			}
		}
		i++;
	}
	while (!minHeap.empty()) {								//�������K����
		cout << minHeap.top() << endl;
		minHeap.pop();
	}
	return 0;
}
 