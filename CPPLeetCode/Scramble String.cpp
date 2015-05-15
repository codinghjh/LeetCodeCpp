#include <iostream>
#include <string.h>
#include <algorithm>
#include "Solutions.h"

using namespace std;

//bool isScramble(string s1, string s2) {
//	if (s1.length() != s2.length())
//		return false;
//	bool result = false;
//	int len = s1.length();
//	if (len == 1)
//		return (s1[0]==s2[0]);
//	char* c1;
//	char* c2;
//	c1 = new char[len+1];
//	c2 = new char[len+1];
//	for (int i = 0; i != len; i++)
//	{
//		*(c1 + i) = s1[i];
//		*(c2 + i) = s2[i];
//	}
//	*(c1 + len) = '\0';
//	*(c2 + len) = '\0';
//	sort(c1, c1 + len);
//	sort(c2, c2 + len);
//	if (strcmp(c1, c2) != 0)
//		return false;
//	for (int i = 1; i != len&&!result; i++)
//	{
//		string s11 = s1.substr(0, i);
//		string s12=s1.substr(i,len-i);
//		string s21 = s2.substr(0, i);
//		string s22 = s2.substr(i, len - i);
//		result = isScramble(s11, s21) && isScramble(s12, s22);
//		if (!result)
//		{
//			string s31 = s2.substr(len - i, i);
//			string s32 = s2.substr(0,len-i);
//			result = isScramble(s11, s31) && isScramble(s12, s32);
//		}
//
//	}
//	return result;
//}

bool isScramble(string s1, string s2) {
	if (s1.length() != s2.length())
		return false;
	int len = s1.length();
	if (len == 1)
		return (s1[0]==s2[0]);
	bool*** dp = new bool**[len];
	for (int i = 0; i != len; i++)
	{
		dp[i] = new bool*[len];
		for (int j = 0; j != len; j++)
		{
			dp[i][j] = new bool[len];
		}
	}

	for (int i = 0; i != len; i++)
		for (int j = 0; j != len; j++)
		{
			dp[0][i][j] = (s1[i]==s2[j]);
		}

	for (int l = 2; l != len+1; l++)
		for (int i = 0; i + l != len+1; i++)
			for (int j = 0; j + l != len+1; j++)
			{
				dp[l - 1][i][j] = false;
				for (int k = 1; k != l; k++)
				{
					if (dp[k - 1][i][j] && dp[l - k - 1][i + k][j + k])
						dp[l - 1][i][j] = true;
					else if (dp[k - 1][i][j + l - k] && dp[l - k - 1][i + k][j])
						dp[l - 1][i][j] = true;
				}
			}
	return dp[len-1][0][0];
}