#include <iostream>
#include <vector>
#include "Solutions.h"

using namespace std;

int candy(vector<int>& ratings) {
	int length = ratings.size();
	if (length<=1)
		return length;
	vector<int> value(length, 1);
	for (auto i = 1; i != length * 2; i++)
	{
		if (ratings[(i%length)] > ratings[(i%length) - 1])
			value[i%length] = value[i%length - 1] + 1;
	}
	for (auto i = 2 * length - 1; i > 0; i--)
	{
		if ((ratings[(i%length)] < ratings[(i%length) - 1])&&(value[i%length]>=value[i%length-1]))
			value[i%length-1] = value[i%length] + 1;
	}
	int sum = 0;
	for (auto i = 0; i != length; i++)
		sum = sum + value[i];
	return sum;
}