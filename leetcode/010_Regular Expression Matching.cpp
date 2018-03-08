#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;


class Solution {
public:
	bool isMatch(string s, string p) {
		int m = s.size(), n = p.size();
		//dp[i][j]��ʾs��ǰi���ַ��� p�е�ǰj���ַ��Ƿ�ƥ��
		//��s[0...i-1] �� p[0...j-1]ע���±�
		vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
		//dp[0][j]��j>0 ����ƥ�� (p[j-1]=='*')
		//dp[i][0], i>0 ������ƥ��
		//���� ����ʱ��������j==0�����
		//��������Ϊ0���ȿմ�ʱ��ƥ��
		dp[0][0] = true;
		for (int i = 0; i <= m; i++)
			for (int j = 1; j <= n; j++)
			{
				//����i-1ʱ��һ��Ҫ�����ж�i>0 !!!!!!!!!!!!!!
				if (p[j - 1] != '*')
					dp[i][j] = (i>0) && (p[j - 1] == '.' || s[i - 1] == p[j - 1]) && dp[i - 1][j - 1];
				else
					dp[i][j] = dp[i][j - 2] || ( i>0 && (p[j-2]=='.'||s[i - 1] == p[j - 2]) && dp[i - 1][j] );
			}
		return dp[m][n];
	}
};

int main()
{
	system("pause");
	return 0;
}