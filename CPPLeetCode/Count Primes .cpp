#include <iostream>
#include <math.h>
#include "Solutions.h"

using namespace std;

int countPrimes(int n) {
	if (n <= 2)
		return 0;
	int result = 0;
	vector<bool> v(n , true);
	v[2] = true;
	for (auto i = 2; i <= sqrt(n)+1; i++)
	{
		if (v[i] == true)
		{
			for (auto j = 2; j*i < n; j++)
				v[j*i] = false;
		}
	}
	for (auto i = 2; i != n; i++)
		if (v[i] == true)
			result++;
	return result;

}