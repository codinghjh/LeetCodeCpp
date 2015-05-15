#include <iostream>
#include "Solutions.h"

using namespace std;

ListNode* reverseBetween(ListNode* head, int m, int n) {
	ListNode* pre = new ListNode(0);
	pre->next = head;
	ListNode* cur = pre;
	for (int i = 1; i != m; i++)
		cur = cur->next;
	ListNode* p = cur->next;
	ListNode* prep = cur;
	ListNode* q = cur->next;
	for (int i = m; i != n+1; i++)
	{
		if (i == m)
		{
			prep = p;
			p = p->next;
		}
		else
		{
			q = p->next;
			prep->next = p->next;
			p->next = cur->next;
			cur->next = p;
			p = q;
		}
	}
	return pre->next;
}