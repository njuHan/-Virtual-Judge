#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	//O(n*n) 
	bool isMatch2(string s, string p) {
		int m = s.size(), n = p.size();
		vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
		// dp[i][j] : s[0,...,i-1] ƥ�� p[0,...,j-1]
		dp[0][0] = 1;
		for (int i = 0; i <= m; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (p[j - 1] != '*')
				{
					dp[i][j] = (i > 0) && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '?');
				}
				else
				{
					// * match empty || match at least 1 char
					dp[i][j] = dp[i][j - 1] || ((i > 0) && dp[i - 1][j]);
				}
			}
		}
		return dp[m][n];
	}
	//greedy linear runtime, ���ݵ�˼�룬��¼����'*'ʱ�� i,j�� ���ݳ���'*'ƥ��0,1,2,3,4...��s���ַ�
	bool isMatch(string s, string p) 
	{
		int m = s.size(), n = p.size();
		int i = 0, j = 0, star = -1, tomatch; //tomatch ��ʾ * ��һ������ƥ���s[i]
		while (i<m)  //���� s
		{
			if (s[i] == p[j] || p[j] == '?')
			{
				i++;
				j++;
			}
			else if (p[j] == '*')
			{
				tomatch = i;
				star = j++;
			}
			else if (star != -1) //��ǰ s[i] p[j]��ƥ�䣬 ���� * ��ƥ��һ�� s[tomatch]
			{
				i = ++tomatch;
				j = star + 1;
			}
			else return false;
		}
		while (j<n && p[j]=='*')
		{
			j++;
		}
		return j == n;
	}
};

int main() {



	system("pause");
	return 0;
}
