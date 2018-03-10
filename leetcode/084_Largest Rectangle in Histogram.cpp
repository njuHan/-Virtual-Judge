#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

// ��һ����������������������� i ʱ���������������
// 1.�ҵ������i��������Ҹ߶�> [i] �����ӣ����±� p, (�����û�У���p=-1)
// 2.�ҵ��Ҳ���i��������Ҹ߶�<= [i] �����ӣ����±� q��(���Ҳ�û�У���q=len ������±�+1)
// 3 ���= [i] * (p - q - 1);
// �������е� i ���ϼ��㼴��
// ʹ��һ��ջ����¼������Ӹ߶������������ҪO(n)ʱ�临�Ӷ�
class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		heights.push_back(0); //ĩβ�Ӹ�0�� �ո�leftBars��ʣ������
		vector<int> leftBars; //�����е����Ӹ߶��ϸ����
		int maxArea = 0;
		for (int i = 0; i < heights.size(); i++)
		{
			//����>=ȡ�����ڣ���ǰ[i]�߶ȵ���ջ�����Ӹ߶ȣ�����ջ�����Ӹ߶�ʱ��û�а�[i]�������ӽ���
			//��������һ�μ���[i]��������֮ǰ��[i]��ȵ����ӵ������ӽ���
			while (leftBars.size() && heights[leftBars.back()] >= heights[i]) 
			{
				int h = heights[leftBars.back()];
				leftBars.pop_back();
				int p = leftBars.size() ? leftBars.back() : -1;
				maxArea = max(maxArea, (i - p - 1)*h);
				//printf("%d -%d -1 * %d, %d\n", i, p, h, maxArea);
			}
			leftBars.push_back(i);
		}
		return maxArea;
	}
};

int main()
{
	vector<int> vec = { 2,1,5,6,2,3 };
	Solution solu;
	int ans = solu.largestRectangleArea(vec);
	printf("%d\n", ans);
	system("pause");
	return 0;
}