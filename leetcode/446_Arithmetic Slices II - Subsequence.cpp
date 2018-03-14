#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
using namespace std; 
class Solution {
public:
	// ����˼·�����ö�άdp����ˢ��dp[i][j]����ʾ��i��β��Ԫ�ز�Ϊj�Ĵ��ĸ���
	// ��ΪԪ�ز���ܴܺ������и���j��ά�Ȳ��ø�
	// ����solution���õ�vector<map>, ������
	// ��Ҫע�� INT_MIN - INT_MAX ��int������������ʱ����Ҫ��long long delt
	//����������Ԫ�صĴ� https://leetcode.com/problems/arithmetic-slices-ii-subsequence/solution/
	int numberOfArithmeticSlices(vector<int>& A) {
		int len = A.size();
		if (len < 3) return 0;
		vector<map<long long, int>> dp(len);
		int ans = 0;
		for (int i = 1; i < len; i++)
		{
			for (int j = 0; j < i; j++)
			{
				long long delt = (long long)A[j] - (long long)A[i];
				int sum = 0;
				if (dp[j].count(delt) != 0)
				{
					sum = dp[j][delt];
				}
				ans += sum; //��i��β������3��Ԫ���Ӵ�����
				dp[i][delt] += sum + 1; //��i��β������2��Ԫ���Ӵ�����
				//2����3����ֻ��ȥ��A[i-1]A[i]��һ��Ԫ��
			}
		}
		return ans;
	}
};
int main()
{
	Solution solu;
	vector<int> A = { 2, 4, 6, 8, 10 };
	int ans = solu.numberOfArithmeticSlices(A);
	printf("%d", ans);
	system("pause");
	return 0;
}