#include <iostream>
#include <vector>
#include <algorithm>
#include "Solutions.h"

using namespace std;

int calculateMinimumHP(vector<vector<int>>& dungeon) {
	int row = dungeon.size();
	if (row == 0)
		return 0;
	int col = dungeon[0].size();
	dungeon[row - 1][col - 1] = max(0 - dungeon[row - 1][col - 1], 0);
	for (auto i = row - 2; i >= 0; i--)
	{
		dungeon[i][col - 1] = max(0, dungeon[i + 1][col - 1] - dungeon[i][col - 1]);
	}
	for (auto i = col - 2; i >= 0; i--)
	{
		dungeon[row - 1][i] = max(0, dungeon[row - 1][i + 1] - dungeon[row - 1][i]);
	}
	for (auto i = row - 2; i >= 0; i--)
	{
		for (auto j = col - 2; j >= 0; j--)
		{
			dungeon[i][j] = max(0, min(dungeon[i + 1][j], dungeon[i][j + 1])-dungeon[i][j]);
		}
	}
	return 1 + dungeon[0][0];
}
