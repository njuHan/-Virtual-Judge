#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<unordered_map>
#include<stack>
#include<algorithm>
#include<queue>
using namespace std;



class Solution {
public:
	// [1,0]
	// To take course 1 you should have finished course 0
	//����� 0->1
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		if (numCourses == 0) return true;
		set<int> ans;
		for (int i = 0; i < numCourses; i++) zeroNode.insert(i);
		//��� graph[i][j]==true����ʾ�����i->j
		graph = vector<vector<bool>>(numCourses, vector<bool>(numCourses, false));
		for (int i = 0; i < prerequisites.size(); i++)
		{
			int u = prerequisites[i].second, v = prerequisites[i].first;
			if (u == v) return false; //has cycle
			graph[u][v] = true;
			inDgree[v] = inDgree[v]+1;
			zeroNode.erase(v);
		}
		// BFS
		while (!zeroNode.empty())
		{
			int u = *zeroNode.begin();
			zeroNode.erase(u);
			ans.insert(u);
			for (int v = 0; v < numCourses; v++)
			{
				if (graph[u][v])
				{
					inDgree[v] -= 1;
					if (inDgree[v] == 0) zeroNode.insert(v);
				}
			}
		}
		if (ans.size() == numCourses) return true;
		else return false;

	}
	// �����ع�, ���������ˡ�����
	bool canFinish2(int numCourses, vector<pair<int, int>>& prerequisites) {
		if (numCourses == 0) return true;
		//��� graph[i][j]==true����ʾ�����i->j
		graph = vector<vector<bool>>(numCourses, vector<bool>(numCourses, false));
		for (int i = 0; i < prerequisites.size(); i++)
		{
			int u = prerequisites[i].second, v = prerequisites[i].first;
			if (u == v) return false; //has cycle
			graph[u][v] = true;
			inDgree[v] = inDgree[v] + 1;
			
		}
		// BFS
		// �ҵ� numCourses�����Ϊ0�ĵ�
		for (int i = 0; i < numCourses; i++)
		{
			int j;
			for (j = 0; j < numCourses; j++)
			{
				if (inDgree[j] == 0)
				{
					inDgree[j] = -1;
					break;
				}
			}
			if (j == numCourses) return false; //�Ҳ������Ϊ0�ĵ�
			for (int v = 0; v < numCourses; v++) //��һ�������ȼ�һ
				if (graph[j][v])
					inDgree[v] -= 1;
		}
		return true;

	}
private:
	vector<vector<bool>> graph;
	//�������
	map<int,int> inDgree; 
	//���Ϊ0�Ľ��
	set<int> zeroNode;
};
int main()
{


	system("pause");
	return 0;
}