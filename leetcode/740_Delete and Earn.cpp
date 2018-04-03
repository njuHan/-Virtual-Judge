#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<unordered_map>
using namespace std;


class Solution {
public:
	//����buckets[i], takei�������skip[i-1]
	//skipi, ���Ի���take[i-1] �� skip[i-1]
	int deleteAndEarn(vector<int>& nums) {
		if (nums.size() < 1) return 0;
		map<int, int> buckets;
		for (int num : nums)
		{
			buckets[num] += num;
		}
		//�ҵ���С����num
		int mini = buckets.begin()->first;
		int maxi = buckets.rbegin()->first;

		//֮ǰ��ȡ��ȡ��ֵ
		int take = 0, skip = 0;
		//��ǰȡ ���� ��ȡ
		int takeCur, skipCur;
		for (int i = mini; i<=maxi; i++)
		{
			takeCur = skip + buckets[i];
			skipCur = max(take, skip);
			take = takeCur;
			skip = skipCur;
		}
		return max(take, skip);
	}
};


int main()
{

	

	system("pause");
	return 0;
}



