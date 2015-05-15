#include<iostream> 
#include"Solutions.h"

using namespace std;

int numTrees(int n) {
	int* p = new int[n+1];
	p[0] = 1;
	p[1] = 1;
	p[2] = 2;
	for (int i = 3; i < n + 1; i++)
	{
		p[i] = 0;
		for (int j = 1; j != i + 1; j++)
		{
			p[i] = p[i] + p[j - 1] * p[i - j];
		}
	}
	return p[n];
}