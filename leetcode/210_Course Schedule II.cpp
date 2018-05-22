#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
using namespace std;


class Solution {
public:
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
		for (auto e : prerequisites)
			adj[e.second].push_back(e.first); //u->v
		ans = vector<int>(numCourses, 0);
		t = numCourses;
		vis = vector<int>(numCourses, false);
		for (int u = 0; u < numCourses; u++)
		{
			if (vis[u] == 0)
				if (dfs(u) == false) return{}; //has cycle
		}
		return ans;
	}
private:
	unordered_map<int, vector<int>> adj;
	vector<int> ans;
	int t ;
	vector<int> vis;
	bool dfs(int u)
	{
		vis[u] = -1;
		for (int v : adj[u])
		{
			if (vis[v] == -1) return false;
			if (vis[v] == 0 && dfs(v) == false) return false;
		}
		vis[u] = 1;
		ans[--t] = u;
		return true;
	}
};