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

// see: https://leetcode.com/problems/task-scheduler/discuss/104507/Python-Straightforward-with-Explanation

class Solution {
public:
	int leastInterval(vector<char>& tasks, int n) {
		map<char, int> task2num;
		int m = 0; //�����ִ���
		for (char ch : tasks)
		{
			task2num[ch]++;
			m = max(task2num[ch], m);
		}
		int cntM = 0; //���ִ���Ϊm��task������
		for (auto data : task2num)
		{
			if (data.second == m)
				cntM++;
		}
		//̰�ģ����ִ�������task,
		//�����ִ��� m, ����m-1����Ҫ (m-1)*(n+1), ���ŵ�m��������m-1��������ȴ���еĽ׶Σ�
		//�������ִ�������m��task, ǰm-1����գ����һ����ӵ�����β
		//�����������ִ���С��m�ģ�ÿ���׶β�շ���
		int ans = (m - 1)*(n + 1) + cntM;
		return max((int)tasks.size(), ans);
	}
};

int main()
{
	

	system("pause");
	return 0;
}



