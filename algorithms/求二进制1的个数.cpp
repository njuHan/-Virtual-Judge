#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<stack>
#include<algorithm>
using namespace std;


int cntOne1(int x)
{
	int cnt = 0;
	while (x!=0)
	{
		cnt++;
		x = x&(x - 1);
	}
	return cnt;
}
//˼�룺��1��1�����������㣬��ʵ�����Ͳ���1�ˣ���n��ÿλ����λ�룬���ж�1�ĸ���
int cntOne2(int x)
{
	int cnt = 0;
	int flag = 1;
	while (flag!=0)
	{
		if (flag&x)
			cnt++;
		flag = flag << 1;
	}
	return cnt;
}
int cntOne3(int x)
{
	int cnt = 0;
	unsigned int temp = (unsigned int)x;
	while (temp!=0)
	{
		if (temp & 1) cnt++;
		temp = temp >> 1;
	}
	return cnt;
}

int main()
{
	int x = -30;
	cout << cntOne1(x) << endl;
	cout << cntOne2(x) << endl;
	cout << cntOne3(x) << endl;
	system("pause");
}