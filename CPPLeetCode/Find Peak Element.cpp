#include <iostream>
#include <vector>
#include "Solutions.h"

using namespace std;

int findPeakElement(vector<int>& nums) {
	if (nums.size() <= 0)
		return 0;
	if (nums.size() == 0)
		return 0;
	int left = 0, right = nums.size() - 1,mid=0;
	while (left <= right)
	{
		if (left == right)
			return left;
		mid = (left + right) / 2;
		if (nums[mid] < nums[mid + 1])
			left = mid + 1;
		else
			right = mid;
	}
}