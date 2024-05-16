#pragma once
#include <string>

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
		TrieNode() : isEndOfWord(false), childCount(0) {}
		~TrieNode();
	};

	TrieNode* m_root;
public:
	Trie() { m_root = nullptr; }
	~Trie() { if (!m_root) delete m_root; }

	// Вставляет ключ в дерево, если его нет (Inserts a key into the tree if it does not exist)
	void insert(std::string key);

	void print();
private:
	//Возвращет новый узел с пустыми детьми (Returns a new node with empty children)
	TrieNode* getNewNode(void);	
	// Возвращает true если root имеет лист, иначе false (Returns true if root has a leaf, false otherwise)
	bool isEmpty();

	void printInner(TrieNode* current);
};