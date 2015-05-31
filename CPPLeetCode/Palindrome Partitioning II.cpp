#include <iostream>
#include "Solutions.h"

using namespace std;

bool** dp;

int minCut(string s) {
	if (s.length() <= 1)
		return 0;
	dp = new bool*[s.length()];
	for (int i = 0; i != s.length(); i++)
	{
		dp[i] = new bool[s.length()];
		for (int j = 0; j != s.length(); j++)
			dp[i][j] = false;
	}
	for (int i = 0; i != s.length(); i++)
		dp[i][i] = true;
	for (int i = 0; i != s.length() - 1; i++)
	{
		if (s[i] == s[i + 1])
			dp[i][i + 1] = true;
	}
	for (int len = 2; len < s.length(); len++)
	{
		for (int i = 0; (i + len) != s.length(); i++)
		{
			if (s[i] == s[i + len] && dp[i + 1][i + len - 1])
				dp[i][i + len] = true;
		}
	}
	int* cuts = new int[s.length()];
	for (int i = 0; i != s.length(); i++)
		cuts[i] = i;
	for (int i = 1; i != s.length(); i++)
	{
		cuts[i] = cuts[i - 1] + 1;
		for (int j = 0; j != i; j++)
		{
			if (dp[j][i] == true)
			{
				if (j == 0)
				{
					cuts[i] = 0;
				}
					
				else if (cuts[i]>cuts[j-1]+1)
					cuts[i] = cuts[j - 1] + 1;
			}
		}
	}
	return cuts[s.length() - 1];

}