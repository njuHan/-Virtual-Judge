#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<unordered_map>
using namespace std;


class Solution {
public:
	string predictPartyVictory(string senate) 
	{
		//ban��֮��ĵ�һ������
		//cnt������ ����Ͷ��Ʊ�� R-D ��ֵ
		int cnt = 0;
		string nextRound(senate);
		int nextLen = -1;
		while (nextLen!=nextRound.size())
		{
			string temp;
			nextLen = nextRound.size();
			for (int i = 0; i < nextLen; i++)
			{
				if (nextRound[i] == 'R')
				{
					if (++cnt > 0)
						temp.push_back('R');
				}
				else if (nextRound[i] == 'D')
				{
					if (--cnt < 0)
						temp.push_back('D');
				}
			}
			swap(temp, nextRound);
		}
		return nextRound[0] == 'R' ? "Radiant" : "Dire";
	}
};

int main()
{



	system("pause");
	return 0;
}



