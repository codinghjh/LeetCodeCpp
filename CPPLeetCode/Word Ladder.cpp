#include <iostream>
#include <unordered_set>
#include <set>
#include "Solutions.h"

using namespace std;

int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
	if (beginWord == endWord)
		return 0;
	set<string> visited;
	vector<string> parent, child;
	set<string> dic;
	unordered_set<string>::iterator it;
	int wordLength = beginWord.size();
	for (it = wordDict.begin(); it != wordDict.end(); it++)
		dic.insert(*it);
	parent.push_back(beginWord);
	visited.insert(beginWord);
	int length = 1;
	while (visited.size() != wordDict.size())
	{
		for (int i = 0; i != parent.size(); i++)
		{
			
			for (int j = 0; j != wordLength; j++)
			{
				string key = parent[i];
				for (char c = 'a'; c != 'z' + 1; c++)
				{
					key[j] = c;
					if (key == endWord)
						return length + 1;
					if (dic.find(key) != dic.end() && visited.find(key) == visited.end())
					{
						child.push_back(key);
						visited.insert(key);
					}
				}
			}
		}
		parent.clear();
		for (int i = 0; i != child.size(); i++)
			parent.push_back(child[i]);
		length++;
		child.clear();
		if (parent.size() == 0)
			return 0;
	}
	return 0;
}