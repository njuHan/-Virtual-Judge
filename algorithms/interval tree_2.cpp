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

#define lson(rt) (rt<<1)
#define rson(rt) (rt<<1|1)
#define mid(l,r) (l + ((r-l)>>1))

const int maxn = 100;
int a[maxn], sum[maxn << 2], add[maxn << 2];

//���ϸ��½��
void pushUp(int rt)
{
	sum[rt] = sum[lson(rt)] + sum[rson(rt)];
}
//������������±��
void pushDown(int rt, int ln, int rn)
{
	if (add[rt])
	{
		add[lson(rt)] += add[rt];
		add[rson(rt)] += add[rt];
		sum[lson(rt)] += ln*add[lson(rt)];
		sum[rson(rt)] += rn*add[rson(rt)];
		add[rt] = 0;
	}
}

//����
void build(int l, int r, int rt)
{
	if (l == r)
	{
		sum[rt] = a[l];
		return;
	}
	int m = mid(l, r);
	build(l, m, lson(rt));
	build(m + 1, r, rson(rt));
	pushUp(rt);
}

//�������޸�
void update(int x, int c, int l, int r, int rt) //��Ч����ʱ����x������[l,r]��
{
	if (l==r) //Ҷ��㣬ֱ���޸�
	{
		sum[rt] += c;
		return;
	}
	int m = mid(l, r);
	pushDown(rt, m - l + 1, r - m);
	if (x <= m) update(x, c, l, m, lson(rt));
	else update(x, c, m + 1, r, rson(rt));
	pushUp(rt);
}

//���������޸� [x,y]�������+c
void update(int x, int y, int c, int l, int r, int rt) 
{
	if (x <= l && r <= y) //��ȫ���Ǹý������
	{
		sum[rt] += c * (r - l + 1);
		add[rt] += c;
		return;
	}
	int m = mid(l, r);
	//�����Ŀ���ǵ��޸ĺ������޸Ļ�ϵĻ�����ô���޸���Ҳ��ҪPushDown��
	pushDown(rt, m - l + 1, r - m);
	if (x <= m) update(x, y, c, l, m, lson(rt));
	if (y >= m + 1) update(x, y, c, m + 1, r, rson(rt));
	pushUp(rt);
}

int query(int x, int y, int l, int r, int rt)
{
	if (x <= l && r <= y)
	{
		return sum[rt];
	}
	int m = mid(l, r);
	pushDown(rt, m - l + 1, r - m);
	int ans = 0;
	if (x <= m) ans += query(x, y, l, m, lson(rt));
	if (y >= m + 1) ans += query(x, y, m + 1, r, rson(rt));
	return ans;
}

int main()
{
	int n = 3;
	build(0, n - 1, 1);
	update(0, n - 1, 2, 0, n - 1, 1);
	update(0, 2, 0, n - 1, 1);
	
	int ans = query(0, n-1,0,  n - 1, 1);
	cout << ans;
	system("pause");
	return 0;
}



