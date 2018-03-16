#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

class Solution {
public:
	bool canIWin(int maxChoosableInteger, int desiredTotal) {
		if (desiredTotal < 1) return true; //��һ���˲���Ҫѡ���Ѿ��ﵽҪ��Ҳ��Ӯ��
		int sum = (1 + maxChoosableInteger)*maxChoosableInteger >> 1;
		if (sum < desiredTotal) return false;
		if (sum == desiredTotal) return maxChoosableInteger % 2==1;
		vector<int> table(1 << maxChoosableInteger, 0);
		return dfs(table, 0, maxChoosableInteger, desiredTotal);
	}
	// ��bitmap״̬��ʼѡ����ˣ��Ƿ��ܹ�Ӯ
	bool dfs(vector<int>& table, int bitmap, int m, int d)
	{
		if (table[bitmap] != 0) return table[bitmap]>0; //����
		if (d <= 0) return false; //�����Ѿ�����ҪdesiredTotal�ˣ�����һ�����Ѿ�win�����ڿ�ʼѡ����lose
		for (int i = 0; i < m; i++)
		{
			if (bitmap & 1 << i) //ѡ���ظ���λ
				continue;
			if (dfs(table, bitmap | 1 << i, m, d - i-1) == false) //��һ����ѡ������
			{
				table[bitmap] = 1; //��ǰ��Ӯ��
				return true;
			}
		}
		table[bitmap] = -1; 
		return false;
	}
};

int main()
{
	Solution solu;
	bool ans = solu.canIWin(10, 12);
	
	cout << ans << endl;
	system("pause");
	return 0;
}