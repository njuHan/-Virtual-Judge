#include<iostream>
#include<cstdio>
#include<unordered_map>
#include<algorithm> 
#include<string>
using namespace std;

class Solution {
public:
	//11ms
	double myPow(double x, int n) {
		if (n == 0) return 1;
		if (n < 0) return 1 / x* myPow(1/x, -(n + 1));
		if (n == 2) return x*x;
		if (n%2 == 0) return myPow(x*x,n/2);
		else return x*myPow(x*x, n / 2);
	}
	//12ms
	double myPow(double x, int n) {
		if (n == 0) return 1;
		if (n < 0) return 1 / x * myPow(1 / x, -(n + 1));
		if (n == 2) return x*x;
		if (n % 2 == 0) return myPow(myPow(x, n / 2), 2);
		else return x * myPow(myPow(x, n / 2), 2);
	}
	//12ms
	double myPow(double x, int n) {
		if (n == 0) return 1;
		double t = myPow(x, n / 2);
		if (n % 2) return n>0 ? x * t * t : 1 / x * t * t;
		else return t * t;
	}
	//����ֱ�� int n=-n ��-2147483648�����
	// 9ms
	double myPow(double x, int n)
	{
		if (n == 0) return 1;
		long long m = n;
		if (m < 0) { m = -m; x = 1 / x; }
		double ans = 1;
		while (m) // m ����2���ƣ����ɶ����������
		{
			if (m & 1) ans *= x; // x��2���ݴη����
			x *= x;  
			m = m >> 1;
		}
		return ans;
	}
};