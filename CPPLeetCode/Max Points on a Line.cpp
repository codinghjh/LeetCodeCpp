#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include "Solutions.h"

using namespace std;

int maxPoints(vector<Point>& points) {


	if (points.size() <3)
		return points.size();

	int maxP = 0;
	unordered_map<double, int> lines;
	int dup = 0;
	double k = 0;
	for (auto i = 0; i != points.size(); i++)
	{
		dup = 1;
		lines.clear();
		for (auto j = 0; j != points.size(); j++)
		{
			if (i == j)
				continue;
			if (points[i].x == points[j].x&&points[i].y == points[j].y)
			{
				dup++;
				continue;
			}
			if (points[i].x == points[j].x)
				lines[INT_MAX]++;
			else
			{
				k = ((double)points[i].y - points[j].y) / ((double)points[i].x - points[j].x);
				lines[k]++;
			}
		}
		if (maxP < dup)
			maxP = dup;
		for (auto l = lines.begin(); l != lines.end(); l++)
		{
			if (maxP < l->second + dup)
				maxP = l->second + dup;
		}
	}
	return maxP;

}