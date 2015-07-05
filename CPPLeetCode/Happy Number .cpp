#include <iostream>
#include <unordered_set>
#include "Solutions.h"

using namespace std;

bool isHappy(int n) {
	if (n == 1)
		return true;
	unordered_set<int> set;
	vector<int> v;
	while (true)
	{
		if (set.find(n) != set.end())
			return false;
		set.insert(n);
		while (n != 0)
		{
			v.push_back(n % 10);
			n = n / 10;
		}
		for (auto i = 0; i != v.size(); i++)
			n = n + v[i] * v[i];
		v.clear();
		if (n == 1)
			return true;
	}
	return false;
	
}