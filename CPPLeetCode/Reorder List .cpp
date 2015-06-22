#include <iostream>
#include <stack>
#include "Solutions.h"

using namespace  std;

void reorderList(ListNode* head) {
	if (head == nullptr)
		return;
	ListNode *cur = head;
	int length = 0;
	while (cur != nullptr)
	{
		length++;
		cur = cur->next;
	}
	cur = head;
	for (auto i = 0; i < length/2-1; i++)
	{
		cur = cur->next;
	}
	if (length % 2 == 1)
		cur = cur->next;
	if (cur == nullptr)
		return;
	ListNode *tag = cur->next;
	cur->next = nullptr;
	ListNode *p = tag->next;
	tag->next = nullptr;
	ListNode *q = p;
	while (p != nullptr)
	{
		q = p->next;
		p->next = tag;
		tag = p;
		p = q;
	}
	cur = head;
	while (tag != nullptr&&cur != nullptr)
	{
		p = cur->next;
		q = tag->next;
		cur->next = tag;
		tag->next = p;
		cur = tag->next;
		tag = q;
	}
}