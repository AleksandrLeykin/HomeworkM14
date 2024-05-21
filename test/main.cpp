#include <iostream>
#include "HashTable.h"

int main()
{
	std::cout << "Hello!" << std::endl;
	//объ€вление хеш таблицы
	HashTable ht;

	ht.add((char*)"apple", 10);
	ht.add((char*)"orange", 15);
	ht.add((char*)"banana", 2);
	ht.add((char*)"lemon", 6);
	ht.add((char*)"pear", 7);
	ht.add((char*)"ciwi", 4);
	ht.add((char*)"mandarin", 9);

	return 0;
}