#include <iostream>
#include "Solutions.h"

using namespace std;

ListNode* removeElements(ListNode* head, int val) {
	if (head == nullptr)
		return nullptr;
	ListNode* newHead = new ListNode(0);
	ListNode* cur = head, *newCur = newHead;
	while (cur != nullptr)
	{
		if (cur->val != val)
		{
			newCur->next = cur;
			newCur = newCur->next;
			cur = cur->next;
			newCur->next = nullptr;
		}
		else
			cur = cur->next;
	}
	return  newHead->next;
}