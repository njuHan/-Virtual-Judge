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
#include<stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void inorderMorrisTraversal(TreeNode *root)
{
	TreeNode* pre = NULL, *cur = root;
	while (cur)
	{
		if (cur->left == NULL) //�������
		{
			cout << cur->val;
			cur = cur->right;
		}
		else
		{
			pre = cur->left;
			while (pre->right!=NULL && pre->right!=cur)
			{
				pre = pre->right;
			}
			if (pre->right == NULL) //��������ָ��
			{
				pre->right = cur;
				cur = cur->left;
			}
			else //if (pre->right == cur) //�������㣬 ��������ָ��
			{
				pre->right = NULL;
				cout << cur->val;  //��������
				cur = cur->right; //����������
			}
		}
	}
}
//ǰ�����
void preorderMorrisTraversal(TreeNode *root)
{
	TreeNode* pre = NULL, *cur = root;
	while (cur)
	{
		if (cur->left == NULL)
		{
			cout << cur->val;
			cur = cur->right;
		}
		else
		{
			pre = cur->left;
			while (pre->right!=NULL && pre->right!=cur)
			{
				pre = pre->right;
			}
			if (pre->right == NULL)
			{
				cout << cur; //�����ڽ�������ָ��ʱ�� ����������
				pre->right = cur;
				cur = cur->left;
			}
			else
			{
				pre->right = NULL;
				cur = cur->right;
			}

		}
	}
}

//��������������Ƚϸ���
void reverse(TreeNode *from, TreeNode *to) // reverse the tree nodes 'from' -> 'to'.
{
	if (from == to)
		return;
	TreeNode *x = from, *y = from->right, *z;
	while (true)
	{
		z = y->right;
		y->right = x;
		x = y;
		y = z;
		if (x == to)
			break;
	}
}

void printReverse(TreeNode* from, TreeNode *to) // print the reversed tree nodes 'from' -> 'to'.
{
	reverse(from, to);

	TreeNode *p = to;
	while (true)
	{
		printf("%d ", p->val);
		if (p == from)
			break;
		p = p->right;
	}

	reverse(to, from);
}

void postorderMorrisTraversal(TreeNode *root) {
	TreeNode dump(0);
	dump.left = root;
	TreeNode *cur = &dump, *prev = NULL;
	while (cur)
	{
		if (cur->left == NULL)
		{
			cur = cur->right;
		}
		else
		{
			prev = cur->left;
			while (prev->right != NULL && prev->right != cur)
				prev = prev->right;

			if (prev->right == NULL)
			{
				prev->right = cur;
				cur = cur->left;
			}
			else
			{
				printReverse(cur->left, prev);  // call print
				prev->right = NULL;
				cur = cur->right;
			}
		}
	}
}