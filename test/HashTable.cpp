#include "HashTable.h"

HashTable::HashTable() {
	// выделение памяти, инициализация
	mem_size = 8;
	chain_tops = new ChainNode* [mem_size];
	for (int i = 0; i < mem_size; ++i) {
		chain_tops[i] = nullptr;
	}
	count = 0;
}

HashTable::~HashTable() {
	// прибираем за собой
	for (int i = 0; i < mem_size; ++i) {
		if (chain_tops[i] != nullptr)
			delete chain_tops[i];		
	}
	delete[] chain_tops;
}

void HashTable::add(FruitName fr_name, int fr_count) {
	int index = hash_func(fr_name);
	if (chain_tops[index] != nullptr) {
		// если список c таким индексом уже есть, то создаем новый узел и делаем его верхним 
		ChainNode* newNode = new ChainNode(fr_name, fr_count);
		newNode->next = chain_tops[index];
		chain_tops[index] = newNode;
	}
	else {
		// если нет списка, задаем его верхний узел
		chain_tops[index] = new ChainNode(fr_name, fr_count);
	}
	count++;
}

int HashTable::hash_func(FruitName fr_name)
{
	// вычисляем индекс
	int sum = 0, i = 0;
	for (; i < strlen(fr_name); ++i) {
		sum += fr_name[i];
	}
	// значение точно будет между 0 и memsize
	return sum % mem_size;
}
