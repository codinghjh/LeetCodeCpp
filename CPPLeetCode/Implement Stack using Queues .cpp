#include <iostream>
#include <queue>

using namespace std;


class Stack {
private:
	queue<int> v[2];
	int tag = 0;
public:
	// Push element x onto stack.
	void push(int x) {
		v[tag].push(x);
	}

	// Removes the element on top of the stack.
	void pop() {
		while (v[tag].size() > 1)
		{
			v[1 - tag].push(v[tag].front());
			v[tag].pop();
		}
		v[tag].pop();
		tag = 1 - tag;
	}

	// Get the top element.
	int top() {
		
		return v[tag].back();
	}

	// Return whether the stack is empty.
	bool empty() {
		return v[tag].empty();
	}
};

