#include "hashTableZakr.h"

HashTable::HashTable()
{
	count = 0;
	mem_size = 8;
	array = new Pair[mem_size];
}

HashTable::~HashTable()
{
	delete[] array;
}

void HashTable::add(FruitName fr_name, int fr_count)
{
	int index = -1, i = 0;
	// берем пробы по всем i от 0 до размера массива
	for (; i < mem_size; ++i) {
		index = hash_func(fr_name, i);
		if (array[index].status != enPairStatus::engaged) {
			// найдена пустая ячейка, занимаем ее
			break;
		}
		// все перебрали, нет места
		if (i >= mem_size) return; 

		// кладем в свободную ячейку пару
		array[index] = Pair(fr_name, fr_count);
		count++;
	}
}

int HashTable::hash_func(FruitName fr_name, int offset)
{
	// вычисляем индекс
	int sum = 0, i = 0;
	for (; i < strlen(fr_name); ++i)
		sum += fr_name[i];
	// линейные пробы
	return (sum % mem_size + offset) % mem_size;
}
