#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// https://leetcode.com/problems/sum-of-distances-in-tree/discuss/130583/C++JavaPython-Pre-order-and-Post-order-DFS-O(N)
class Solution {
public:
	vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
		if (N <= 0) return ans;
		n = N;
		count = vector<int>(n, 0);
		ans = vector<int>(n, 0);
		tree = vector<unordered_set<int>>(n);
		for (auto e : edges) // ����ÿ�����Ϊ������������㼯��
		{
			tree[e[0]].insert(e[1]);
			tree[e[1]].insert(e[0]);
		}
		int root = 0; //�Խ�� 0 Ϊ������������Ϣ
		vis.clear();
		postDfs(root);
		vis.clear();
		preDfs(root);
		return ans;
	}
private:
	int n; //������
	vector<int> count; //count[i] ��iΪ����������������
	vector<int> ans;
	unordered_set<int> vis; 
	vector<unordered_set<int>> tree;
	void postDfs(int root) //���µ��ϣ���¼ÿ�������Ľ�����count[i]����ʱans[i]��ʾ����i�ĸ����i���Լ��������ľ����
	{
		vis.insert(root);
		for (int i : tree[root])
		{
			if (!vis.count(i))
			{
				postDfs(i);
				count[root] += count[i];
				ans[root] += count[i] + ans[i];
			}
		}
		count[root]++; //add root
	}
	void preDfs(int root)
	{
		vis.insert(root);
		for (int i : tree[root])
		{
			if (!vis.count(i))
			{
				ans[i] = ans[root] - count[i] + (n - count[i]);
				preDfs(i);
			}
		}
	}
};