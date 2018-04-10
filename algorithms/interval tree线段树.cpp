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


const int maxn = 101; 
// ȡ�±�1��ʼ
//������� rt, ��������ls = rt<<1, ��������rs = rt<<1|1
int a[maxn]; //Դ�������� 1..n
//sum ��ͣ� add������
int sum[maxn << 2], add[maxn << 2]; //����������4���ռ�

//build tree
void pushUp(int rt)
{
	sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}
void build(int l, int r, int rt) //l,r��ʾ��ǰ�ڵ����䣬rt��ʾ��ǰ�ڵ���  
{
	if (l == r)
	{
		sum[rt] = a[l];
		return;
	}
	int m = l + ((r - l) >> 1); //�м��
	build(l, m, rt << 1);
	build(m+1, r, rt << 1 | 1); //ע������m+1
	pushUp(rt);
}

//���޸�
//a[x] += c;
void update(int x, int c, int l, int r, int rt) //l,r��ʾ��ǰ�ڵ����䣬rt��ʾ��ǰ�ڵ���  
{
	if (l == r)
	{
		sum[rt] += c;
		return;
	}
	int m = l + ((r - l) >> 1);
	if (x <= m) update(x, c, l, m, rt<<1);//������
	else update(x, c, m + 1, r, rt << 1 | 1); //������
	pushUp(rt);
}

//���Ʊ�ǵĺ���
//�����޸��ӽ���sumֵ
void pushDown(int rt, int ln, int rn) //ln,rnΪ��������������������������   
{
	if (add[rt])
	{
		//���Ʊ��
		add[rt << 1] += add[rt];
		add[rt << 1 | 1] += add[rt];
		//�޸��ӽڵ��Sumʹ֮���Ӧ��Add���Ӧ 
		sum[rt << 1] += add[rt] * ln;
		sum[rt << 1 | 1] += add[rt] * rn;
		//������ڵ���   
		add[rt] = 0;
	}
}

//�����޸�
//a[x, y] += c;
void update(int x, int y, int c, int l, int r, int rt)
{
	if ( x<=l && r<=y) //�����������ȫ�ڲ�������[x, y]����,�Ÿ���sum,add
	{
		sum[rt] += c*(r - l + 1); //�������ֺͣ����ϱ�����ȷ  
		add[rt] += c; //����Add��ǣ���ʾ�������Sum��ȷ���������Sum����Ҫ����Add��ֵ������  
		return; //return, ��ʱ������
	}
	int m = l + ((r - l) >> 1);
	pushDown(rt, m - l + 1, r - m); //���Ʊ��  
	//�����ж�����������[L,R]���޽������н����ŵݹ� 
	if (x <= m) update(x, y, c, l, m, rt << 1);
	if (y >= m + 1) update(x, y, c, m + 1, r, rt << 1 | 1);
	pushUp(rt); //���±��ڵ���Ϣ   
}

int query(int x, int y, int l, int r, int rt) //x,y��ʾ�������䣬l,r��ʾ��ǰ�ڵ����䣬rt��ʾ��ǰ�ڵ��� 
{
	if (x <= l && r <= y)
	{
		return sum[rt]; //�������ڣ�ֱ�ӷ���  
	}
	int m = l + ((r - l) >> 1);
	//���Ʊ�ǣ�����Sum���ܲ���ȷ  
	pushDown(rt, m - l + 1, r - m);

	int ans = 0;
	if (x <= m) ans += query(x, y, l, m, rt << 1);
	if (y >= m + 1) ans += query(x, y, m + 1, r, rt << 1 | 1);
	return ans;
}
/*
int main()
{
	int n = 1;
	int x = 1, y = 10;
	int c = 2;
	//����   
	build(1, n, 1);
	//���޸�  
	//update(x, c, 1, n, 1);
	update(1, -1, 1, n, 1);
	
	//�����޸�   
	//update(x, y, c, 1, n, 1);
	//�����ѯ   
	int ans = query(1, 3, 1, n, 1);
	cout << ans;
	system("pause");
	return 0;
}
*/


