#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<stack>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<int> countSmaller(vector<int>& nums) {
		vector<pair<int, int>> num2idx;
		for (int i = 0; i < nums.size(); i++) num2idx.emplace_back(pair<int, int>{nums[i], i});
		this->cnt = vector<int>(nums.size(), 0);

		mergeSort(num2idx, 0, nums.size() - 1);
		return cnt;
	}
private:
	vector<int> cnt;
	//merge the sorted two vec: [i,mid] and[mid+1,j]
	// and store the result in vec
	void merge(vector<pair<int, int>>& vec, int i, int mid, int j)
	{
		// [vec[i], vec[mid]) ����ҿ�
		vector<pair<int, int>> v1(&vec[i], &vec[mid]+1);
		vector<pair<int, int>> v2(&vec[mid+1], &vec[j]+1);
		int len1 = mid - i + 1, len2 = j - mid;
		int k = i, p = 0, q = 0;
		//ֻ���� v1�е�Ԫ�ش�������
		while (p<len1 && q<len2)  
		{
			if (v1[p].first <= v2[q].first)
			{
				cnt[v1[p].second] += q; //v2�б�v1[p].firstС��Ԫ�ظ���
				vec[k++] = v1[p++];
			}
			else // v1[p].first > v2[q].first
				vec[k++] = v2[q++];
		}
		while (p < len1)
		{
			cnt[v1[p].second] += q; //v2�б�v1[p].firstС��Ԫ�ظ���
			vec[k++] = v1[p++];
		}
		while (q < len2) vec[k++] = v2[q++];
	}
	void mergeSort(vector<pair<int, int>>& vec, int i, int j)
	{
		if (i < j)
		{
			int mid = i + (j - i) / 2;
			mergeSort(vec, i, mid);
			mergeSort(vec, mid+1, j);
			merge(vec, i, mid, j);
		}
	}
};

int main()
{
	Solution solu;
	vector<int> vec = { 5, 2, 6, 1 };
	vector<int> ans = solu.countSmaller(vec);
	
	//cout << ans;
	system("pause");
	return 0;
}