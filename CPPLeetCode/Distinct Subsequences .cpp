#include <iostream>
#include "Solutions.h"

using namespace std;

int numDistinct(string s, string t) {
	if (s.length() < t.length())
		return 0;
	int lenS = s.length();
	int lenT = t.length();
	int** dp = new int*[lenS];
	for (int i = 0; i != lenS; i++)
	{
		dp[i] = new int[lenT];
		for (int j = 0; j != lenT; j++)
			dp[i][j] = 0;
	}
	if (s[0] == t[0])
		dp[0][0] = 1;
	else
		dp[0][0] = 0;
	for (int i = 1; i != lenS; i++)
	{
		if (s[i] == t[0])
			dp[i][0] = dp[i - 1][0]+1;
		else
			dp[i][0] = dp[i - 1][0];
	}

	for (int i = 1; i != lenS; i++)
		for (int j = 1; j != lenT&&j<=i; j++)
		{
			if (s[i] == t[j])
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
			else
				dp[i][j] = dp[i - 1][j];
		}

	return dp[lenS - 1][lenT - 1];
}