#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>
#include "Solutions.h"

using namespace std;

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
	vector<vector<int>> result;
	vector<vector<int>> tmpV;
	set<vector<int>> test;
	
	sort(nums.begin(), nums.end());
	for (int i = 0; i != nums.size(); i++)
	{
		tmpV.clear();
		copy(result.begin(), result.end(), back_inserter(tmpV));
		vector<int> iv;
		iv.push_back(nums[i]);
		for (int j = 0; j != tmpV.size(); j++)
		{
			vector<int> tmp = tmpV[j];
			tmp.push_back(nums[i]);
			if (test.find(tmp) == test.end())
			{
				result.push_back(tmp);
				test.insert(tmp);
			}	
		}
		if (test.find(iv) == test.end())
		{
			result.push_back(iv);
			test.insert(iv);
		}
		
	}
	vector<int> em;
	result.push_back(em);
	return result;
}