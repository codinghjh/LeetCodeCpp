#include <iostream>
#include "Solutions.h"

using namespace std;

ListNode* reverseR(ListNode* head)
{
	if (head == nullptr)
		return nullptr;
	if (head->next != nullptr)
	{
		ListNode* newL = reverseR(head->next);
		head->next = nullptr;
		ListNode* cur = newL;
		while (cur->next != nullptr)
		{
			cur = cur->next;
		}
		cur->next = head;
		return newL;
	}
	else
		return head;
}

ListNode* reverseList(ListNode* head) {
	/*iteratively
	if (head == nullptr)
		return nullptr;
	ListNode* newHead = new ListNode(0);
	ListNode* cur = head->next;
	newHead->next = head;
	head = head->next;
	newHead->next->next = nullptr;
	while (head != nullptr)
	{
		cur = head->next;
		head->next = newHead->next;
		newHead->next = head;
		head = cur;
	}
	return newHead->next;
	*/
	/*recursively*/
	if (head == nullptr)
		return nullptr;
	return reverseR(head);
}