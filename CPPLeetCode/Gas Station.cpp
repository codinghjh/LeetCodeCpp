#include <iostream>
#include <vector>
#include "Solutions.h"

using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
	int length = gas.size();
	if (length == 0)
		return -1;
	for (auto i = 0; i != length; i++)
	{
		gas[i] = gas[i] - cost[i];
	}
	int sum = -1, index = -1, len = 0;
	for (auto i = 0; i < 2 * length - 1; i++)
	{
		if (sum < 0)
		{
			if (i > length - 1)
				break;
			sum = gas[i];
			len = 1;
			index = i;
		}
		else
		{
			sum += gas[i%length];
			len++;
		}
		if (sum>=0 && len == length)
			return index;
	}
	return -1;
}