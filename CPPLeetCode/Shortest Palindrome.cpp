#include <iostream>
#include <string>
#include <algorithm>
#include "Solutions.h"

string shortestPalindrome(string s) {
	if (s.length() <= 1)
		return s;
	string re = s;
	reverse(re.begin(), re.end());
	string t = s + "#" + re+"#";
	vector<int> p(t.size(), 0);
	p[0] = -1;
	int k = -1, j = 0;
	while (j < t.size()-1)
	{
		if (k == -1 || t[j] ==t[k])
		{
			k++;
			j++;
			p[j] = k;
		}
		else
			k = p[k];
	}
	return re.substr(0, s.length() - p[t.size() - 1])+s;
}

int main()
{
	string s = "aacecaaa";
	cout << shortestPalindrome(s) << endl;
	return 0;
}