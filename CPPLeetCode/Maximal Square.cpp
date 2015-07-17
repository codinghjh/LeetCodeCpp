#include <iostream>
#include <vector>
#include <algorithm>
#include "Solutions.h"

using namespace std;

int maximalSquare(vector<vector<char>>& matrix) {
	if (matrix.size() == 0)
		return 0;
	int maxSize = 0;
	vector<vector<int>> dp;
	for (int i = 0; i < matrix.size(); i++)
	{
		vector<int> v(matrix[0].size(), 0);
		dp.push_back(v);
	}
	for (int i = 0; i < matrix.size(); i++)
	{
		if (matrix[i][0] == '1')
		{
			dp[i][0] = 1;
			maxSize = 1;
		}
			
	}
	for (int i = 0; i < matrix[0].size(); i++)
		if (matrix[0][i] == '1')
		{
			dp[0][i] = 1;
			maxSize = 1;
		}
			
	for (int i = 1; i <matrix.size(); i++)
	{
		for (int j = 1; j < matrix[0].size(); j++)
		{
			if (matrix[i][j] == '1')
			{
				dp[i][j] = min(min(dp[i-1][j-1],dp[i][j-1]), dp[i-1][j])+1;
				if (dp[i][j] > maxSize)
					maxSize = dp[i][j];
			}
		}
	}
	return maxSize*maxSize;
}

int main()
{
	vector<char> v1 = { '0' };
	vector<vector<char>> v;
	v.push_back(v1);
	cout << maximalSquare(v) << endl;
	return 0;
}