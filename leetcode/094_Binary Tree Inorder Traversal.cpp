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
	vector<int> inorderTraversal2(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> sk;
        while(root || !sk.empty())
        {
            while(root) 
            {
                sk.push(root);
                root = root->left;
            }
            TreeNode* node = sk.top(); sk.pop();
            ans.emplace_back(node->val);
            root = node->right;
        }
        return ans;
    }
	vector<int> inorderTraversal(TreeNode* root) {
		if (root != NULL)
		{
			inorderTraversal(root->left);
			ans.emplace_back(root->val);
			inorderTraversal(root->right);
		}
		return ans;
	}
private:
	vector<int> ans;
};

int main()
{
	Solution solu;
	vector<vector<char>> board = { { 'a','a' } };
	string word = "aaa";
	bool ans = solu.exist(board, word);
	system("pause");
	return 0;
}