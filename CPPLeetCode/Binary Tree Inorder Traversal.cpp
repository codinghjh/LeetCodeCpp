#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include "Solutions.h"
 //.................
using namespace std;

vector<int> inorderTraversal(TreeNode* root) {

	vector<int> result;
	if (root == NULL)
		return result;
	stack<TreeNode*> p;
	set<TreeNode*> visit;
	TreeNode* cur = root;
	p.push(cur);
	while (!p.empty())
	{
		while (p.top()->left != NULL)
		{
			if (visit.find((p.top()->left)) == visit.end())
			{
				visit.insert((p.top()->left));
				p.push(p.top()->left);
			}
			else
				break;
			
		}
		TreeNode* tmp = p.top();
		result.push_back(tmp->val);
		p.pop();
		if (tmp->right != NULL)
		{
			p.push(tmp->right);
		}
	}
	return result;
}