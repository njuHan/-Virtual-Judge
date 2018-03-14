#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int maxA(int N)
	{
		vector<int> dp(N + 1);
		dp[1] = 1;
		for (int i = 2; i <= N; i++)
		{
			//һ�� A
			dp[i] = dp[i - 1] + 1; 
			// clt+a. clt+c, clt+v
			for (int step = 3; step < i; step++) //������step�����ҵ�dp[i-step]
			{
				// �� i ��Ϊճ��
				//������3����ȫѡ�����ơ�ճ��
				//dp[i] = min(dp[i], dp[i - step] + dp[i - step] * (step-2)); 
				dp[i] = max(dp[i], dp[i - step] * (step - 1));
			}
		}
		return dp[N];
	}
};

int main()
{
	Solution solu;
	int ans = solu.maxA(7);
	printf("%d", ans);
	system("pause");
	return 0;
}