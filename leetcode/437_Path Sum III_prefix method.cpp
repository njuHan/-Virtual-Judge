#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<queue>
#include<functional>
using namespace std;

//https://leetcode.com/problems/path-sum-iii/discuss/91878/17-ms-O(n)-java-Prefix-sum-method?page=3

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int pathSum(TreeNode* root, int sum) {
		preSum.emplace(0, 1);
		return dfs(root, 0, sum);

	}
private:
	unordered_map<int, int> preSum;
	//��¼�Ӹ���㵽��ǰ��������ǰ׺�ͣ�eg : A->B->C  sum(A,B), sum(A,B,C)
	int dfs(TreeNode* node, int sum, int target)
	{
		if (node == NULL) return 0;
		sum += node->val;
		int ans = 0;
		//target == �Ӹ���㵽��ǰ���ĺ� - �Ӹ���㵽�м���ĺ� 
		//���� ���м��㵽��ǰ���ĺ� == target
		if (preSum.count(sum - target)) 
			ans += preSum[sum - target];
		preSum[sum]++;
		ans += dfs(node->left, sum, target) + dfs(node->right, sum, target);
		preSum[sum]--; //�����ݹ���������ظ��ڵ�
		return ans;
	}

};

int main()
{

	return 0;
}