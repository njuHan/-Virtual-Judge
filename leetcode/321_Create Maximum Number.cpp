
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
	//˼·����������ֱ�ȥk1, k2����ԭ�����������ںϲ�k1,k2
	// �ȽϺϲ�������飬ȡ���ֵ
	vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
		int len1 = nums1.size(), len2 = nums2.size();
		//��nums1��ȡ k1 ������ע��k1�ķ�Χ
		vector<int> best;
		for (int k1 = max(0, k - len2); k1 <= min(k, len1); k1++)
		{
			best = max(best, merge(getKmax(nums1, k1), getKmax(nums2, k - k1)));
		}
		return best;
	}
	vector<int> getKmax(vector<int> nums, int k)
	{
		int drop = nums.size() - k;
		vector<int> ans;
		for (int num : nums)
		{
			while (ans.size() && drop > 0 && num > ans.back())
			{
				ans.pop_back();
				drop--;
			}
			ans.emplace_back(num);
		}
		ans.resize(k);
		return ans;
	}
	vector<int> merge(vector<int> nums1, vector<int> nums2)
	{
		/*
		vector<int> ans;
		int i = 0, j = 0;
		// ����д���ԣ� ���ʱ������⣬
		// 6��7
		// 6��1 
		// 6->1->7, 6->7->1
		while (i < nums1.size() || j < nums2.size())
		{
			if (i == nums1.size())
			{
				ans.emplace_back(nums2[j++]);
			}
			else if (j==nums2.size())
			{
				ans.emplace_back(nums1[i++]);
			}
			else
			{
				ans.emplace_back(nums1[i] > nums2[j] ? nums1[i++] : nums2[j++]);
			}
		}
		return ans;
		*/
		// ��Ҫ����֮���ַ����ֵ��򣬿���ʹ��max ���� ������ >
		/*
		vector<int> out;
		auto i1 = nums1.begin(), end1 = nums1.end();
		auto i2 = nums2.begin(), end2 = nums2.end();
		while (i1 != end1 || i2 != end2)
			out.push_back(lexicographical_compare(i1, end1, i2, end2) ? *i2++ : *i1++);
		return out;
		*/
		vector<int> ans;
		while (nums1.size() || nums2.size())
		{
			vector<int> &bigger = nums1 > nums2? nums1 : nums2;
			ans.emplace_back(bigger[0]);
			bigger.erase(bigger.begin());
		}
		return ans;
		
	}
};

int main()
{
	Solution solu;

	return 0;
}