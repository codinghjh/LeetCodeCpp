#include <iostream>
#include <vector>
#include "Solutions.h"

using namespace std;

int findMin(vector<int>& nums) {
	if (nums.size() <= 0)
		return 0;
	if (nums.size() == 1)
		return nums[0];
	int minValue = nums[0];
	int start = 0, end = nums.size() - 1,mid=0;
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (minValue <= nums[mid])
			start = mid + 1;
		else
		{
			minValue = nums[mid];
			end = mid - 1;
		}
	}
	return minValue;
}