#include <iostream>
#include "Solutions.h"

using namespace std;

ListNode* sortList(ListNode* head) {
	if (head == nullptr||head->next==nullptr)
		return head;
	ListNode* cur = head;
	int length = 0;
	while (cur != nullptr)
	{
		cur = cur->next;
		length++;
	}
	cur = head;
	ListNode* p = head;
	for (auto i = 0; i != length / 2; i++)
		cur = cur->next;
	for (auto i = 0; i != length / 2 - 1; i++)
		p = p->next;
	p->next = nullptr;
	ListNode *front = sortList(head);
	ListNode *tag = sortList(cur);
	ListNode *newHead = new ListNode(0);
	cur = newHead;
	while (front != nullptr&&tag != nullptr)
	{
		if (front->val < tag->val)
		{
			cur->next = front;
			front = front->next;
		}
		else
		{
			cur->next = tag;
			tag = tag->next;
		}
		cur = cur->next;;
	}
	if (tag != nullptr)
		cur->next = tag;
	if (front != nullptr)
		cur->next = front;
	return newHead->next;
}