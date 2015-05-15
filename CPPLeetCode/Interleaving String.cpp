#include <iostream>
#include "Solutions.h"

using namespace std;

bool isInterleave(string s1, string s2, string s3) {
	if (s1.length() + s2.length() != s3.length())
		return false;
	if (s1.length() == 0 && s2.length() == 0 && s3.length() == 0)
		return true;
	bool*** dp = new bool**[s3.length() + 1];
	for (int i = 0; i != s3.length() + 1; i++)
	{
		dp[i] = new bool*[s1.length() + 1];
		for (int j = 0; j != s1.length() + 1; j++)
		{
			dp[i][j] = new bool[s2.length() + 1];
			for (int k = 0; k != s2.length() + 1; k++)
				dp[i][j][k] = false;
		}
	}
	if (s1[0] == s3[0])
		dp[1][1][0] = true;
	if (s2[0] == s3[0])
		dp[1][0][1] = true;
	for (int i = 2; i != s3.length() + 1; i++)
	{
		for (int j = 0; j != s1.length() + 1; j++)
			for (int k = 0; k != s2.length() + 1; k++)
			{
				if (dp[i - 1][j][k])
				{
					if (j != s1.length())
					dp[i][j + 1][k] = dp[i][j + 1][k]||(j < s1.size()) && (s3.at(i - 1) == s1.at(j));
					if (k != s2.length())
					dp[i][j][k + 1] = dp[i][j][k + 1]||(k < s2.size()) && (s3.at(i - 1) == s2.at(k));
				}
			}
	}
	return dp[s3.length()][s1.length()][s2.length()];
}