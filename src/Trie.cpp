#include "Trie.h"
#include <iostream>

Trie::TrieNode::~TrieNode()
{
	for (int i = 0; i < childCount; ++i)
	{
		 children[i] = nullptr;
		 delete children[i];
	}	
}

Trie::TrieNode* Trie::getNewNode(void)
{
	// ¬ыдел€ем пам€ть под новый узел (Allocating memory for the new node)
	TrieNode* pNode = new TrieNode;
	// устанавливаем флаг конца слова в false (set the end-of-word flag to false)
	pNode->isEndOfWord = false;
	// инициализируем детей нулевым уазателем (initialize the children with a null pointer)
	for (int i = 0; i < ALPHABET_SIZE; ++i)
	{
		pNode->children[i] = nullptr;
	}
	return pNode;
}

bool Trie::isEmpty()
{
	for (int i = 0; i < ALPHABET_SIZE; ++i)
	{
		if (m_root->children[i])
			return true;
	}
	return false;
}

void Trie::printInner(TrieNode* current)
{
	
}

void Trie::print()
{
	printInner(m_root);
}

void Trie::insert(std::string key)
{
	TrieNode* node = m_root;

	for (int i = 0; i < key.length(); i++)
	{
		// вычисл€ем индекс в алфите через смещение отнситьельно первой буквы
		// calculate the index in the alphabet through the offset relative to the first letter
		int index = key[i] - 'a';
		// если указатель пустрой, т.е. детей с таким префиксом нет  создаем новый узел
		// if the pointer is empty, there are no children with this prefix, create a new node
		if (!node->children[index]) {
			node->children[index] = getNewNode();
			node->childCount++;
		}
		node = node->children[index];		
	}
	// помечаем последний узлел как конец слова (mark the last node as the end of the word)
	node->isEndOfWord = true;
}
