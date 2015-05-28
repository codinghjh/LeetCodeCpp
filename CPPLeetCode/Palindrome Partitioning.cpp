#include <iostream>
#include <vector>

using namespace std;

bool isPalindrome(string s)
{
	bool result = true;
	for (int i = 0, j = s.length() - 1; i != s.length() && j >= 0; i++, j--)
		if (s[i] != s[j])
		{
			result = false;
			break;
		}
			
	return result;
}

vector<vector<string>> partition(string s) {
	vector<vector<string>> result;
	if (s.length() == 0)
		return result;
	if (s.length() == 1)
	{
		vector<string> v;
		v.push_back(s);
		result.push_back(v);
		return result;
	}
	for (int i = 0; i != s.length(); i++)
	{
		if (isPalindrome(s.substr(0, i + 1)))
		{
			vector<string> v;
			if (i == s.length() - 1)
			{
				vector<string> v2;
				v2.push_back(s);
				result.push_back(v2);
			}
			else
			{
				vector<vector<string>> tmp = partition(s.substr(i + 1, s.length()));
				if (tmp.size() != 0)
				{
					for (int j = 0; j != tmp.size(); j++)
					{
						tmp[j].insert(tmp[j].begin(), s.substr(0, i + 1));
						result.push_back(tmp[j]);
					}
						
				}
			}	
		}
	}
	return result;
}