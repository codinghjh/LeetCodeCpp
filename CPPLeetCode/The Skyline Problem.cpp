#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include "Solutions.h"

using namespace std;

struct event
{
	int index;
	int x;
	int times;
	event(int i, int j, int k)
	{
		index = i;
		x = j;
		times = k;
	}
};



vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
	vector<pair<int, int>> result;
	if (buildings.size() == 0)
		return result;
	unordered_set<int> activeHeights;
	vector<int> heights;
	int maxHeight=0,newHeight;
	vector<event> ev;
	for (int i = 0; i != buildings.size(); i++)
	{
		heights.push_back(buildings[i][2]);
		int index = heights.size() - 1;
		ev.push_back(event(index, buildings[i][0], 0));
		ev.push_back(event(index, buildings[i][1], 1));
	}
	sort(ev.begin(), ev.end(), [](const event&v1, const event&v2)
	{
		if (v1.x != v2.x)
			return v1.x < v2.x;
		return v1.times < v2.times;
	}
		);
	for (int i = 0; i != ev.size(); i++)
	{
		newHeight = 0;
		int curX = ev[i].x;
		if (ev[i].times == 0)
		{
			while (i < ev.size())
			{
				if (curX != ev[i].x||ev[i].times==1)
					break;
				newHeight = max(heights[ev[i].index], newHeight);
				activeHeights.insert(ev[i].index);
				++i;
			}
			i--;
			if (maxHeight < newHeight)
			{
				maxHeight = newHeight;
				result.push_back(pair<int, int>(ev[i].x, maxHeight));
			}
		}
		else
		{
			while (i < ev.size())
			{
				if (curX != ev[i].x||ev[i].times==0)
					break;
				newHeight = max(newHeight, heights[ev[i].index]);
				activeHeights.erase(ev[i].index);
				i++;
			}
			i--;
			
			if (maxHeight == newHeight)
			{
				newHeight = 0;
				for (auto it = activeHeights.begin(); it != activeHeights.end(); it++)
				{
					if (newHeight < heights[*it])
						newHeight = heights[*it];
				}
				if (newHeight < maxHeight)
				{
					maxHeight = newHeight;
					result.push_back(pair<int, int>(ev[i].x, newHeight));
				}
				
			}
		}
	}
	return result;
}

int main()
{
	vector<vector<int>> v;
	vector<int> v1 = {0,2,3 };
	vector<int> v2 = { 2,5,3 };
	v.push_back(v1);
	v.push_back(v2);
	/*
	vector<int> v3 = { 5, 12, 12 };
	vector<int> v4 = { 15, 20, 10 };
	vector<int> v5 = { 19,24,8 };
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3); 
	v.push_back(v4);
	v.push_back(v5);
	*/
	vector<pair<int, int>> result = getSkyline(v);
	for (int i = 0; i != result.size(); i++)
		cout << result[i].first << " " << result[i].second << endl;
	return 0;
}