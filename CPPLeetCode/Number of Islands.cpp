#include <iostream>
#include <vector>
#include <queue>
#include "Solutions.h"

using namespace std;

void dfsIslands(vector<vector<char>>& grid, int i, int j)
{
	if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
		return;
	if (grid[i][j] == '1')
	{
		grid[i][j] = '2';
		dfsIslands(grid, i - 1, j);
		dfsIslands(grid, i, j - 1);
		dfsIslands(grid, i + 1, j);
		dfsIslands(grid, i, j + 1);
	}
}

int numIslands(vector<vector<char>>& grid) {
	if (grid.size() == 0)
		return 0;
	int isLands = 0;
	for (auto i = 0; i < grid.size(); i++)
	{
		for (auto j = 0; j < grid[0].size(); j++)
		{
			if (grid[i][j] == '1')
			{
				
				dfsIslands(grid, i, j);
				isLands++;;
			}				
		}
	}
	return isLands;
}