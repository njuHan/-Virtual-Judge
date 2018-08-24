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

// see: https://leetcode.com/problems/course-schedule-iii/discuss/104840/C++-13-lines-With-Explanation

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        // ������ʱ������ ���ȿ���������Ŀγ̣��γ̳���С�Ŀγ�
        sort(courses.begin(), courses.end(), [](const vector<int>& v1, const vector<int>& v2) {return v1.back() < v2.back() || (v1.back() == v2.back() && v1[0] < v2[0]); });
		priority_queue<int> que; //max heap���洢�γ�ʱ�䳤�ȣ�������Ŀ��ڶѶ�
		int curEnd = 0;
		for(vector<int> cos : courses)
		{
			if (curEnd + cos[0] <= cos[1]) // �пռ����ֱ�����
			{
				curEnd += cos[0];
				que.push(cos[0]);
			}
			else if (!que.empty() && que.top() > cos[0]) //�滻�Ѷ�ʱ��ϳ��Ŀγ̣�
			{
				curEnd = curEnd - que.top() + cos[0]; // ��Ϊ���ս���ʱ�����򣬿϶����㣺curEnd = curEnd - que.top() + cos[0] <= cos[1] 
				que.pop();
				que.push(cos[0]);
			}
		}

		return que.size();
    }
};



int main()
{
	

	
	system("pause");
	return 0;
}



