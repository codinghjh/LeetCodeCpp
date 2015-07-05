#include <iostream>
#include <unordered_map>
#include <stack>
#include "Solutions.h"

using namespace std;

bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
	if (numCourses <= 1)
		return true;
	unordered_map<int, vector<int>> map;
	vector<int> du(numCourses, 0);
	stack<int> zeros;
	int left = 0, right = 0;
	for (auto i = 0; i != prerequisites.size(); i++)
	{
		left = prerequisites[i].first;
		right = prerequisites[i].second;
		auto it = map.find(left);
		vector<int> v;
		if (it != map.end())
		{
			v = map[left];
		}
		v.push_back(right);
		map[left] = v;
		du[right]++;
	}
	for (auto i = 0; i != numCourses; i++)
	{
		if (du[i] == 0)
		{
			zeros.push(i);
		}
	}
	while (!zeros.empty())
	{
		int z = zeros.top();
		zeros.pop();
		if (map.find(z) == map.end())
			continue;
		vector<int> zv = map[z];
		for (auto i = 0; i != zv.size(); i++)
		{
			if (du[zv[i]] != 0)
				du[zv[i]]--;
			if (du[zv[i]] == 0)
				zeros.push(zv[i]);
		}
	}
	for (auto i = 0; i != du.size(); i++)
		if (du[i] != 0)
			return false;
	return true;
}