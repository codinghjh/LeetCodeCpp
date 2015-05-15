#include <iostream>
#include <queue>
#include "Solutions.h"

using namespace std;

ListNode* partition(ListNode* head, int x) {
	if (head == NULL)
		return head;
	ListNode* cur = head;
	queue<int> less,other;
	while (cur != NULL)
	{
		if (cur->val < x)
			less.push(cur->val);
		else
			other.push(cur->val);
		cur = cur->next;
		
	}
	cur = head;
	while (cur != NULL)
	{
		if (!less.empty())
		{
			cur->val = less.front();
			less.pop();
		}
		else
		{
			cur->val = other.front();
			other.pop();
		}
		cur = cur->next;
	}
	return head;

}