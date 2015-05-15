#include <iostream>
#include <vector>
#include "Solutions.h"

using namespace std;

vector<string> address(string s, int n)
{
	vector<string> result;
	if (n == 1)
	{
		if (s.length()!=0&&s.length() <= 3)
		{
			string tmp = s;
			int key = 0;
			while (tmp.length() != 0)
			{
				key = key*10 + (tmp[0] - '0');
				tmp = tmp.substr(1);
			}
			if ((s.length() > 1) && s[0] == '0')
				return result;
			if (key <= 255)
			{
				result.push_back(s);
			}
		}
		return result;
	}
	for (int i = 0; i != 3&&(s.length()!=0)&&(i<s.length()); i++)
	{
		if (i == 2)
		{
			string t = s.substr(0, i + 1);
			int key = 0;
			while (t.length() != 0)
			{
				key = key * 10 + (t[0] - '0');
				t = t.substr(1);
			}
			t = s.substr(0, i + 1);
			if (key > 255||t[0]=='0')
				continue;
		}
		if (i == 1 && s[0] == '0')
			continue;
		vector<string> tmp = address(s.substr(i + 1), n - 1);
		if (tmp.size() > 0)
		{
			for (int j = 0; j != tmp.size(); j++)
			{
				result.push_back(s.substr(0, i + 1) + "." + tmp[j]);
			}
		}
		
	}
	return result;
}

vector<string> restoreIpAddresses(string s) {
	vector<string> result;
	return address(s, 4);
}

