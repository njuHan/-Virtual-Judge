#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<set>
#include<list>
#include<sstream>
#include<functional>
using namespace std;


class Solution {
public:
	//1��n ѡ��һ����i��ʼ�£�i��[1,n]�п�ʼ�µĴ�����С min
	//ѡ��i�󣬱�֤����·��������Ӯ����Ҫȡ��������·�� max
	int getMoneyAmount(int n) {
		dp = vector<vector<int>>(n + 1, vector<int>(n + 1, -1));
		return search(1, n);
	}
private:
	vector<vector<int>> dp;
	//[x,y]
	int search(int x, int y)
	{
		if (x >= y) return 0;  //����
		int& ans = dp[x][y];
		if (ans > 0) return ans;
		ans = INT_MAX;
		for (int i = x; i <= y; i++)
		{
			ans = min(ans,i + max(search(x, i - 1), search(i + 1, y)));
		}
		return ans;
	}
};