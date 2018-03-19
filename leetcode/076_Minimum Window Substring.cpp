#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<stack>
#include<algorithm>
using namespace std;

class Solution {
public:
	string minWindow(string s, string t) {
		if (s.size() == 0) return "";
		//if (t.size() == 0) return s.substr(0, 1);
		unordered_map<char, int> chCnt;
		// t���ظ����ַ�Ҳ���붼�ڴ�����
		size_t count = t.size(); //�����л�����ӵ�t���ַ��ĸ���
		for (auto ch : t) chCnt[ch]++; //t���ַ�����
		size_t minI = 0, minJ = 0; //������ʼλ��
		size_t minSize = INT_MAX; //��С���ڴ�С
		size_t i = 0, j = 0;
		while (j < s.size())
		{
			if (chCnt.count(s[j])) //s[j]������ t ��
			{
				if (chCnt[s[j]]>0) //����0���ż�������Ϊs�п����кܶ�t�е��ַ���chCnt����Ϊ����
					count--;
				chCnt[s[j]]--; //s�Ĵ����У� �ַ�s[j]����Ҫ���ֵĴ���
				
			}
			j++;
			//��ǰ�����Ѿ�����������t���ַ�
			//��Сwin���, ��С����
			while (count == 0 && i<j)
			{
				//ע���ʱ��jָ�򴰿����һ���ַ�����һ���ַ�
				if (minSize > j - i)
				{
					minSize = j - i;
					minI = i;
					minJ = j;
				}
				if (chCnt.count(s[i]))
				{
					chCnt[s[i]]++;
					if (chCnt[s[i]] > 0) //˵��������ȱ�� �ַ� s[i]
						count++;
				}
				i++;
			}
		}
		if (minSize == INT_MAX)
			return "";
		else
			return s.substr(minI, minSize);

	}
};

int main()
{
	Solution solu;
	string s = "abc", t = "";
	string ans = solu.minWindow(s, t);
	cout << ans;
	system("pause");
	return 0;
}