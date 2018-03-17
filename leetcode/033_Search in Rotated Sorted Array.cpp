#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<stack>
#include<algorithm>
using namespace std;

//���۰뷨������target��low high mid �ϵ�Ԫ�ش�С����������̫�࣬��������
//����ֱ���ҵ���СԪ�أ�֮��ͺð���

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int len = nums.size();
		if (len < 1) return -1;
		int low = 0, high = len - 1;
		int minIdx;
		while (low <= high)
		{
			if (nums[low] <= nums[high])
			{
				minIdx = low;
				break;
			}
			int mid = (low + high) / 2;
			//ע������Ҫ�� mid �� high �Ƚ�
			//ֻ������Ԫ��ʱ mid==low�� ���ܻ����
			nums[mid] > nums[high] ? low = mid + 1 : high = mid;
		}

		if (target < nums[minIdx] || nums[(minIdx - 1 + len)%len] < target) return -1;
		
		if (target >= nums[0])
			return bSearch(0, (minIdx - 1 +len)%len, nums, target);
		else return bSearch(minIdx, len - 1, nums, target);
		

	}
	int bSearch(int i, int j, vector<int>& nums, int t)
	{
		while (i<=j)
		{
			int mid = (i + j) / 2;
			if (nums[mid] == t) return mid;
			if (i == j && nums[mid] != t) return -1;
			nums[mid] < t ? i = mid + 1 : j = mid;
		}
		return -1;
	}
};

int main()
{
	Solution solu;
	vector<int > vec = { 3,1};
	int t = 1;
	int ans = solu.search(vec, t);
	cout << ans;
	system("pause");
	return 0;
}