#include <iostream>
#include <vector>
#include "Solutions.h"

using namespace std;

vector<TreeNode*>  searchTrees(int start, int end)
{
	vector<TreeNode*> result;
	if (start > end)
	{
		result.push_back(NULL);
		return result;
	}
	for (int i = start; i != end + 1; i++)
	{
		vector<TreeNode*> leftChild;
		vector<TreeNode*> rightChild;
		leftChild = searchTrees(start, i - 1);
		rightChild = searchTrees(i + 1, end);
		for (int j = 0; j != leftChild.size(); j++)
			for (int k = 0; k != rightChild.size(); k++)
			{
				TreeNode* t = new TreeNode(i);
				t->left = leftChild[j];
				t->right = rightChild[k];
				result.push_back(t);
			}
	}
	return result;
}

vector<TreeNode*> generateTrees(int n) {
	return searchTrees(1, n);
}