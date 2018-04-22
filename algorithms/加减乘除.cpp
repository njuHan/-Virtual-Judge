#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<unordered_map>
#include<sstream>
#include<numeric>
#include<bitset>
#include<stack>
using namespace std;


//Ϊ����ʵ�ּӷ�
int add(int a, int b)
{
	if (b == 0) return a;
	int sum, carry;
	sum = a^b; //û�н�λ�ļӷ�
	carry = (a&b) << 1; //�н�λ�ļӷ�,ע������
	return add(sum, carry);
}

//������
//����ת��Ϊ�ӷ���a - b = a + (-b) = a + (~b + 1 )
int sub(int a, int b)
{
	return add(a, add(~b, 1));
}

//�˳����г��ֵļӼ�������add,sub����
//�˷�
int muti(int a, int b)
{
	bool nega = (b < 0);
	if (nega) b = -b; //ʹ�� b Ϊ����
	unordered_map<int, int> shift;
	for (int i = 0; i < 32; i++)
	{
		shift[1 << i] = i;
	}
	int sum = 0;
	while (b > 0) //���� b �Ķ�����1
	{
		//int last = b&(~b + 1); //ȡ�����һ��1��add
		int last = b&(-b); //-b == (~b+1)
		int temp = shift[last];
		sum = sum + (a << temp); //��Ϊ add()
		b = b&(b - 1); //��ȥ���һ��1�� sub
	}
	if (nega) return -sum;
	else return sum;
}

//����
int mydiv(int a, int b)
{
	if (b == 0) throw std::exception("divider is zero");
	bool nega = (a < 0) ^ (b < 0);
	a = a < 0 ? -a : a;
	b = b < 0 ? -b : b;
	if (a < b) return 0;
	int msb = 0;
	while ((b<<msb)<a)
	{
		msb++;
	}
	int res = 0;
	for (int i = msb; i >= 0; i--)
	{
		if ((b << i) > a) continue;
		res = res | (1 << i);
		a = a - (b << i);
	}
	if (nega) return -res;
	else return res;
}



int main()
{

	cout << mydiv(13, 3);
	system("pause");
	return 0;
}
