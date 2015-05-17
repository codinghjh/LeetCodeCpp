#include <iostream>
#include <vector>
#include "Solutions.h"

using namespace std;

int maxProfit(vector<int>& prices) {
	if (prices.size() == 0)
		return 0;
	vector<int> profit;
	int min = INT_MAX;
	for (int i = 0; i != prices.size(); i++)
	{
		if (min > prices[i])
			min = prices[i];
		profit.push_back(min);
	}
	int max = INT_MIN;
	for (int i = 0; i != prices.size(); i++)
	{
		if (max < prices[i] - profit[i])
			max = prices[i] - profit[i];
	}
	return max;
}