#include <iostream>
#include <math.h>
#include <stack>
#include "Solutions.h"

using namespace std;

int rangeBitwiseAnd(int m, int n) {
	int num = 0;
	while (m != n)
	{
		num++;
		m = m >> 1;
		n = n >> 1;
	}
	return n << num;
}