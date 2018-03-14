#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int minSteps(int n) {
		vector<int> dp(n + 1, 0);
		dp[1] = 0;
		for (int i = 2; i <= n; i++)
		{
			dp[i] = i; //��������i��ÿ��ֻճ��һ�� A
			for (int j = i - 1; j > 1; j--) //�����������ÿ��ճ������2��A
			{
				if (i%j == 0)
				{
					dp[i] = dp[j] + i / j;
					break;
				}
			}
		}
		return dp[n];
	}
};

int main()
{
	Solution solu;
	int ans = solu.minSteps(12);
	printf("%d", ans);
	system("pause");
	return 0;
}