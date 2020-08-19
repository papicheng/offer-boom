#include<stdio.h>
#include<algorithm>
#include<vector>
#include<stdlib.h>
#include<iostream>
using namespace std;
bool cmp1(const vector<int> &a, const vector<int> &b)
{
	return a[1] > b[1];
}
int main()
{
	vector<vector<int>> viA(10);
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			viA[i].push_back(rand() % 100);
		}
	}
	
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << viA[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "after:" << endl;
 
	//sort(viA.begin(), viA.end(), [](const vector<int> &a, const vector<int> &b) {return a[0] < b[0]; });
 
	sort(viA.begin(), viA.end(), cmp1);
	//for (int i = 0; i < 10; i++)
	//{
		//sort(viA.begin(), viA.end());//默认为从小到大排序
	//}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << viA[i][j] << "\t";
		}
		cout << endl;
	} 
	return 0;
}