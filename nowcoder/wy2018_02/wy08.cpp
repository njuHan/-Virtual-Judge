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

int dp[15][100005];

//dp[i][j]��ʾ����״̬�ռ䣬����i(1 <= i <= n)��ʾ���еĳ��ȣ�j(1 <= j <= k)��ʾ���г���Ϊi��������j��β���Ϸ����еĸ���
//���ƹ�ϵ�У�dp[i][j] += dp[i - 1][m](1 <= m <= k, ����(m, j)�Ǹ��Ϸ�������)��
//����ֱ�Ӱ��յ��ƹ�ϵ��������forѭ���ᳬʱ��Ϊ�˿����Ƚ�����Ϊi - 1�ĺϷ��������(��Ϊsum)��
//Ȼ��������г���Ϊi��ÿһ��j��������г���Ϊi - 1ʱ�Ƿ������и�������Ϊinvalid��, ����dp[i][j] = sum - invalid��
//����invalid��ȡ�����Բ�������ɸѡ���㷨��ʱ�临�Ӷȴ��ΪO(nkloglogk)

//����λ�����ڵ�������A��B(A��Bǰ),������(A <= B)��(A mod B != 0)(������һ����)
// dp[i][j] += dp[i - 1][m] �൱��m�������j,
//�����жϷǷ�ʱ��ֻ�迼�� m>j && m%j==0; ���� m = p*j (p>=2)

const int mod = 1000000007;
int main()
{
	int n, k;
	cin >> n >> k;
	//��ʼ�� dp[1][j] = 1;
	for (int j = 1; j <= k; j++)
		dp[1][j] = 1;

	for (int i = 2; i <= n; i++)
	{
		int sum = 0; //��ͳ���Ϊ i-1�ĺϷ����еĸ���
		for (int j = 1; j <= k; j++)
			sum = (sum + dp[i - 1][j])%mod;
		//�� dp[i][j]
		for (int j = 1; j <= k; j++)
		{
			//invalid: dp[i-1][p*j] (p>=2)
			int invalid = 0;
			int p = 2;
			while (p*j <= k)
			{
				invalid = (invalid + dp[i - 1][p*j]) % mod;
				p++;
			}
			dp[i][j] = (sum - invalid + mod) % mod; //С�ĸ���
		}
	}
	int sum = 0;
	// sum dp[n][i]
	for (int i = 1; i <= k; i++)
		sum = (sum + dp[n][i]) % mod;
	cout << sum;
	system("pause");
	return 0;
}


