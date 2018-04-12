#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
	vector<string> removeInvalidParentheses(string s) {
		dfsRemove(0, 0, s, "()");
		return ans;
	}
	
private:
	vector<string> ans;
	//�ڱ�����ʱ���� ) ���� ( ���Ϳ���ȷ����Ҫɾ�� )�� eg: ()))) 
	//����� ��������෴ ((() ����->  )(((, ����ȷ��Ҫɾ���� (
	//ȥ�أ� ������Ҫɾ�����ţ�����ѡ���һ��ɾ���� lastRm�����һ��ɾ����idx
	//666 solution : https://leetcode.com/problems/remove-invalid-parentheses/discuss/75027/Easy-Short-Concise-and-Fast-Java-DFS-3-ms-solution
	void dfsRemove(int start, int lastRm, string s, const string& par)
	{
		int cnt = 0;
		for (int i = start; i < s.size(); i++)
		{
			if (par[0] == s[i]) cnt++;
			if (par[1] == s[i]) cnt--;
			if (cnt >= 0) continue; //��ʱ����ȷ���費��Ҫɾ������
			// else cnt<0 ����ʱ����Ҫɾ�� par[1], dfs����ɾ��
			//[start, i]����������һ��par[1]
			for (int j = lastRm; j <= i; j++)
			{
				//������[lastRm, i]��ɾ��һ���ַ�par[1]
				//������һ������[i, len], ����ɾ���Ը��ַ������Դ�i��ʼ
				if (s[j] == par[1] && (j == lastRm || s[j - 1] != par[1]))
					dfsRemove(i, j, s.substr(0, j) + s.substr(j + 1), par);
			}
			return; //������cnt<0������������������cnt>=0��ֱ�ӷ���
		}
		//���븴�ô��� cnt>=0
		//��������cnt>0֮�� ��������һ��(cnt==0)��ʹ�ú�Դ����һ��
		reverse(s.begin(), s.end());
		if (par[0] == '(')
			dfsRemove(0, 0, s, ")(");
		else
			ans.emplace_back(s);
	}
};

int main()
{

}