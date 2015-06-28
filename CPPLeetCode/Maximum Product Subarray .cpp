#include <iostream>
#include <vector>
#include <algorithm>
#include "Solutions.h"

using namespace std;

int maxProduct(vector<int>& nums) {
	int length = nums.size();
	if (length < 1)
		return 0;
	if (length == 1)
		return nums[0];
	int global = nums[0], max_local = nums[0], min_local = nums[0];
	for (auto i = 1; i != nums.size(); i++)
	{
		int copy = max_local;
		max_local = max(max(nums[i], max_local*nums[i]), min_local*nums[i]);
		min_local = min(min(nums[i],nums[i]*min_local),nums[i]*copy );
		global = max(global, max_local);
	}
	return global;
}