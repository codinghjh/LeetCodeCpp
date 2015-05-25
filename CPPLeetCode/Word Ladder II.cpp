#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include "Solutions.h"

using namespace std;

vector<vector<string>> result;
vector<string> tmpPath;

void buildPath(unordered_map<string,unordered_set<string>> &parent,const string &start,const string &end)
{
	tmpPath.push_back(start);
	if (start == end)
	{
		vector<string> aPath = tmpPath;
		reverse(aPath.begin(), aPath.end());
		result.push_back(aPath);
		return;
	}
	for (auto it = parent[start].begin(); it != parent[start].end(); it++)
	{
		buildPath(parent, *it, end);
		tmpPath.pop_back();
	}
}

vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
	unordered_set<string> cur;
	unordered_set<string> next;
	unordered_map<string, unordered_set<string>> parent;
	unordered_set<string> unVisited = dict;
	if (unVisited.count(start) > 0)
		unVisited.erase(start);
	cur.insert(start);
	while (cur.count(end) == 0 && unVisited.size() > 0)
	{
		for (auto it = cur.begin(); it != cur.end(); it++)
		{
			for (auto i = 0; i != start.size(); i++)
			{
				string word = *it;
				for (auto j = 'a'; j != 'z' + 1; j++)
				{
					word[i] = j;
					if (unVisited.count(word) > 0)
					{
						next.insert(word);
						parent[word].insert(*it);
					}
						
				}
			}
		}
		if (next.empty())
			break;
		for (auto it = next.begin(); it != next.end(); it++)
			unVisited.erase(*it);
		cur = next;
		next.clear();
	}
	if (cur.count(end) > 0)
		buildPath(parent, end, start);
	return result;
}