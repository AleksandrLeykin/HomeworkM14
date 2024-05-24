#pragma once

#include <string.h>

#define NAMELENGTH 10  // Зафиксируем длину имени

// тип имя фрукта
typedef char FruitName[NAMELENGTH];

class HashTable {
public:
	HashTable();
	~HashTable();

	void add(FruitName fr_name, int fr_count);

private:
	enum enPairStatus {
		free, // свободен
		engaged, //занят
		deleted //удален
	};

	// пара ключ-значение
	struct Pair {
		// конструктор по умолчанию
		Pair() : fruit_name("")
			   , fruit_count(-1)
			   , status(enPairStatus::free) {}
		// конструктор копирования
		Pair(FruitName fr_name, int fr_count)
			: fruit_count(fr_count)
			, status(enPairStatus::engaged)
		{
			strcpy(fruit_name, fr_name);
		}
		//  оператор присваивания
		Pair& operator=(const Pair& other) {
			fruit_count = other.fruit_count;
			strcpy(fruit_name, other.fruit_name);
			status = other.status;
			return *this;
		}
	
		// имя фрукта (ключ)
		FruitName fruit_name; 
		// количество фрукта (значение)
		int fruit_count; 
		// состояние ячейки
		enPairStatus status; 
	};

	int hash_func(FruitName fr_name, int offset);

	Pair* array;
	int mem_size;
	int count;

};
