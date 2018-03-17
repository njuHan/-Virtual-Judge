#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
using namespace std;

//��������BFS��һ��ʼ�뵽��queue�����Ǿ��ö���ȡ��Ԫ�ػ�Ҫ���������鷳
//��ʵ��vector�Լ����Ʒ���˳�������
//����vector�������ǳ�����˽���
//emplace_back �˽���

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> dig2let = { "","","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
		vector<string> ans;
		int len = digits.size();
		if (len < 1) return ans;
		ans.push_back("");
		for (int i = 0; i < len; i++)
		{
			int dig = digits[i] - '0';
			if (dig < 0 || dig>9) break;
			vector<string> temp;
			for (int j = 0; j < dig2let[dig].size(); j++)
			{
				for (int k = 0; k < ans.size(); k++)
				{
					//temp.push_back(ans[k] + dig2let[dig][j]);
					temp.emplace_back(ans[k] + dig2let[dig][j]);
				}
			}
			ans.swap(temp);
		}
		return ans;
	}
};
int main()
{
	Solution solu;
	vector<string> ans = solu.letterCombinations("23");
	for (auto e : ans)
		cout << e << endl;
	system("pause");
	return 0;
}