#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<set>
#include<list>
#include<sstream>
using namespace std;

struct TreeLinkNode {
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;
	TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

	}
};

class Solution {
public:
	TreeLinkNode* GetNext(TreeLinkNode* pNode)
	{
		TreeLinkNode* ans = NULL;
		if (pNode->right != NULL)
		{
			ans = pNode->right;
			while (ans->left)
				ans = ans->left;
		}
		else
		{
			TreeLinkNode* parent = pNode->next, *son = pNode;
			//�ҵ���һ�����ڵ㣬��pnode�ڸø��ڵ��������
			//����NULL
			while (parent && son == parent->right)
			{
				son = parent;
				parent = parent->next;
			}
			ans = parent;
		}
		return ans;
	}
};