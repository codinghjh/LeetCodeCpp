#include <iostream>
#include <map>
#include <list>
#include "Solutions.h"

using namespace std;

struct Node
{
	int key;
	int value;
};

class LRUCache{
private:
	int maxSize;
	list<Node> cacheList;
	map < int, list<Node>::iterator > cache;
public:
	LRUCache(int capacity) {
		maxSize = capacity;	
	}
	int get(int key) {
		if (cache.size() == 0 || cache.find(key) == cache.end())
			return -1;
		auto it = cache[key];
		Node newNod;
		newNod.key = it->key;
		newNod.value = it->value;
		cacheList.erase(it);
		cacheList.push_front(newNod);
		cache[key] = cacheList.begin();
		return cacheList.begin()->value;
	}

	void set(int key, int value) {
		auto it = cache.find(key);
		if (it == cache.end())
		{
			if (cacheList.size() == maxSize)
			{
				auto deletIt = cacheList.back();
				cache.erase(deletIt.key);
				cacheList.pop_back();
			}
			Node newNode;
			newNode.key = key;
			newNode.value = value;
			cacheList.push_front(newNode);
			cache[key] = cacheList.begin();
		}
		else
		{
			Node newNode;
			newNode.key = key;
			newNode.value = value;
			auto listIt = cache[key];
			cacheList.erase(listIt);
			cacheList.push_front(newNode);
			cache[key] = cacheList.begin();
		}
	}
};

int main()
{
	LRUCache *test = new  LRUCache(2);
	test->set(2, 1);
	test->set(2, 2);
	cout << test->get(2) << endl;
	test->set(1, 1);
	test->set(4, 1);
	cout << test->get(2) << endl;
	return 0;
}