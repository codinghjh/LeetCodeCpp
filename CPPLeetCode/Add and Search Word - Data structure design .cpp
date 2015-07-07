#include <iostream>
#include <vector>
#include <unordered_map>
#include "Solutions.h"

using namespace std;

class WordDictionary {
public:
	struct wordNode
	{
		char c;
		bool isEnd = false;
		unordered_map<char, wordNode*> childrens;
	};
	wordNode* root;
	WordDictionary()
	{
		root = new wordNode();
	}
	// Adds a word into the data structure.
	void addWord(string word) {
		wordNode* cur = root;
		for (auto i=0; i != word.size(); i++)
		{
			auto it = cur->childrens.find(word[i]);
			if (it != cur->childrens.end())
			{
				cur = cur->childrens[word[i]];
			}
			else
			{
				wordNode* newWordNode=new wordNode;
				newWordNode->c = word[i];
				cur->childrens[word[i]] = newWordNode;
				cur = newWordNode;
			}
		}
		cur->isEnd = true;
	}

	// Returns if the word is in the data structure. A word could
	// contain the dot character '.' to represent any one letter.
	bool search(string word) {
		wordNode* cur = root;
		for (auto i = 0; i != word.size(); i++)
		{
			if (word[i] == '.')
			{
				bool result = false;
				for (auto itt = cur->childrens.begin(); itt != cur->childrens.end(); itt++)
				{

					if (i == word.size() - 1)
					{
						if (itt->second->isEnd == true)
							return true;
					}
					result = result || searchAll(itt->second, word.substr(i + 1, word.size() - i - 1));
					if (result == true)
						return true;
				}
				return false;
			}
			auto it = cur->childrens.find(word[i]);
			if (it != cur->childrens.end())
			{
				if (i == word.size() - 1)
				{
					if (cur->childrens[word[i]]->isEnd == true)
						return true;
					else
						return false;
				}
				cur = cur->childrens[word[i]];
			}
			else
				return false;
		}
		return false;
	}
	bool searchAll(wordNode* ro, string word)
	{
		wordNode* cur = ro;
		for (auto i = 0; i != word.size(); i++)
		{
			if (word[i] == '.')
			{
				bool result = false;
				for (auto itt = cur->childrens.begin(); itt != cur->childrens.end(); itt++)
				{
					if (i == word.size() - 1)
					{
						if (itt->second->isEnd == true)
							return true;
					}
					result = result || searchAll(itt->second, word.substr(i + 1, word.size() - i - 1));
					if (result == true)
						return true;
				}
				return false;
			}
			auto it = cur->childrens.find(word[i]);
			if (it != cur->childrens.end())
			{
				if (i == word.size() - 1)
				{
					if (cur->childrens[word[i]]->isEnd == true)
						return true;
					else
						return false;
				}
				cur = cur->childrens[word[i]];
			}
			else
				return false;
		}
		return false;
	}
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");

/*
int main()
{
	WordDictionary wordDictionary;
	wordDictionary.addWord("bad");
	wordDictionary.addWord("dad");
	wordDictionary.addWord("mad");
	cout<<boolalpha<<wordDictionary.search("pad");
	cout << boolalpha << wordDictionary.search("bad");
	cout << boolalpha << wordDictionary.search(".ad");
	cout << boolalpha << wordDictionary.search("b..");
	wordDictionary.addWord("a");
	cout<<boolalpha<<wordDictionary.search(".");
	return 0;
}
*/