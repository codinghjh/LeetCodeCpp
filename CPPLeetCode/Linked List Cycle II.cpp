#include <iostream>
#include "Solutions.h"

using namespace std;

ListNode *detectCycle(ListNode *head) {
	bool isFirst = true,hasCycle=false;
	ListNode *fast = head;
	ListNode *slow = head;
	while (fast != nullptr&&slow != nullptr)
	{
		if (isFirst)
		{
			isFirst = false;
			slow = slow->next;
			fast = fast->next;
			if (fast == nullptr)
				return nullptr;
			else
				fast = fast->next;
		}
		else
		{
			if (fast == slow)
			{
				hasCycle = true;
				break;
			}
			else
			{
				slow = slow->next;
				fast = fast->next;
				if (fast == nullptr)
					return nullptr;
				else
					fast = fast->next;
			}
		}
	}
	if (hasCycle)
	{
		fast = head;
		while (fast != slow)
		{
			fast = fast->next;
			slow = slow->next;
		}
		return fast;
	}
	return nullptr;

}