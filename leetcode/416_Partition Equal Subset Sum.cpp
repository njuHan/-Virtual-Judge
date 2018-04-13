#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<unordered_map>
#include<sstream>
#include<numeric>
#include<bitset>
using namespace std;

class Solution {
public:
	bool canPartition(vector<int>& nums) {
		int total = accumulate(nums.begin(), nums.end(), 0);
		if (total & 1) return false; //odd
		arr = nums;
		len = arr.size();
		sort(arr.rbegin(), arr.rend());
		return dfs(0,  total >> 1, total);
	}
	bool dfs(int cur,  int target, int left) //�����left ��֦����Ҫ
	{
		for (int i = cur; i < len; i++)
		{
			left -= arr[i];
			if (arr[i] > target) continue;
			if (arr[i] == target || left == target) return true;
			if (dfs(i + 1, target - arr[i], left)) return true;
			if (left < target) return false;
		}
		return false;
	}
	// dp solution
	// https://leetcode.com/problems/partition-equal-subset-sum/discuss/90592/01-knapsack-detailed-explanation
	bool canPartition2(vector<int>& nums) 
	{
		int total = accumulate(nums.begin(), nums.end(), 0);
		if (total & 1) return false; //odd
		int target = total >> 1;
		int len = nums.size();
		vector<bool> dp(target + 1, 0);
		dp[0] = 1;
		for (int num : nums)
			for (int i = target; i >= num; i--)  //��άdp��Ϊһά��ע��˳��
				dp[i] = dp[i] || dp[i - num]; //������һ�ֵ�dp, �ȸ��´��i, ���ָ��µ�i�����ڱ����ٴ�ʹ��
		return dp[target];                    // ������num == 1 ,dp[2] = dp[1-1], dp[3] = dp[2-1], num�ظ�ʹ����
	}
	//bitset 
	//https://leetcode.com/problems/partition-equal-subset-sum/discuss/90590/simple-c-4-line-solution-using-a-bitset
	bool canPartition3(vector<int>& nums)
	{
		const int maxnum = 100;
		const int maxsize = 200;
		int total = accumulate(nums.begin(), nums.end(), 0);
		if (total & 1) return false; //odd

		//bits �����űߵ�0λ��ʼ�� ��iλ��ʾ������ɺ�Ϊ i ���Ӽ�
		bitset< (maxnum*maxsize >> 1) + 1> bits(1); //��ʼ����Ϊ0���Ӽ�Ϊtrue
		for (int num : nums)
			bits = bits | (bits << num);
		return bits[total >> 1];
	}
private:
	vector<int> arr;
	int len;
};



int main()
{

	vector<int> vec = {1,2,5};
	Solution solu;
	solu.canPartition2(vec);

	system("pause");
	return 0;
}



