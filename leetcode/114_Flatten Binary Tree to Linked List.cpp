#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<stack>
#include<algorithm>
#include<queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution3 {
public:
	// ���� morris traversal
    void flatten(TreeNode* root) {
        TreeNode* pre = NULL, * cur = root;
        while(cur)
        {
            if (cur->left == NULL)
                cur = cur->right;
            else
            {
                pre = cur->left;
                while(pre->right!=NULL && pre->right!=cur)
                    pre = pre->right;
                if (pre->right == NULL)
                {
                    pre->right = cur;
                    cur = cur->left;
                }
                else
                {
                    //���������cur���
					//cur �� cur->right ֮�����һ������
					//������ĵ�һ��Ԫ����cur->left,
					// ���һ��Ԫ����pre, �� ������� cur ����һ�����
                    pre->right = cur->right;
                    TreeNode* right = cur->right;
                    cur->right = cur->left;
                    cur->left = NULL;
                    cur = right;
                }
            }
        }
    }
};

class Solution2 {
public:
    // https://leetcode.com/problems/flatten-binary-tree-to-linked-list/discuss/36977/My-short-post-order-traversal-Java-solution-for-share
	//�� �� �� ����
    void flatten(TreeNode* root) {
        if (root == NULL) return;
        flatten(root->right);
        flatten(root->left);
        root->right = next;
        root->left = NULL;
        next = root;
    }
private:
    TreeNode* next = NULL;
};


class Solution {
public:
	void flatten(TreeNode* root)
	{
		flatten(root, NULL);
	}
	TreeNode *flatten(TreeNode *root, TreeNode *tail) {
		//�� �� �� ������ �� ��һ���ⷨ����һ���� tail ���� next
		if (NULL == root) return tail;
		root->right = flatten(root->left, flatten(root->right, tail));
		root->left = NULL;
		return root;
	}

	void flatten2(TreeNode* root)
	{
		TreeNode* p = root;
		TreeNode* q;
		while (p)
		{
			curR = p;
			q = p->right;
			if (p->left)
			{
				insert(p->left);
				p->left = NULL;
			}
			p = q;
		}
	}
private:
	TreeNode* curR;

	// ���� �� �� ����˳�����β�������ڶ���
	void insert(TreeNode* node)
	{
		if (node->right)
			insert(node->right);

		if (node->left)
			insert(node->left);
		
		node->left = NULL;
		TreeNode* next = curR->right;
		curR->right = node;
		node->right = next;

		
	}
};

int main()
{
	Solution solu;
	TreeNode n1(1);
	TreeNode n2(2);
	TreeNode n3(3);
	TreeNode n4(4);
	TreeNode n5(5);
	TreeNode n6(6);
	n1.left = &n2;
	n1.right = &n5;
	n2.left = &n3;
	n2.right = &n4;
	n5.right = &n6;
	solu.flatten(&n1);
	system("pause");
	return 0;
}