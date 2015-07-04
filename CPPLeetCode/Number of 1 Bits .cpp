#include <iostream>
#include <cstdint>
#include "Solutions.h"

using namespace std;

int hammingWeight(uint32_t n) {
	int num = 0;
	uint32_t tmp = 0;
	for (auto i = 0; i < 32; i++)
	{
		tmp = n & 1;
		if (tmp == 1)
			num++;
		n=n >> 1;
	}
	return num;
}