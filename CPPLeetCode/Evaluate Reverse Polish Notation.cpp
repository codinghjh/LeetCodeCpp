#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <sstream>
#include "Solutions.h"

using namespace std;

int evalRPN(vector<string>& tokens) {
	stack<int> opn;
	int right,left;
	
	for (auto i = 0; i != tokens.size(); i++)
	{
		if (tokens[i] == "+")
		{
			if (opn.size() > 1)
			{
				right = opn.top();
				opn.pop();
				left = opn.top();
				opn.pop();
				opn.push(right + left);
			}
		}
		else if (tokens[i] == "-")
		{
			if (opn.size() > 1)
			{
				right = opn.top();
				opn.pop();
				left = opn.top();
				opn.pop();
				opn.push(left-right);
			}
			else
				return -1;
		}
		else if (tokens[i] == "*")
		{
			if (opn.size() > 1)
			{
				right = opn.top();
				opn.pop();
				left = opn.top();
				opn.pop();
				opn.push(right * left);
			}
			else
				return -1;
		}
		else if (tokens[i] == "/")
		{
			if (opn.size() > 1)
			{
				right = opn.top();
				opn.pop();
				left = opn.top();
				opn.pop();
				if (right != 0)
					opn.push(left/right);
				else
					return -1;
			}
			else
				return -1;
		}
		else
		{
			stringstream  ss;
			int num = 0;
			ss << tokens[i];
			ss >> num;
			opn.push(num);
		}
	}
	if (opn.size() != 1)
		return -1;
	return opn.top();
}