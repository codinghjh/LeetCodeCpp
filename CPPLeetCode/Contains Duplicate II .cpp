#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
	if (k <= 0)
		return false;
	unordered_map<int, int> map;
	for (int i = 0; i != nums.size(); i++)
	{
		auto it = map.find(nums[i]);
		if (it == map.end())
		{
			map[nums[i]] = i;
		}
		else
		{
			if (i - map[nums[i]] <= k)
				return true;
			else
			{
				map[nums[i]] = i;
			}
		}
	}
	return false;
}