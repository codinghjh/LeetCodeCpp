#include <iostream>
#include "Solutions.h"

using namespace std;

bool hasCycle(ListNode *head) {
	bool isFirst = true;
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
				return false;
			else
				fast = fast->next;
		}
		else
		{
			if (fast == slow)
				return true;
			else
			{
				slow = slow->next;
				fast = fast->next;
				if (fast == nullptr)
					return false;
				else
					fast = fast->next;
			}
		}
	}
	return false;
}