#include <iostream>
#include "Solutions.h"

using namespace std;

ListNode* insertionSortList(ListNode* head) {
	if (head == nullptr || head->next == nullptr)
		return head;
	ListNode* sorted = new ListNode(0);
	sorted->next = head;
	head = head->next;
	sorted->next->next = nullptr;
	while (head != nullptr)
	{
		ListNode* curHead = head;
		head = head->next;
		curHead->next = nullptr;
		auto i = sorted;
		for (i = sorted; i->next!=nullptr&&i->next->val < curHead->val; i = i->next);
		if (i->next == nullptr)
		{
			i->next = curHead;
			continue;
		}
		curHead->next = i->next;
		i->next = curHead;
	}
	return sorted->next;
}