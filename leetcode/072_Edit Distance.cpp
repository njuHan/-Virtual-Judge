#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>
using namespace std;

class Solution {
public:
	int minDistance(string word1, string word2) {
		int m = word1.size();
		int n = word2.size();
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
		//dp[i][j]�� word1 ѡi����ĸ��word2ѡj����ĸ��ת�������̾���
		dp[0][0] = 0;
		for (int i = 1; i < m + 1; i++) dp[i][0] = i;
		for (int j = 1; j < n + 1; j++) dp[0][j] = j;
		
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++)
			{
				if (word1[i - 1] == word2[j - 1])
					dp[i][j] = dp[i - 1][j - 1];
				else
				{
					// �ģ� ɾ �� ��
					dp[i][j] = min(dp[i - 1][j - 1]+1, min(dp[i - 1][j]+1, dp[i][j - 1]+1));
				}
			}
		return dp[m][n];
	}
};

int main()
{
	Solution solu;

	int ans = solu.minDistance("abcd", "fgh");
	printf("%d\n", ans);
	system("pause");
	return 0;
}