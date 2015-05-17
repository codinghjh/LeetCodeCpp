#include <iostream>
#include <vector>
#include "Solutions.h"

using namespace std;

int maxProfit3(vector<int>& prices) {
	if (prices.size() <= 1)
		return 0;
	vector<int> left(prices.size(), 0);
	vector<int> right(prices.size(), 0);
	int min = prices[0];
	for (int i = 1; i != prices.size()-1; i++)
	{
		if (prices[i] < min)
			min = prices[i];
		if (prices[i] - min>left[i - 1])
			left[i] = prices[i] - min;
		else
			left[i] = left[i - 1];
	}
	int max = prices[prices.size() - 1];
	for (int i = prices.size() - 2; i >= 0; i--)
	{
		if (prices[i] > max)
			max = prices[i];
		if (max-prices[i]>right[i + 1])
			right[i] = max - prices[i];
		else
			right[i] = right[i + 1];
	}
	max = 0;
	for (int i = 0; i != prices.size()-1; i++)
		if (max < right[i] + left[i])
			max = right[i] + left[i];
	return max;
}