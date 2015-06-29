#include <iostream>
#include <vector>
#include <algorithm>
#include "Solutions.h"

using namespace std;

int maximumGap(vector<int>& nums) {
	if (nums.empty()||nums.size() < 2)
		return 0;
	int maxAll = *max_element(nums.begin(), nums.end());
	int minAll = *min_element(nums.begin(), nums.end());
	double distance = ((double)maxAll - minAll) / (nums.size()-1);
	vector<int> minElements(nums.size()-1, INT_MAX);
	vector<int> maxElements(nums.size()-1, INT_MIN);
	for (int i = 0; i != nums.size(); i++)
	{
		if (nums[i] == maxAll)
			continue;
		int id = (int)((nums[i] - minAll) / distance);
		maxElements[id] = max(maxElements[id], nums[i]);
		minElements[id] = min(minElements[id], nums[i]);
	}
	int maxGap = 0, preMax = maxElements[0];
	for (int i = 1; i != nums.size()-1; i++)
	{
		if (minElements[i] == INT_MAX)
			continue;
		maxGap = max(maxGap, minElements[i] - preMax);
		preMax = maxElements[i];
	}
	maxGap = max(maxGap, maxAll - preMax);
	return maxGap;
}