#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<set>
#include<list>
#include<sstream>
using namespace std;



class Solution {
public:
	// Parameters:
	//        numbers:     an array of integers
	//        length:      the length of array numbers
	//        duplication: (Output) the duplicated number in the array number
	// Return value:       true if the input is valid, and there are some duplications in the array number
	//                     otherwise false

	// swap
	bool duplicate(int numbers[], int length, int* duplication)
	{
		if (length <= 1) return false;
		for (int i = 0; i < length; i++) if (numbers[i] < 0 || numbers[i] >= length) return false;
		for (int i = 0; i < length; i++)
		{
			while (numbers[i]!=i)
			{
				if (numbers[i] == numbers[numbers[i]])
				{
					*duplication = numbers[i];
					return true;
				}
				else swap(numbers[i], numbers[numbers[i]]);
			}
		}
		return false;
	}
	// modify num + len
	bool duplicate_1(int numbers[], int length, int* duplication)
	{
		if (length <= 1) return false;
		for (int i = 0; i < length; i++) if (numbers[i] < 0 || numbers[i] >= length) return false;
		for (int i = 0; i < length; i++)
		{
			int idx = numbers[i] % length;
			if (numbers[idx] >= length)
			{
				*duplication = idx;
				return true;
			}
			else numbers[idx] += length;
		}
		return false;
	}

	//���ⲻ��֤���ظ�Ԫ�أ�����leetcode287 ����ָ��ķ�������������һ��
	bool duplicate_2(int numbers[], int length, int* duplication) {
		int slow = 0, fast = 0, step = 0;
		do
		{
			if (step > length || fast >= length || slow >= length) return false;
			fast = numbers[numbers[fast]];
			slow = numbers[slow];
			step++;
			cout << fast << "," << slow << endl;
		} while (slow != fast);
		fast = 0;
		while (slow != fast)
		{
			slow = numbers[slow];
			fast = numbers[fast];
		}
		*duplication = fast;
		return true;
	}
};
int main()
{
	int nums[] = { 2,1,3,0,4 }, len = 5;
	Solution solu;
	int *p = new int;
	solu.duplicate(nums, len, p);
	system("pause");
	return 0;
}