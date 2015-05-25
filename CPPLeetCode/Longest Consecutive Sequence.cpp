#include <iostream>
#include <vector>
#include <set>
#include "Solutions.h"

using namespace  std;

int longestConsecutive(vector<int>& nums) {
	int* p = new int[nums.size()];
	set<int> pre,isVisited;
	for (auto i = 0; i != nums.size(); i++)
	{
		p[i] = 0;
		if (pre.find(nums[i]) == pre.end())
			pre.insert(nums[i]);
	}
		
	for (auto i = 0; i != nums.size(); i++)
	{
		if (isVisited.find(nums[i]) != isVisited.end())
			continue;
		isVisited.insert(nums[i]);
		p[i] = 1;
		int key = nums[i];
		bool isBreak = false;
		while (!isBreak)
		{
			if (pre.find(key - 1) != pre.end())
			{
				p[i] = p[i] + 1;
				key--;
				isVisited.insert(key - 1);
			}
			else
				isBreak = true;
				
		}
	}
	auto max = INT_MIN;
	for (auto i = 0; i != nums.size(); i++)
	{
		if (max < p[i])
			max = p[i];
	}
	return max;
}