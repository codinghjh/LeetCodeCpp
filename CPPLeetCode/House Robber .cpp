#include <iostream>
#include <vector>
#include <algorithm>
#include "Solutions.h"

using namespace std;

int rob(vector<int>& nums) {
	if (nums.size() == 0)
		return 0;
	if (nums.size() == 1)
		return nums[0];
	vector<vector<int>> dp;
	for (auto i = 0; i != 2; i++)
	{
		vector<int> v(nums.size(), 0);
		dp.push_back(v);
	}
	//dp[0] without  dp[1] include
	dp[0][0] = 0;
	dp[1][0] = nums[0];
	for (auto i = 1; i != nums.size(); i++)
	{
		dp[0][i] = max(dp[1][i - 1],dp[0][i-1]);
		dp[1][i] = dp[0][i - 1]+nums[i];
		
	}
	return max(dp[0][nums.size() - 1], dp[1][nums.size() - 1]);
}