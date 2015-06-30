#include <iostream>
#include "Solutions.h"

using namespace std;

int titleToNumber(string s) {
	if (s.empty())
		return 0;
	int result = 0;
	for (auto i = 0; i != s.length(); i++)
	{
		result = result * 26 + s[i] - 'A' + 1;
	}
	return result;
}