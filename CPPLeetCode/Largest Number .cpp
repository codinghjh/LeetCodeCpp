#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "Solutions.h"

using namespace std;

bool compareString(string s1, string s2)//s1>s2?
{
	if (s1 == s2)
		return false;
	int len1 = s1.length();
	int len2 = s2.length();
	if (len1 == len2)
	{
		for (auto i = 0; i != len1; i++)
		{
			if (s1[i] == s2[i])
				continue;
			else
			{
				return s1[i] > s2[i] ? true : false;
			}
		}
	}
	if (len1 > len2)
		return !compareString(s2, s1);
	if (s2.substr(0, len1) == s1)
	{
		s2 = s2.substr(len1, s2.length() - len1);
		return compareString(s1, s2);
	}
	for (auto i = 0; i != len1; i++)
	{
		if (s1[i] == s2[i])
			continue;
		else
		{
			return s1[i] > s2[i] ? true : false;
		}
	}

}

string largestNumber(vector<int>& nums) {
	if (nums.size() <= 0)
		return "0";
	if (nums.size() == 1)
		return to_string(nums[0]);
	map<int, vector<string>> map;
	for (auto i = 0; i != nums.size(); i++)
	{
		int n = nums[i];
		while (n >= 10)
			n = n / 10;
		if (map.find(n) == map.end())
		{
			vector<string> newV;
			newV.push_back(to_string(nums[i]));
			map[n] = newV;
		}
		else
		{
			vector<string> v = map[n];
			v.push_back(to_string(nums[i]));
			for (auto j = v.size() - 1; j > 0; j--)
			{
				if (compareString(v[j], v[j - 1]))
				{
					string tmp = v[j - 1];
					v[j - 1] = v[j];
					v[j] = tmp;
				}
			}
			map[n] = v;
		}
	}
	string s = "";
	for (auto i = 9; i >= 0; i--)
	{
		if (map.find(i) != map.end())
		{
			vector<string> vT = map[i];
			for (auto j = 0; j != vT.size(); j++)
			{
				s += vT[j];
			}
		}
	}
	while (s.size() > 1)
	{
		if (s[0] == '0')
			s = s.substr(1, s.size() - 1);
		else
			break;
	}
	return s;
}
