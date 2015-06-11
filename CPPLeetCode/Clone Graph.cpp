#include <iostream>
#include <map>
#include <queue>
#include "Solutions.h"

using namespace std;

UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
	if (node == nullptr)
		return nullptr;
	queue<UndirectedGraphNode*> qu;
	map<UndirectedGraphNode*, UndirectedGraphNode*> ma;
	UndirectedGraphNode* head = new UndirectedGraphNode(node->label);
	ma.insert(pair<UndirectedGraphNode*, UndirectedGraphNode*>(node, head));
	qu.push(node);
	while (!qu.empty())
	{
		UndirectedGraphNode* cur = qu.front();
		qu.pop();
		for (UndirectedGraphNode* tmp : cur->neighbors)
		{
			if (ma.find(tmp) == ma.end())
			{
				UndirectedGraphNode* newNode = new UndirectedGraphNode(tmp->label);
				ma.find(cur)->second->neighbors.push_back(newNode);
				ma.insert(pair<UndirectedGraphNode*, UndirectedGraphNode*>(tmp, newNode));
				qu.push(tmp);
			}
			else
				ma.find(cur)->second->neighbors.push_back(ma.find(tmp)->second);
		}
	}
	return head;
}