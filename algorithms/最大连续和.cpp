#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<unordered_map>
using namespace std;

const int maxn = 100;
int a[maxn];
//sum a[l] + ... + a[r]

//O(n*n) 
//S[i] = a[0]+...+a[i-1], ��0��ʼ����i��Ԫ��
int s[maxn];
int maxsum(int l, int r)
{
	s[0] = 0;
	for (int i = 1; i <= maxn; i++) s[i] = s[i - 1] + a[i-1];
	int sum = s[1];
	for (int i = 1; i <= maxn; i++)
		for (int j = 0; j < i; j++)
			sum = max(sum, s[i] - s[j]);
	return sum;
}

//���ֵݹ� O(nlogn)
int maxsum(int l, int r) //����ҿ�����[l,r)�����������
{
	if (1 == r - l) return a[l];
	//���֣�
	int m = l + (r - l) / 2; //[l,m) , [m, r)
	int best = max(maxsum(l, m), maxsum(m, r));
	//���м��m�����������
	int lhs = a[m-1], rhs = a[m]; //ע�������ʼ������Ϊ0,��ֹ��������
	int suml=0, sumr=0;
	//�ⲿ�ֿ���ֻҪO(1)�� 	//https://leetcode.com/problems/maximum-subarray/discuss/20360/C++-An-clear-O(n)-divide-and-conquer-solution-with-comments
	for (int i = m - 1; i >= l; i--) 
	{
		lhs = max(lhs, suml += a[i]);
	}
	for (int i = m; i < r; i++)
	{
		rhs = max(rhs, sumr += a[i]);
	}
	best = max(best, lhs + rhs);
	return best;
}

int main()
{



	system("pause");
	return 0;
}



