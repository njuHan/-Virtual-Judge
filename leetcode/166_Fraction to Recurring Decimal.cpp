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
	// ���ݷ���(������)�ظ����֣��ж�ѭ��С������ʼ��
	string fractionToDecimal(int numerator, int denominator) {
		if (numerator == 0) return "0";
		string ans;
		bool sign = numerator < 0 ^ denominator < 0; //is negative
		if (sign) ans += "-";
		long long nume = numerator < 0 ? -(long long)numerator : (long long)numerator;
		long long deno = denominator < 0 ? -(long long)denominator : (long long)denominator;
		ans += to_string(nume / deno);
		nume %= deno;
		if (nume == 0) return ans;
		else ans += ".";
		unordered_map<long long, int> idx; //���ӳ��ֵ��±�
		while (nume)
		{
			if (idx.count(nume))
			{
				ans.insert(idx[nume], 1, '(');
				ans += ")";
				break;
			}
			idx[nume] = ans.length();
			nume *= 10;
			ans += to_string(nume / deno);
			nume %= deno;
		}
		return ans;
	}
};