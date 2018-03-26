#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>
#include<string>
#include<sstream>
#include<iterator>
#include<stack>
#include<string.h>
#include<algorithm>
using namespace std;

bool isvalid(const string& str)
{
	int cnt = 0;
	for (int i = 0; str[i]; i++)
	{
		if (str[i] == '(') cnt++;
		else cnt--;
		if (cnt < 0) return false;
	}
	return cnt == 0;
}

/*
�������⣬Ҫ��ʹ�� LCS ���ɾȥ����һ���ַ����ɻ�� LCS = |s| - 1 ���ٰѸ��ַ��嵽��ԭ����ͬ������λ�ÿ���ά��ԭ���ȣ�����Ӱ�� LCS �ļ��㡣

��������������ö��ÿ���ַ����������뵽����λ�ã��кϷ���ȥ�أ��ۼơ�

�Ż� 1 �������ǲ嵽ָ��λ�õ��ַ�֮ǰ�����������ַ��͸�λ�õ��ַ���ͬ����������ԭ�ַ�����������������������������Ľ��Ҫ - 1 ��
�Ż� 2 ����������һ�����������ţ������ƶ����ǡ����ַ�ȴ���Բ嵽���ǵĺ��档

�кϷ���ʵ���Ͼ�������ƥ���ƽ���ԡ������������Ǵ�ǰ��������������ſ�����ʱ���������ţ������������ڣ���Ϊ�ܹ��պ������ŵ������Ŷ�������ˡ�ÿ�γɹ��պ�һ�����Ű����� - 1 ���õ�����˵����ƽ�⡣
*/

int main()
{
	string str;
	cin >> str;
	
	set<string> ans;
	for (int i = 0; str[i]; i++)
	{
		// erase i
		string strdelei(str);
		strdelei.erase(i,1);
		char chi = str[i];
		// insert at j
		for (int j = 0; str[j]; j++)
		{
			if (chi == str[j]) continue;
			string strinsetj(strdelei);
			strinsetj.insert(j, 1, chi);
			if (isvalid(strinsetj))
				ans.insert(strinsetj);
		}
	}
	cout << ans.size() << endl;
	//system("pause");
	return 0;
}