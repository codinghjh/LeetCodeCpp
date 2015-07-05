#include <iostream>
#include <unordered_map>
#include "Solutions.h"

using namespace std;

bool isIsomorphic(string s, string t) {
	if (s.length() != t.length())
		return false;
	if (s.length() == 0)
		return true;
	unordered_map<char, int> mapS;
	unordered_map<char, int> mapT;
	for (auto i = 0; i != s.length(); i++)
	{
		auto itS = mapS.find(s[i]);
		auto itT = mapT.find(t[i]);
		if (itS == mapS.end() && itT == mapT.end())
		{
			mapS[s[i]] = i;
			mapT[t[i]] = i;
		}
		else if (itS != mapS.end() && itT != mapT.end())
		{
			if (itS->second != itT->second)
				return false;
		}
		else
			return false;
	}
	return true;
}