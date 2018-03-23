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
	//����˼�룺 ά��һ����ǰ��Ч�߶ȵļ��ϣ�
	//����ǰ��Ч�߶ȼ��ϵ����߶Ⱥ͵�ǰ��ƽ�߲�ͬ���޸ĵ�ƽ����ʼ��͸߶�
	vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
		//�洢��ǰ��Ч�ĸ߶ȣ�����set���Զ��������ʣ����߶������һ��Ԫ��
		//����һ���·��ӵĿ�ʼ�������߶ȣ�
		//�������ӵĽ�����ɾ����߶�
		multiset<int> heights = { 0 };
		//��¼������ʼ�ͽ���ʱ��idx �� �߶� �Ķ�Ԫ��
		//���� [2,4,3], ��Ϊ(2,-3), (4,3)
		// ��������������ʼ�ͽ���
		// ��ʼ�߶�Ϊ����������set�����ԣ�ʹ�������߶�һ�����������ڵķ��ӣ��ڶ�����������ʼpush �߶ȣ���pop��һ�����ӵĸ߶�
		//�Զ��ϲ����������ڵķ���
		multiset<pair<int, int>> idxHeight;
		//��ǰ��ʼλ�ã�����ʼ�ĸ߶�
		pair<int, int> cur({ 0, 0 });
		//ans:
		vector<pair<int, int>> ans;
		for (auto e : buildings)
		{
			idxHeight.insert(pair<int, int>(e[0], -e[2])); //��-�߶�
			idxHeight.insert(pair<int, int>(e[1], e[2])); // �ң��߶�
		}
		for (auto e : idxHeight)
		{
			if (e.second < 0) //�������ӵ���ʼ
				heights.insert(-e.second);
			else //���ӽ�����ɾ�����Ӹ߶�
			{
				//heights.erase(e.second); ����ֱ��ɾ��key,�����������key��ɾ��
				//ֻ��ɾ��һ����
				heights.erase(heights.find(e.second));
			}
			if (*heights.rbegin() != cur.second)
			{
				cur.first = e.first;
				cur.second = *heights.rbegin();
				ans.emplace_back(cur);
			}
			
		}
		return ans;
	}


};
int main()
{

	Solution solu;
	vector<vector<int>> vec = { {0,2,3},{2,5,3} };
	solu.getSkyline(vec);
	system("pause");
	return 0;
}