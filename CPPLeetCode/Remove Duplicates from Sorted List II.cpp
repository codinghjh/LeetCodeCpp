#include <iostream>
#include <map>
#include "Solutions.h"
using namespace std;

ListNode *deleteDuplicates(ListNode *head) {
	if(head==NULL)
		return NULL;
	if(head->next==NULL)
		return head;
	map<int,bool> key;
	map<int,bool>::iterator it;
	ListNode *cur=head;
	int cout=0;
	while(cur!=NULL)
	{
		it=key.find(cur->val);
		if(it==key.end())
			key.insert(pair<int,bool>(cur->val,true));
		else
			it->second=false;
		cur=cur->next;
	}
	
	ListNode* tmp=new ListNode(0);
	tmp->next=head;
	cur=tmp;
	ListNode *p=head;
	while(p!=NULL)
	{
		if(key.find(p->val)->second==true)
		{
			cur=cur->next;
			cur->val=p->val;
		}
		p=p->next;
	}
	cur->next=NULL;
	return tmp->next;
}