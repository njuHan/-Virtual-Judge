#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<unordered_map>
using namespace std;

class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
		this->mat = matrix;
		this->rowlen = matrix.size();
		this->collen = matrix[0].size();
		this->edgesize = 0;
		for (int i = 0; i < rowlen; i++)
			for (int j = 0; j < collen; j++)
				if (mat[i][j] == '1')
					search(i, j, 0);
		return edgesize*edgesize;
	}
	void search(int i, int j, int stepsize)
	{
		if (i + stepsize >= rowlen || j + stepsize >= collen ) return;
		for (int k = 0; k <= stepsize; k++)
		{
			//�ж��µ������к�������
			if (mat[i + stepsize][j + k] != '1') return; 
			if (mat[i + k][j + stepsize] != '1') return;
		}
		if (edgesize < stepsize + 1) //ע��䳤����(i,j)����Ҫ������һ
			edgesize = stepsize+1;
		search(i, j, stepsize + 1); //������һ������̽��

	}
private:
	vector<vector<char>> mat;
	int edgesize;
	int rowlen;
	int collen;
};
int main()
{

	
	system("pause");
	return 0;
}



