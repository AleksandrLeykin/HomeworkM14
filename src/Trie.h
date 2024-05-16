#pragma once
#include <string>

const int ALPHABET_SIZE = 26;

class Trie
{	
	struct TrieNode
	{
		//��������� ����� children's storage
		TrieNode* children[ALPHABET_SIZE]{};
		//���� ����� ����� end of word flag
		bool isEndOfWord;
		int childCount;
		TrieNode() : isEndOfWord(false), childCount(0) {}
		~TrieNode();
	};

	TrieNode* m_root;
public:
	Trie() { m_root = nullptr; }
	~Trie() { if (!m_root) delete m_root; }

	// ��������� ���� � ������, ���� ��� ��� (Inserts a key into the tree if it does not exist)
	void insert(std::string key);

	void print();
private:
	//��������� ����� ���� � ������� ������ (Returns a new node with empty children)
	TrieNode* getNewNode(void);	
	// ���������� true ���� root ����� ����, ����� false (Returns true if root has a leaf, false otherwise)
	bool isEmpty();

	void printInner(TrieNode* current);
};