#include <iostream>
#include <unordered_set>
#include "Solutions.h"

using namespace std;

bool wordBreak(string s, unordered_set<string>& wordDict) {
	if (wordDict.find(s) != wordDict.end())
		return true;
	int length = s.length();
	vector<vector<bool>> dp;
	for (auto i = 0; i != length; i++)
	{
		vector<bool> v(length, false);
		dp.push_back(v);
	}
	for (auto len = 0; len != length + 1; len++)
	{
		for (auto i = 0; (i+len-1)!= length; i++)
		{
			if (wordDict.find(s.substr(i, len)) != wordDict.end())
				dp[i][i + len - 1] = true;
		}
	}
	for (auto i = 0; i != length; i++)
	{
		if (dp[0][i] == true)
			continue;
		else
		{
			for (auto j = 0; j != i; j++)
			{
				if (dp[0][j] == true && dp[j + 1][i] == true)
				{
					dp[0][i] = true;
					break;
				}
					
			}
		}
	}
	return dp[0][length - 1];
}