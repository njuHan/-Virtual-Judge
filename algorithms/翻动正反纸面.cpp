#include<iostream>
#include<cstdio>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include<unordered_map>
using namespace std;

//һ��ֽ������������ϣ�ÿ��ֻ�ܷ���������k��ֽ��ȫ������������Ҫ���ٴη���
//1:�������ϣ�0����
int func(vector<int> paper)
{
	int n = paper.size();
	if (n == 0) return 0;
	int ans = 1;
	int state = paper[0];
	for (int i = 0; i < n; i++)
	{
		if (paper[i] != state)
		{
			state = paper[i];
			ans++; //��ͬ�μ�һ
		}
	}
	return paper[n - 1] == 1 ? ans - 1 : ans;
}