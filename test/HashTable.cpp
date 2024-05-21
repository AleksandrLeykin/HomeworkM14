#include "HashTable.h"

HashTable::HashTable() {
	// ��������� ������, �������������
	mem_size = 8;
	chain_tops = new ChainNode* [mem_size];
	for (int i = 0; i < mem_size; ++i) {
		chain_tops[i] = nullptr;
	}
	count = 0;
}

HashTable::~HashTable() {
	// ��������� �� �����
	for (int i = 0; i < mem_size; ++i) {
		if (chain_tops[i] != nullptr)
			delete chain_tops[i];		
	}
	delete[] chain_tops;
}

void HashTable::add(FruitName fr_name, int fr_count) {
	int index = hash_func(fr_name);
	if (chain_tops[index] != nullptr) {
		// ���� ������ c ����� �������� ��� ����, �� ������� ����� ���� � ������ ��� ������� 
		ChainNode* newNode = new ChainNode(fr_name, fr_count);
		newNode->next = chain_tops[index];
		chain_tops[index] = newNode;
	}
	else {
		// ���� ��� ������, ������ ��� ������� ����
		chain_tops[index] = new ChainNode(fr_name, fr_count);
	}
	count++;
}

int HashTable::hash_func(FruitName fr_name)
{
	// ��������� ������
	int sum = 0, i = 0;
	for (; i < strlen(fr_name); ++i) {
		sum += fr_name[i];
	}
	// �������� ����� ����� ����� 0 � memsize
	return sum % mem_size;
}
