#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;

class Solution {
public:
	int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
		//����<=R�������Ӵ��� - ����<=L-1�������Ӵ���
		return cnt(A, R) - cnt(A, L - 1);
	}
	//���� ����Ԫ��<=b�������Ӵ��ĸ���
	//cur����ǰiָ���Ԫ�����������������(����Ԫ��<=b)����cur����[i]��β�Ӵ�(<=b)
	// ��ô��i+1Ԫ��<=bʱ����cur+1����[i+1]��β���Ӵ�
	//���Ӵ�������������������Ӵ�������cur֮��
	int cnt(vector<int>& A, int b)
	{
		int len = A.size();
		int cur = 0, sum = 0;
		for (int i = 0; i < len; i++)
		{
			if (A[i] <= b)
				cur = cur + 1; //�Ӵ��ӳ�
			else
				cur = 0; //�Ӵ��жϽ���
			sum += cur;
		}
		return sum;
	}
};
int main()
{
	vector<int> v = { 2, 1, 4, 3 };
	Solution solu;
	int ans = solu.numSubarrayBoundedMax(v, 2, 3);
	printf("%d\n", ans);
	system("pause");
	return 0;
}