#include <iostream>
#include <vector>
#include <algorithm>
#include "Solutions.h"

using namespace std;

int findMinValue(vector<int>& nums, int start, int end)
{
	if (start > end)
		return INT_MAX;
	if (start == end)
		return nums[start];
	int minValue = nums[start];
	int  mid = 0;
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (minValue < nums[mid])
			start = mid + 1;
		else if (minValue == nums[mid])
		{
			minValue = min(findMinValue(nums,start,mid), findMinValue(nums,mid+1,end));
			return minValue;
		}
		else
		{
			minValue = nums[mid];
			end = mid - 1;
		}
	}
	return minValue;
}

int findMin1(vector<int>& nums) {
	if (nums.size() <= 0)
		return 0;
	if (nums.size() == 1)
		return nums[0];
	return findMinValue(nums, 0, nums.size() - 1);
}