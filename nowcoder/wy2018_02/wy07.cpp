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

//��ԭ�����ź���ÿ��ȡ�����е��������Сֵ���뵽�������У�����һ�·����д��м���������չ����
//����һ�μ������С�����ֵ�������ֱ��ԭ�����н�ʣ���һ��ֵ�������ŵ������к��ʵ�λ���ϱ�֤���ֵ��󼴿ɡ�
const int maxn = 55;
int arr[maxn];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	if (n <= 1)
	{
		cout << 0;
		return 0;
	}
	sort(&arr[0], &arr[n]);
	int maxnum = arr[n - 1];
	int minnum = arr[0];
	int ans = maxnum - minnum;
	int minidx = 1, maxidx = n - 2;
	while (minidx < maxidx)
	{
		ans += maxnum - arr[minidx];
		ans += arr[maxidx] - minnum;
		maxnum = arr[maxidx--];
		minnum = arr[minidx++];
	}
	if (n % 2) ans += max(maxnum - arr[minidx], arr[minidx] - minnum);
	cout << ans;
	//system("pause");
	return 0;
}


