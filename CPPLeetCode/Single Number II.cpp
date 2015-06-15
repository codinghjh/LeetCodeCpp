#include <iostream>
#include <vector>
#include "Solutions.h"

using namespace std;

int singleNumber(vector<int>& nums) {
	int one = 0, two = 0, three = 0;
	for (auto i = 0; i != nums.size(); i++)
	{
		three = two&nums[i];
		two = (two | one&nums[i])&~three;
		one = (one | nums[i])&~three;
	}
	return one;
}