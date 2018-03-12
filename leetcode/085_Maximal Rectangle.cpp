#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

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
	int maximalRectangle(vector<vector<char>>& matrix) {
		if (matrix.size() == 0 || matrix[0].size()==0) return 0; //ע���mat
		int m = matrix.size(), n = matrix[0].size(); //����
		int maxRec = 0;
		vector<int> heights(n, 0);
		for (int i = m - 1; i >= 0; i--)
		{
			int idx = i; 
			int h = 0;
			for (int j = 0; j < n; j++)
			{
				while (idx >= 0 && matrix[idx][j] != '0')
				{
					h++;
					idx--;
				}
				heights[j] = h;
				h = 0;
				idx = i;
			}
			maxRec = max(maxRec, largestRectangleArea(heights));
		}
		return maxRec;
	}
};

int main()
{
	vector<vector<char>> mat = { { '1' ,'0', '1', '0', '0'},
	{'1', '0', '1','1', '1'},
	{'1', '1', '1', '1', '1'},
	{'1','0', '0', '1', '0' }};

	Solution solu;
	int ans = solu.maximalRectangle(mat);
	printf("%d\n", ans);
	system("pause");
	return 0;
}