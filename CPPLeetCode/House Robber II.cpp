#include <iostream>
#include <vector>
#include <algorithm>
#include "Solutions.h"

using namespace std;

int rob1(vector<int>& nums) {
	if (nums.size() == 0)
		return 0;
	if (nums.size() == 1)
		return nums[0];
	vector<vector<int>> dp;
	for (int i = 0; i != 2; i++)
	{
		vector<int> v(nums.size(), 0);
		dp.push_back(v);
	}
	//0
	dp[1][1] = nums[1];
	for (int i = 2; i < nums.size(); i++)
	{
		dp[1][i] = dp[0][i - 1] + nums[i];
		dp[0][i] = max(dp[1][i - 1], dp[0][i - 1]);
	}
	int tmp = max(dp[0][nums.size() - 1], dp[1][nums.size() - 1]);
	//1
	if (nums.size() == 2)
		return max(tmp, nums[0]);
	dp[1][1] = nums[0];
	dp[0][1] = nums[0];
	for (int i = 2; i < nums.size() - 1; i++)
	{
		dp[1][i] = dp[0][i - 1] + nums[i];
		dp[0][i] = max(dp[1][i - 1], dp[0][i - 1]);
	}
	int tmp1 = max(dp[0][nums.size() - 2], dp[1][nums.size() - 2]);
	return max(tmp, tmp1);
}

int main()
{
	vector<int> v = { 2, 1, 1,1 };
	cout<<rob1(v);
	cout << endl;
	return 0;
}