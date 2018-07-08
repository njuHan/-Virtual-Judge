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
	int countNumbersWithUniqueDigits(int n) {
		if (n <= 0) return 1;
		// ans[n]: λ��Ϊ0��n��UniqueDigits �ĸ���, ��0����λ��Ϊ0
		//pre[n] : λ��Ϊn�ҵ�һλ��Ϊ0�� niqueDigits �ĸ���
		//n==0, 1�������
		// n==0ʱ��ֻ�� һ�� 0�� ans[0] = 1;
		// n==1ʱ��pre[1]=9, ans[1] = pre[1] + ans[0] = 9+1 =10;
		int ans = 10, pre = 9; //n==1;
		for (int i = 2; i <= min(10, n); i++)
		{
			pre = pre * (10 - i + 1);
			ans = ans + pre;
		}
		return ans;
	}
};