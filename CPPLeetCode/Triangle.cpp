#include <iostream>
#include <vector>
#include <algorithm>
#include "Solutions.h"

using namespace std;

int minimumTotal(vector<vector<int> > &triangle) {

	int col = triangle[triangle.size() - 1].size();
	int* p = new int[col];
	memset(p, 0, sizeof(p));
	p[0] = triangle[0][0];
	for (int i = 1; i != triangle.size(); i++)
		for (int j = triangle[i].size() - 1; j >= 0; j--)
		{
			if (j == triangle[i].size() - 1)
				p[j] = p[j - 1] + triangle[i][j];
			else if (j == 0)
				p[j] = p[j] + triangle[i][j];
			else
				p[j] = min(p[j], p[j - 1]) + triangle[i][j];
		}
	int result = p[0];
	for (int i = 1; i != col; i++)
		result = min(result, p[i]);
	return result;

}