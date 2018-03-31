
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<unordered_map>
#include<stack>
#include<algorithm>
#include<queue>
using namespace std;

class Solution {
public:
	//1. ��� nums[0,...,i-1], ���Թ���[0,miss)������
	//��ô���� nums[i]�� ���Թ���[0,miss+nums[i])����
	// 2. ��� nums[i]<=miss, ��ônums[i]����nums[0,...,i-1]�е�һЩ�����϶����Թ����Ϊ miss��������ʱmiss����Ϊ miss+nums[i], i++
	// 3. ��� nums[i]>miss ,�޷�����miss, ̰�����miss������� ����miss = miss + miss
	int minPatches(vector<int>& nums, int n) 
	{
		/*
		case :
		[1,2,31,33]
		2147483647
		ʹ��long long ��ֹ���
		*/
		long long  miss = 1, ans = 0, i = 0;
		while (miss <= n)
		{
			if (i<nums.size() && nums[i] <= miss)
			{
				miss += nums[i++];
			}
			else
			{
				miss += miss;
				ans++;
			}
		}
		return ans;
	}
};

int main()
{
	Solution solu;

	return 0;
}