#include <iostream>
#include <vector>
#include "Solutions.h"

using namespace std;

void rotate(vector<int>& nums, int k) {
	int len = nums.size();
	if (len == 0)
		return;
	k = k%len;
	if (k == 0)
		return;
	vector<int> v(k, 0);
	for (auto i = len - k; i != len; i++)
		v[i - len + k] = nums[i];
	for (auto i = len - k - 1; i >= 0; i--)
		nums[i + k] = nums[i];
	for (auto i = 0; i != k; i++)
		nums[i] = v[i];
}