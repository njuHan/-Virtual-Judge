#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<stack>
#include<algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isValidBST(TreeNode* root) {
		TreeNode* pre = NULL;
		return search(root, pre);
	}
	/*
	If we use in-order traversal to serialize a binary search tree, we can
	get a list of values in ascending order. It can be proved with the
	definition of BST. And here I use the reference of TreeNode
	pointer prev as a global variable to mark the address of previous node in the
	list.
	*/
	bool search(TreeNode* node, TreeNode*& pre)
	{
		if (node == NULL) return true;
		//ʹ������������� �� ��
		if (search(node->left, pre) == false) return false; //�ҵ����������һ���㣬����ߵĽ��
		if (pre != NULL && node->val <= pre->val) return false; //�жϵ�ǰ���,�о����԰�node�����������ڵ�
		pre = node;
		return search(node->right, pre); //�ж��������� pre���Ǹ������ĸ����

	}


	// [-2147483648,null,2147483647]
	// [10,5,15,null,null,-2147483648,20]
	// ʹ�������ޣ���ʼֵ�ᵼ��bug
	bool search_bug(TreeNode* root, int lower, int upper)
	{
		if (!root) return true;

		if (root->left && root->left->val == INT_MIN && lower == INT_MIN);
		else if (root->left && (root->left->val >= root->val || root->left->val<=lower)) return false;

		if (root->right && root->right->val == INT_MAX && upper == INT_MAX);
		else if (root->right && (root->right->val <= root->val ||  root->right->val>=upper)) return false;

		return search_bug(root->left, lower, root->val) && search_bug(root->right, root->val, upper);
	}

};

int main()
{
	Solution solu;

	system("pause");
	return 0;
}