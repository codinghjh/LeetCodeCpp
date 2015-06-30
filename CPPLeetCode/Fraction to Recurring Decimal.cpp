#include <iostream>
#include <string>
#include <unordered_map>
#include "Solutions.h"

using namespace std;

string fractionToDecimal(int numerator, int denominator) {
	if (denominator == 0)
		return nullptr;
	string result;
	unordered_map<int, int> map;
	if (((double)numerator / denominator) < 0)
		result = result + "-";
	long int n = numerator,d=denominator;
	n = abs(n);
	d = abs(d);
	result += to_string(n / d);
	long int r = n%d;
	if (r == 0)
		return result;
	result += ".";
	while (r)
	{
		if (map.find(r) != map.end())
		{
			result.insert(map[r], 1, '(');
			result += ")";
			return result;
		}
		map[r] = result.size();
		r=r * 10;
		result += to_string(r / d);
		r = r%d;
	}
	return result;
}