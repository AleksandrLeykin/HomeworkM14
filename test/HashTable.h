#pragma once

#include <cstring>

#define NAMELENGTH 10 //Зафиксируем длину имени

typedef char FruitName[NAMELENGTH]; // тип имя фрукта

class HashTable // Хеш-таблица
{
public:
	HashTable();
	~HashTable();

	void add(FruitName fr_name, int fr_count);

private:
	struct ChainNode { // узел в списке
		FruitName fruit_name; // ключ
		int fruit_count; // значение

		ChainNode* next; // указатель на следующий узел в списке
		ChainNode(FruitName _fn, int _fc) 
			: fruit_count(_fc)
		{
			strcpy_s(fruit_name, _fn);
			next = nullptr;
		}
		~ChainNode()
		{
			if (next != nullptr)
				delete next;
		}		
	};
	// хеш-функция для поиска индекса
	int hash_func(FruitName fr_name);

	// массив указателей на списки
	ChainNode** chain_tops;
	// количество выделенной памяти
	int mem_size;
	// количество добавленных пар ключ-значение
	int count;
};