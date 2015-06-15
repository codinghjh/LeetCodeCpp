#include <iostream>
#include <vector>
#include "Solutions.h"

using namespace std;

int singleNumber(vector<int>& nums) {
	int num = 0;
	for (auto i = 0; i != nums.size(); i++)
	{
		num = num^nums[i];
	}
	return num;
}