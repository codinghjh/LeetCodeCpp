#include <iostream>
#include <map>
#include "Solutions.h"

using namespace std;

RandomListNode *copyRandomList(RandomListNode *head) {
	if (head == nullptr)
		return head;
	map<RandomListNode*, RandomListNode*> copy;
	RandomListNode* newHead = new RandomListNode(head->label);
	copy.insert(pair<RandomListNode*, RandomListNode*>(head, newHead));
	while (head != nullptr)
	{
		if (copy.find(head) == copy.end())
		{
			RandomListNode* newNode = new RandomListNode(head->label);
			copy.insert(pair<RandomListNode*, RandomListNode*>(head, newNode));
		}
		if (head->next != nullptr)
		{
			if (copy.find(head->next) == copy.end())
			{
				RandomListNode* newNext = new RandomListNode(head->next->label);
				copy.find(head)->second->next = newNext;
				copy.insert(pair<RandomListNode*, RandomListNode*>(head->next, newNext));
			}
			else
			{
				copy.find(head)->second->next = copy.find(head->next)->second;
			}
		}
		if (head->random != nullptr)
		{
			if (copy.find(head->random) == copy.end())
			{
				RandomListNode* newR = new RandomListNode(head->random->label);
				copy.find(head)->second->random = newR;
				copy.insert(pair<RandomListNode*, RandomListNode*>(head->random, newR));
			}
			else
			{
				copy.find(head)->second->random = copy.find(head->random)->second;
			}
		}
		head = head->next;
	}
	return newHead;
}