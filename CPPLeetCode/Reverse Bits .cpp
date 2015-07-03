#include <iostream>
#include <cstdint>
#include "Solutions.h"

using namespace std;

uint32_t reverseBits(uint32_t n) {
	uint32_t tmp = 0;
	uint32_t result = 0;
	for (auto i = 0; i != 32; i++)
	{
		tmp = n;
		tmp = tmp & 1;
		n = n >> 1;
		result=result << 1;
		if (tmp == 1)
		{
			result = result |1;
		}
	}
	return result;
}