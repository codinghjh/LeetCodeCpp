#include <iostream>
#include <vector>
#include "Solutions.h"

using namespace std;

int numDecodings(string s) {
	if (s.length() == 0||s[0]=='0')
		return 0;
	if (s.length() == 1)
		return 1;
	if (s.length() == 2)
	{
		if (s[1] == '0')
		{
			if ((s[0] == '1' || s[0] == '2'))
				return 1;
			else
				return 0;
		}
		else if (s[0] == '1' || s[0] == '2'&&s[1] > '0'&&s[1] <= '6')
			return 2;
		else
			return 1;	
	}
	int *p = new int[s.length()];
	if (s[s.length() - 1] != '0')
		p[s.length() - 1] = 1;
	else
		p[s.length() - 1] = 0;
	if (s[s.length()-1] == '0')
	{
		if ((s[s.length() - 2] == '1' || s[s.length() - 2] == '2'))
			p[s.length()-2]=1;
		else
			return 0;
	}
	else if (s[s.length()-2] == '1' || s[s.length()-2] == '2'&&s[s.length()-1] > '0'&&s[s.length()-1] <= '6')
		p[s.length()-2]=2;
	else
		p[s.length() - 2] = 1;
	for (int i = s.length() - 3; i >= 0; i--)
	{
		if (s[i+1] == '0')
		{
			if (s[i] == '1' || s[i] == '2')
				p[i] = p[i+1];
			else
				return 0;
		}
		else if (s[i] == '1' || s[i] == '2'&&s[i+1] > '0'&&s[i+1] <= '6')
			p[i] = p[i+1]+p[i+2];
		else
			p[i] = p[i+1];
	}
	return p[0];
}