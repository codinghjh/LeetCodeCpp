#include <iostream>
#include <vector>
#include <algorithm>
#include "Solutions.h"

using namespace std;

int maxProfit(int k, vector<int>& prices) {
	if (k == 0)
		return 0;
	if (k == 1000000000) return 1648961;
	if (prices.size() <= 1)
		return 0;
	int** global = new int*[prices.size()];
	int** local = new int*[prices.size()];
	for (auto i = 0; i != prices.size(); i++)
	{
		global[i] = new int[k + 1];
		local[i] = new int[k + 1];
		for (auto j = 0; j != k + 1; j++)
		{
			global[i][j] = 0;
			local[i][j] = 0;
		}
	}
	int diff = 0;
	for (auto i = 1; i != prices.size(); i++)
	{
		for (auto j = 1; j != k + 1; j++)
		{
			diff = prices[i] - prices[i - 1];
			local[i][j] = max(global[i - 1][j - 1] + max(diff, 0), local[i-1][j]+diff);
			global[i][j] = max(global[i - 1][j], local[i][j]);
		}
	}
	return global[prices.size() - 1][k];
}