#include <iostream>
#include <set>
#include <vector>
#include "Solutions.h"

using namespace std;

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
	multiset<long long> mset;
	for (int i = 0; i != nums.size(); i++)
	{
		if (mset.size() > k)
			mset.erase(mset.find(nums[i - k - 1]));
		auto it = mset.lower_bound(nums[i]);
		auto it1 = mset.upper_bound(nums[i]);
		if (it != mset.end() && abs(nums[i] - *it) <= t)
			return true;
		if (it1 != mset.begin() && abs(nums[i] - *(--it1)) <= t)
			return  true;
		mset.insert(nums[i]);
	}
	return false;
}