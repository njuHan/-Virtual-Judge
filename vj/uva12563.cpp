#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 51;
const int maxt = maxn * 180 + 678;
//ʵ��d[maxn][maxt]�����ڵ���ֻ��Ҫ��¼��һ�����Ϣ������ֻ��Ҫ����
//d[i][j]��ʾ: �ӵ�1,2...i�׸���ѡ���ܿɳ�ʱ��Ϊj,��ô������೪d[i][j]��
int d[2][maxt];
int len[maxn];
int main()
{
	int kase, T;
	scanf("%d", &T);
	for (kase = 1; kase <= T; kase++)
	{
		int n, t;
		scanf("%d%d", &n, &t);
		for (int i = 1; i <= n; i++)
			scanf("%d", &len[i]);
		//����d[0][i],�����������һ��ʼ�ͳ������ܿ�ʼ�п���ʱ��
		//���Ե�i������0ʱ��d[0][i]����ȡ������Ϊ-1��
		//for (int i = 0; i < maxt; i++) d[0][i] = 0;
		//����d[0][i]������0����ô�ᵼ����ʱ��䳤�������˿���ʱ�䣩����ʱ�䣺t-1+678
		memset(d, -1, sizeof(d));
		d[0][0] = 0;
		int p = 1, ans = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < t; j++) //ע�����ﲻȡ=t
			{
				d[p][j] = d[p ^ 1][j]; //��ѡ��i�׸�
				if (j >= len[i] && d[p ^ 1][j - len[i]] != -1)
				{
					d[p][j] = max(d[p][j], d[p ^ 1][j - len[i]] + 1);
				}
				ans = max(ans, d[p][j]);
			}
			p = p^1; 
		}
		for (int i = t - 1; i >= 0; i--)
		{
			if (d[p^1][i] == ans)
			{
				printf("Case %d: %d %d\n", kase, ans + 1, i + 678);
				break;
			}
		}
	}
	//system("pause");
	return 0;

}