#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

/*
���������� binary indexed tree (BIT)
��������A1�� A2, ... ,An
֧�����ֲ����� 
Add(x,d): ��Ax ���� d
query(LR): ���� AL+...+AR
*/

const int maxn = 105;
int A[maxn+1]; //��Χ �� [1,maxn]
int C[maxn+1];
// C[i] = A[i-lowbit(i)+1] + ...+ A[i]

//���±� x ��lowebit
int lowbit(int x)
{
	return x&(-x);
}

// ����C �Ķ���Ԥ����C
void getC()
{
	for (int i = 1; i < maxn; i++)
	{
		C[i] = 0;
		for (int j = i - lowbit(i) + 1; j <= i; j++)
		{
			C[i] += A[j];
		}
	}
}

//sum A[1]+...+A[x]
int sum(int x)
{
	int ans = 0;
	while (x>0)
	{
		ans += C[x];
		x = x - lowbit(x);
	}
	return ans;
}

//update A[x]
void add(int x, int d)
{
	while (x<=maxn)
	{
		C[x] += d;
		x = x + lowbit(x);
	}
}

// ʹ�� add Ԥ���� C
// ���� A,C, ִ��maxn�� add
// ���� A
void initC()
{
	for (int i = 1; i <= maxn; i++)
	{
		add(i, A[i]);
	}
}

int main() {



	system("pause");
	return 0;
}
