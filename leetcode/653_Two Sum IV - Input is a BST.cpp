#include<iostream>
#include<cstdio>
#include<unordered_map>
using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool findTarget(TreeNode* root, int k) {
		if (!root) return false;
		if(!this->rootNode) this->rootNode = root;
		// ���ǽ��root, ������Ѱ����һ����� || ���������� || ����������
		// ע�Ᵽ�ָ���㣬����Ѱ����һ�����
		return search(rootNode, root, k - root->val ) || findTarget(root->left, k) || findTarget(root->right, k);
	}
private:
	TreeNode* rootNode;
	bool search(TreeNode* tocheck, TreeNode* cur, int target)
	{
		if (!tocheck) return false;
		return tocheck != cur && tocheck->val == target || tocheck->val > target && search(tocheck->left, cur, target) || tocheck->val < target && search(tocheck->right, cur, target);
	}
};