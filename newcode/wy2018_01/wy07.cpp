#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>
#include<string>
#include<sstream>
#include<iterator>
#include<stack>
#include<string.h>
#include<algorithm>
using namespace std;

const int maxn = 2005;
int dp[maxn][maxn];
int v[maxn];

int main()
{
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> v[i];
	dp[0][0] = 0;


	//����ֻ��һ���˳���϶��������Ž⡣�������һ��forѭ����ȷ��������������ĳ�ֵ
	//dp[i][0]���ڶ����˳���һ��������һ���˳�����������
	//dp[i][i - 1]����һ���˳������һ�������ڶ����˳�ǰ��������
	for (int i = 2; i < n; i++)
	{
		dp[i][0] = dp[i - 1][0] + abs(v[i] - v[i - 1]);
		dp[i][i - 1] = dp[i - 1][i - 2] + abs(v[i - 1] - v[i - 2]);
	}

	for (int i = 2; i < n; i++)
	{
		for (int j = 0; j < i - 1; j++)
		{
			// because i-1 < j, so j<i-1 in for
			dp[i][j] = dp[i - 1][j] + abs(v[i] - v[i - 1]);
			dp[i][i - 1] = min(dp[i][i - 1], dp[i - 1][j] + abs(v[i] - v[j]));
		}
	}
	int ans = dp[n - 1][0];
	for (int i = 1; i < n - 1; i++)
		ans = min(ans, dp[n - 1][i]);
	cout << ans;
	//system("pause");
	return 0;
}