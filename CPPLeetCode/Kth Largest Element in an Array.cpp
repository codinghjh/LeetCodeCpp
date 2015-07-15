#include <iostream>
#include <vector>
#include "Solutions.h"

using namespace std;

void swap(vector<int> &nums, int i, int j)
{
	int tmp = nums[i];
	nums[i] = nums[j];
	nums[j] = tmp;
}

void createMaxHeap(vector<int> &nums)
{
	int j = 0;
	for (int i = nums.size() / 2; i >= 0; i--)
	{
		j = i;
		while (j < nums.size())
		{
			if (2 * j + 1 < nums.size())
			{
				int minChild = 2 * j + 1;
				if (2 * j + 2 < nums.size())
					minChild = nums[minChild] > nums[minChild + 1] ? minChild : minChild + 1;
				if (nums[minChild] > nums[j])
					swap(nums, minChild, j);
				j = minChild;
			}
			else
				break;
		}

	}
}

int findKthLargest(vector<int>& nums, int k) {
	if (nums.size() == 0)
		return 0;
	if (nums.size() == 1)
		return nums[0];
	createMaxHeap(nums);
	for (int i = 1; i < k; i++)
	{
		nums[0] = nums[nums.size() - i];
		nums[nums.size() - i] = INT_MIN;
		createMaxHeap(nums);
	}
	return nums[0];
}

int main()
{
	vector<int> nums = { 3, 2, 1, 5, 6, 4 };
	int k = 2;
	cout << findKthLargest(nums, k);
	cout << endl;
	return 0;
}