#include <iostream>
#include <unordered_set>

using namespace std;

bool containsDuplicate(vector<int>& nums) {
	if (nums.size() <= 1)
		return false;
	unordered_set<int> setN;
	for (int i = 0; i != nums.size(); i++)
	{
		if (setN.find(nums[i]) != setN.end())
			return true;
		setN.insert(nums[i]);
	}
	return false;
}

