#include <iostream>
#include <unordered_map>
#include "Solutions.h"

using namespace std;

class TrieNode {
private:
public:
	// Initialize your data structure here.
	unordered_map<char, TrieNode*> childrens;
	bool isWord = false;
	char tag;
	TrieNode() {

	}
	TrieNode(char c)
	{
		tag = c;
	}
	int c;
};

class Trie {
public:
	Trie() {
		root = new TrieNode();
	}

	// Inserts a word into the trie.
	void insert(string word) {
		if (word.size() == 0)
			return;
		TrieNode* cur = root;
		auto i = 0;
		while (cur != nullptr&&i<word.size())
		{
			auto it = cur->childrens.find(word[i]);
			if (it != cur->childrens.end())
			{
				cur = cur->childrens[word[i]];
				i++;
			}
			else
			{
				TrieNode* newTrieNode = new TrieNode(word[i]);
				cur->childrens[word[i]] = newTrieNode;
				i++;
				cur = newTrieNode;
			}
			if (i == word.size())
				cur->isWord = true;
		}
	}

	// Returns if the word is in the trie.
	bool search(string word) {
		TrieNode* cur= root;
		for (auto i = 0; i != word.size(); i++)
		{
			auto it = cur->childrens.find(word[i]);
			if (it == cur->childrens.end())
				return false;
			cur = cur->childrens[word[i]];
		}
		if (cur->isWord==true)
			return true;
		return false;
	}

	// Returns if there is any word in the trie
	// that starts with the given prefix.
	bool startsWith(string prefix) {
		TrieNode* cur = root;
		for (auto i = 0; i != prefix.size(); i++)
		{
			auto it = cur->childrens.find(prefix[i]);
			if (it == cur->childrens.end())
				return false;
			cur = cur->childrens[prefix[i]];
		}
		return true;
	}

private:
	TrieNode* root;
};

int main()
{
	Trie t;
	t.insert("abc");
	cout<<boolalpha<<t.search("abc");
	cout << boolalpha << t.search("ab");
	t.insert("ab");
	cout << boolalpha << t.search("ab");
	t.insert("ab");
	cout << boolalpha << t.search("ab");
	return 0;
}