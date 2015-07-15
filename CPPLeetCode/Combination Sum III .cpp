#include <iostream>
#include <vector>
#include "Solutions.h"

using namespace std;

vector<vector<int>> result;

void findCombinationSum(int k, int start, int sum,int n,vector<int> v)
{
	if (k == 0)
	{
		if (sum == n)
		{
			result.push_back(v);
		}
		return;
	}
	for (int i = start; i <= 9; i++)
	{
		if (sum + i <= n)
		{
			sum += i;
			v.push_back(i);
			findCombinationSum(k - 1, i + 1, sum, n,v);
			v.pop_back();
			sum -= i;
		}
		else
			return;

	}
}

vector<vector<int>> combinationSum3(int k, int n) {
	if (k == 0)
		return result;
	if (k == 1 && n <= 9)
	{
		vector<int> v;
		v.push_back(k);
		result.push_back(v);
		return result;
	}
	for (int i = 1; i != 10; i++)
	{
		if (i > n / k)
			break;
		vector<int> v;
		v.push_back(i);
		findCombinationSum(k - 1, i + 1, i, n,v);
	}
	return result;
}
