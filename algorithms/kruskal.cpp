#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


const int m = 100; // edge num
const int n = 100; //node num
int w[m];  // edge weights
int r[m];  //sorted edge index
int p[n];  //union find set
int u[m];  //edge(u,v)
int v[m];

//������� ����� ��Ȩ��С�ıߵ��±� �� Ȩ�ش�ıߵ��±�
int cmp(const int i, const int j)
{
	return w[i] < w[j];
}

int findSet(int x)
{
	return x == p[x] ? x : p[x] = findSet(p[x]);
}

int kruskal()
{
	for (int i = 0; i < n; i++) p[i] = i;  //��ʼ����ͨ����
	for (int i = 0; i < m; i++) r[i] = i; //��ʼ�����±�
	sort(r, r + m, cmp); //�������

	int ans = 0;
	for (int i = 0; i < m; i++)
	{
		int e = r[i];
		int x = findSet(u[e]), y = findSet(v[e]);
		if (x != y)
		{
			p[x] = y;
			ans += w[e];
		}
	}
	return ans;
}

int main() {



	system("pause");
	return 0;
}
