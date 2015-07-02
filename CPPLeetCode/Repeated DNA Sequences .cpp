#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include "Solutions.h"

using namespace std;

int getValue(char c)
{
	if (c == 'A')
		return 0;
	else if (c == 'C')
		return 1;
	else if (c == 'G')
		return 2;
	else if (c == 'T')
		return 3;
}

vector<string> findRepeatedDnaSequences(string s) {
	vector<string> result;
	if (s.size() <= 10)
		return result;
	unordered_set<int>  setS;
	unordered_set<int> re;
	bool hashMap[1024 * 1024];
	memset(hashMap, false, sizeof(hashMap));
	//bool hashMap[10 * 10];
	int hashValue = 0;
	for (auto i = 0; i != 10; i++)
	{
		hashValue = hashValue << 2;
		hashValue = hashValue | getValue(s[i]);
	}
	hashMap[hashValue] = true;
	for (auto i = 10; i != s.size(); i++)
	{
		hashValue = hashValue << 2;
		hashValue = hashValue | getValue(s[i]);
		hashValue = hashValue&~(0x300000);
		if (hashMap[hashValue])
		{
			if (re.find(hashValue) == re.end())
			{
				result.push_back(s.substr(i - 9, 10));
				re.insert(hashValue);
			}
		}
		else
			hashMap[hashValue] = true;
	}
	return result;
}