#pragma once
#include <string>
#include <iostream>

const int ALPHABET_SIZE = 26;

class Trie
{	
	struct TrieNode
	{
		//хранилище детей children's storage
		TrieNode* children[ALPHABET_SIZE]{};
		//флаг конца слова end of word flag
		bool isEndOfWord;
		int childCount;	
		TrieNode() {
			isEndOfWord = false;
			childCount = 0;
			for (int i = 0; i < ALPHABET_SIZE; ++i)
				children[i] = nullptr;
		}
		~TrieNode() {
			for (int i = 0; i < ALPHABET_SIZE; ++i)
				/*if (children[i] != nullptr)
					delete children[i];*/
				children[i] = nullptr;
			//delete[] children;
		}
	};

	TrieNode* m_root;
public:	
	Trie() { m_root = getNewNode(); }
	~Trie();

	// Вставляет ключ в дерево, если его нет (Inserts a key into the tree if it does not exist)
	void insert(std::string key);
	TrieNode* getNode() { return m_root; }

	void print();
	void printInnet(TrieNode* root, char buf[], int ind, std::string& res);
	void compareWord(std::string& word);

private:
	void deleteNode(TrieNode* root);
	//Возвращет новый узел с пустыми детьми (Returns a new node with empty children)
	TrieNode* getNewNode(void);	
	// Возвращает true если root не имеет лист, иначе false (Returns true if root has a leaf, false otherwise)
	bool isEmpty();
	bool search(std::string key);
	
};