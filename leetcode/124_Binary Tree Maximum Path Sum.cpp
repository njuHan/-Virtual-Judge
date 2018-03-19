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

class Solution {
public:
	// ���val����Ϊ����
	int maxPathSum(TreeNode* root) {
		maxP = INT_MIN;
		getMax(root);
		return maxP;
	}
	//�ý�㵽Ҷ�ӽ����·��ֵ�������ý���Լ���val
	//�������Ϊ��������ȡ0�����߸�·��
	//·������һ����㣬����node�Լ���val����ȡ
	int getMax(TreeNode* node) 
	{
		if (node == NULL) return 0;
		//�������
		int left = max(getMax(node->left), 0);
		int right = max(getMax(node->right), 0);
		maxP = max(maxP, left + right + node->val);
		return node->val + max(left, right);
	}
private:
	int maxP;
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
	
	system("pause");
	return 0;
}