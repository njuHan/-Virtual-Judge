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

class NumArray {
public:
	NumArray(vector<int> nums) {
		a = nums;
		n = nums.size();
		if (n > 0)
		{
			sum = vector<int>(n << 2, 0);
			add = vector<int>(n << 2, 0);
			build(0, n-1, 1);
		}
	}

	void update(int i, int val) {
		if (n < 1) return;
		int c = val - a[i];
		update(i, c, 0, n-1, 1);
	}

	int sumRange(int i, int j) {
		if (n < 1) return 0;
		return query(i, j, 0, n-1, 1);
	}
private:
	int n;
	vector<int> a;
	vector<int> sum;
	vector<int> add;

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
		build(m + 1, r, rt << 1 | 1); //ע������m+1
		pushUp(rt);
	}

	//���޸�
	//a[x] += c;
	void update(int x, int c, int l, int r, int rt) //l,r��ʾ��ǰ�ڵ����䣬rt��ʾ��ǰ�ڵ���  
	{
		if (l == r)
		{
			sum[rt] += c;
			a[l] += c;
			return;
		}
		int m = l + ((r - l) >> 1);
		if (x <= m) update(x, c, l, m, rt << 1);//������
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
		if (x <= l && r <= y) //�����������ȫ�ڲ�������[x, y]����,�Ÿ���sum,add
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

};

int main()
{
	NumArray num(vector<int>{-1});
	int ans;
	ans = num.sumRange(0, 0);
	cout << ans;
	num.update(0, 1);
	ans = num.sumRange(0, 0);
	cout << ans;
	system("pause");
	return 0;
}