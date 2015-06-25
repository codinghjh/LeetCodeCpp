#include <iostream>
#include <vector>
#include "Solutions.h"

using namespace std;

int maxProduct(vector<int>& nums) {
	int length = nums.size();
	int** dp = new int*[length];
	for (auto i = 0; i != length; i++)
	{
		dp[i] = new int[length];
		for (auto j = 0; j != length; j++)
			dp[i][j] = 0;
	}
	for (auto i = 0; i != length; i++)
	{
		dp[i][i] = nums[i];
	}
	for (auto len = 2; len != length; len++)
		for (auto i = 0; i + len != length; i++)
		{
			dp[i][i + len - 1] = dp[i][i + len - 2] * nums[i + len - 1];
		}
	int max = 0;
	for (auto i = 0; i != length; i++)
		for (auto j = i; j != length; j++)
		{
			if (max < dp[i][j])
				max = dp[i][j];
		}
	return max;
}