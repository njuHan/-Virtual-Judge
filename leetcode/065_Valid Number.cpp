#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>
#include<string>
#include<sstream>
using namespace std;
class Solution {
public:
	//DFA
	bool isNumber(string str) {
		int state = 0;
		while (str[0] == ' ')  str.erase(0, 1);//delete the  prefix whitespace 
		while (str[str.length() - 1] == ' ') str.erase(str.length() - 1, 1);//delete the suffix whitespace
		for (int i = 0; i<str.length(); i++) {
			if ('0' <= str[i] && str[i] <= '9') {
				if (state <= 2) state = 2;
				else state = (state <= 5) ? 5 : 7;
			}
			else if ('+' == str[i] || '-' == str[i]) {
				if (state == 0 || state == 3) state++;
				else return false;
			}
			else if ('.' == str[i]) {
				if (state < 2) state = 6;
				else if (state == 2) state = 7;
				else return false;
			}
			else if ('e' == str[i]) {
				if (state == 2  || state == 7) state = 3;
				else return false;
			}
			else return false;
		}
		return (state == 2 || state == 5 || state == 7);
	}
	// use if
	bool isNumber_2(string str) {
        const char* string = str.c_str();
		int len = strlen(string), i = 0;
		if (len < 1) return false;
		//skip the leading spaces
		while (i < len && string[i] == ' ') i++;
		//skip sign
		if (string[i] == '+' || string[i] == '-') i++;
		//check significant part
		int digitCnt = 0, dotCnt = 0;
		while (i<len && (isdigit(string[i])||string[i]=='.'))
		{
			if (isdigit(string[i])) digitCnt++;
			else dotCnt++;
			if (dotCnt > 1) return false;
			i++;
		}
		if (digitCnt < 1) return false;
		//check exp part
		if (i < len && (string[i] == 'e' || string[i] == 'E'))
		{
			i++;
			if (i == len) return false;
			if (string[i] == '+' || string[i] == '-') i++;
			digitCnt = 0;
			while (i<len && isdigit(string[i])) 
			{
				digitCnt++;
				i++;
			}
			if (digitCnt < 1) return false;
			
		}

		//skip trailing spaces
		while (i < len && string[i] == ' ') i++;
		return i == len;
    }
};

int main()
{
	Solution solu;
	
	system("pause");
	return 0;
}