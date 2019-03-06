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


int x[50];
int y[50];
int n;
//���x0,y0�����k����ľ����
int getDistK(int x0, int y0, int k)
{
	multiset<int> st;
	for (int i = 0; i < n; i++)
	{
		int dist = abs(x[i] - x0) + abs(y[i] - y0);
		st.insert(dist);
	}
	int i = 0;
	int sum = 0;
	for (auto e : st)
	{
		if (i >= k) break;
		i++;
		sum = sum + e;
	}
	return sum;
}
/*
��������������Ĺؼ������ڼ��������پ���ʱ����ͨ����x��y�ֱ������������õ���
����ʹdist_sum��С�ĸ��ӵ�x����һ����X�е�һ����y����һ����Y�е�һ����
 1. ����ÿһ����ѡ����(X[i], Y[j])�����ֱ����dist_sum
 2. ������ǵ���Сֵ
*/
//�������е�, �����ۻ�k�͵㣬�������С�ƶ�
int minMove(int k)
{
	int move = INT_MAX;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			int dist = getDistK(x[i], y[j], k);
			move = move > dist ? dist : move;
		}
	return move;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> x[i];
	for (int i = 0; i < n; i++) cin >> y[i];

	cout << 0; //k == 1;
	for (int k = 2; k <= n; k++)
		cout << " " << minMove(k);
	
	//system("pause");
	return 0;
}


