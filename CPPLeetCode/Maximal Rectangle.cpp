#include <iostream>
#include <vector>
#include <stack>
#include <Windows.h>
#include "Solutions.h"

using namespace std;

int largestRectangle(vector<int>& height) {
	if (height.size() == 0) return 0;

	int res = 0;
	vector<int> tmp = height;
	tmp.push_back(0);  // Important

	stack<int> s;
	for (int i = 0; i < tmp.size(); i++)
	{
		if (s.empty() || (!s.empty() && tmp[i] >= tmp[s.top()])) s.push(i);
		else{
			while (!s.empty() && tmp[s.top()] > tmp[i])
			{
				int idx = s.top(); s.pop();
				int width = s.empty() ? i : (i - s.top() - 1);
				res = max(res, tmp[idx] * width);
			}
			s.push(i);  // Important
		}
	}
	return res;
}

int maximalRectangle(vector<vector<char> > &matrix) {
	if (matrix.empty() || matrix.size() == 0)
		return 0;
	int row = matrix.size(),col=matrix[0].size(),max=0;
	int **dp = new int*[row];
	for (int i = 0; i != row; i++)
	{
		dp[i] = new int[col+1];
		memset(dp[i], 0, sizeof(int)*(col+1));
	}
	for (int i = 0; i != col; i++)
	{
		if (matrix[0][i]=='1')
			dp[0][i] = 1;
	}
	vector<int> tmp(&dp[0][0],&dp[0][col]);
	
	max = largestRectangle(tmp);
	for (int i = 1; i != row; i++)
	{
		for (int j = 0; j != col; j++)
		{
			if (matrix[i][j] == '1')
			{
				dp[i][j] = dp[i - 1][j] + 1;
			}
		}
		vector<int> tmp1(&dp[i][0], &dp[i][col]);

		int max1 = largestRectangle(tmp1);
		if (max1 > max)
			max = max1;
	}
	for (int i = 0; i != row; i++)
	{
		delete[]dp[i];
	}
	delete[]dp;
	return max;
}
