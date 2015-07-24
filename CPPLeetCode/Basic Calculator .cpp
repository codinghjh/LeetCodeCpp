#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include "Solutions.h"

using namespace std;

int calculate(string s) {
	if (s.size() == 0)
		return 0;

	stack<int> opN;
	stack<char> opD;
	string newString = "";
	for (int i = 0; i != s.size(); i++)
	{
		if (s[i] != ' ')
			newString += s.substr(i, 1);
	}
	string tmp = "";
	return 0;
}

/*
int main()
{
	vector<bool> b;
	for (int i = 0; i != 8; i++)
	{
		b.push_back(false);
	}
	cout << sizeof(false) << endl;
	cout << sizeof(b) << endl;
	cout << sizeof(int *) << endl;
		return 0;
}

*/