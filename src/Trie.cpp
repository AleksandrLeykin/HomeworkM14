#include "Trie.h"

Trie::~Trie() {
	deleteNode(m_root);
	delete m_root;	
}

void Trie::deleteNode(TrieNode* root) {	
	for (int i = 0; i < ALPHABET_SIZE; ++i) 	
		delete root->children[i];		
}

Trie::TrieNode* Trie::getNewNode(void)
{
	// �������� ������ ��� ����� ���� (Allocating memory for the new node)
	TrieNode* pNode = new TrieNode;
	// ������������� ���� ����� ����� � false (set the end-of-word flag to false)
	pNode->isEndOfWord = false;
	// �������������� ����� ������� ��������� (initialize the children with a null pointer)
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
			return false;
	}
	return true;
}

bool Trie::search(std::string key) {
	TrieNode* node = m_root;
	
	for (int i = 0; i < key.length(); ++i) {
		int index = key[i] - 'a';	
		if (!node->children[index]) {
			return false;
		}
		node = node->children[index];	
	}
	//���������� ���� ��������� ������ �������� ���������� �����
	//return if the last element is the end of a word
	return (node != nullptr && node->isEndOfWord);
}

void Trie::compareWord(std::string& word) {		
	if (search(word)) 
		std::cout << "�� ��������� ����� �����: " << word  << std::endl;	
	else 		
		std::cout << "������ �����: " << word << " ���!" << std::endl;
}


void Trie::insert(std::string key)
{
	TrieNode* node = m_root;

	for (int i = 0; i < key.length(); i++) {
		// ��������� ������ � ������ ����� �������� ������������ ������ �����
		// calculate the index in the alphabet through the offset relative to the first letter
		int index = key[i] - 'a';
		// ���� ��������� �������, �.�. ����� � ����� ��������� ���  ������� ����� ����
		// if the pointer is empty, there are no children with this prefix, create a new node
		if (!node->children[index]) {
			node->children[index] = getNewNode();			
		}		
		node = node->children[index];	
		node->childCount++;
	}
	// �������� ��������� ����� ��� ����� ����� (mark the last node as the end of the word)
	node->isEndOfWord = true;
}

void Trie::print() {
	std::string res = "";
	int index = 0;
	char buf[10];
	printInnet(m_root, buf, index, res);
	std::cout << res << std::endl;
}

void Trie::printInnet(TrieNode* root, char buf[], int index, std::string& res) {
	if (!root)
		return;
	//���� ������� ���� �������� ������ ����� �������� ������ ��������� ������ 
	//� �����,	����� ��������� ����� � ��������� res � ��������� ������.
	if (root->isEndOfWord) {
		buf[index] = '\0';
		res.append(buf);
		res.push_back(' ');
	}
	//�������� �� ���� ��������� ����� ����
	for (int i = 0; i < ALPHABET_SIZE; i++) {
		//���� ���� �� ������, ��������� ��������������� ������ � ����� �
		//  ���������� �������� printInnet ��� ���������� ������ ������
		if (root->children[i] != nullptr) {
			buf[index] = i + 'a';
			printInnet(root->children[i], buf, index + 1, res);			
		}
	}
}
