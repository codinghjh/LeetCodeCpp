#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
	vector<int> result;
	if (numCourses <= 0)
		return result;
	if (numCourses == 1)
	{
		result.push_back(0);
		return result;
	}
	unordered_map<int, vector<int>> map;
	vector<int> du(numCourses, 0);
	stack<int> zeros;
	int left = 0, right = 0;
	for (auto i = 0; i != prerequisites.size(); i++)
	{
		left = prerequisites[i].second;
		right = prerequisites[i].first;
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
			result.push_back(i);
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
			{
				zeros.push(zv[i]);
				result.push_back(zv[i]);
			}
				
		}
	}
	if (result.size() == numCourses)
		return result;
	else
	{
		result.clear();
		return result;
	}
}

/*
int main()
{
	int numcourses = 4;
	vector<pair<int, int>> v;
	v.push_back(pair<int, int>(1, 0));
	v.push_back(pair<int, int>(2, 0));
	v.push_back(pair<int, int>(3, 1));
	v.push_back(pair<int, int>(3, 2));
	vector<int> re = findOrder(numcourses, v);
	for (auto i = 0; i != re.size(); i++)
		cout << re[i] << " ";
	cout << endl;
	return 0;
}
*/