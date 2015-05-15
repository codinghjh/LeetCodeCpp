#include <iostream>
#include <stack>
#include <set>
#include "Solutions.h"

using namespace std;

bool isValidBST(TreeNode* root) {
	if (root == NULL)
		return true;
	stack<TreeNode*> visit;
	set<TreeNode*> isVisit;
	stack<int> key;

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
		key.push(t->val);
		visit.pop();
		if (t->right != NULL)
		{
			visit.push(t->right);
		}
	}
	int pre = key.top();
	key.pop();
	while (!key.empty())
	{
		if (pre <= key.top())
			return false;
		pre = key.top();
		key.pop();
	}
	return true;

}