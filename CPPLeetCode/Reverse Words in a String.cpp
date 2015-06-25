#include <iostream>
#include <stack>
#include <string>
#include "Solutions.h"

using namespace std;

void reverseWords(string &s) {
	stack<string> tmp;
	s = s + " ";
	int start = 0, i = 0;
	for (i = 0; i != s.length(); i++)
	{
		if (s[i] == ' ')
		{
			if (start == i)
				start++;
			else
			{
				tmp.push(s.substr(start, i - start));
				start = i + 1;
			}
		}
	}
	s.clear();
	while (!tmp.empty())
	{
		s = s + tmp.top()+" ";
		tmp.pop();
	}
	s = s.substr(0, s.length() - 1);
}