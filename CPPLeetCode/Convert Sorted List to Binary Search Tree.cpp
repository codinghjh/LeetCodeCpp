#include <iostream>
#include "Solutions.h"

using namespace std;

TreeNode* sortedListToBST(ListNode* head) {
	if (head == NULL)
		return NULL;
	ListNode* cur = head;
	int len = 0;
	while (cur != NULL)
	{
		len++;
		cur = cur->next;
	}
	if (len == 1)
	{
		TreeNode* root = new TreeNode(head->val);
		return root;
	}
	int mid = len / 2;
	cur = head;
	for (int i = 1; i != mid; i++)
	{
		cur = cur->next;
	}
	ListNode* pre = cur;
	cur = cur->next;
	TreeNode *root = new TreeNode(cur->val);
	pre->next = NULL;
	root->left = sortedListToBST(head);
	root->right = sortedListToBST(cur->next);
	return root;
}