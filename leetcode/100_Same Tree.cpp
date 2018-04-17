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

class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p == NULL && q == NULL) return true;
		else if (p == NULL || q == NULL) return false;
		return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	}

	//�޸����⣬���������������������������ҽ��ɽ�������������������ǲ��ǽṹ��ͬ��
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p == NULL && q == NULL) return true;
		else if (p == NULL || q == NULL) return false;
		return p->val == q->val && ((isSameTree(p->left, q->left) && isSameTree(p->right, q->right)) || (isSameTree(p->right, q->left) && isSameTree(p->left, q->right)));
	}
};

int main()
{

	
	system("pause");
	return 0;
}
