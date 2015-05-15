#include <iostream>
#include <stack>
#include <set>
#include <algorithm>
#include "Solutions.h"

using namespace std;

void recoverTree(TreeNode* root) {
	stack<TreeNode*> visit;
	set<TreeNode*> isVisit;
	stack<TreeNode*> key;
	vector<int> val;
	visit.push(root);
	while (!visit.empty())
	{
		while (visit.top()->left != NULL)
		{
			if (isVisit.find(visit.top()->left) != isVisit.end())
				break;
			isVisit.insert(visit.top()->left);
			visit.push(visit.top()->left);
		}
		TreeNode* t = visit.top();
		key.push(t);
		val.push_back(t->val);
		visit.pop();
		if (t->right != NULL)
		{
			visit.push(t->right);
		}
	}
	sort(val.begin(), val.end());
	vector<int> tmp;
	for (int i = val.size() - 1; i >= 0; i--)
		tmp.push_back(val[i]);
	int i = 0;
	while (!key.empty())
	{
		key.top()->val = tmp[i++];
		key.pop();
	}

}