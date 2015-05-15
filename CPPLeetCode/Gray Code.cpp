#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <iterator>
#include "Solutions.h"

using namespace std;

vector<int> grayCode(int n) {
	vector<int> result;
	if (n < 0)
		return result;
	vector<int> tmp;
	if (n == 0)
	{
		result.push_back(0);
		return result;
	}
	result.push_back(0);
	result.push_back(1);
	for (int i = 1; i != n; i++)
	{
		tmp.clear();
		copy(result.begin(), result.end(), back_inserter(tmp));
		for (int j = tmp.size() - 1; j >= 0; j--)
		{
			result.push_back(tmp[j] + pow(2, i));
		}
	}
	return result;

}
