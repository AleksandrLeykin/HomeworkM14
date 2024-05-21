#pragma once

#include <cstring>

#define NAMELENGTH 10 //����������� ����� �����

typedef char FruitName[NAMELENGTH]; // ��� ��� ������

class HashTable // ���-�������
{
public:
	HashTable();
	~HashTable();

	void add(FruitName fr_name, int fr_count);

private:
	struct ChainNode { // ���� � ������
		FruitName fruit_name; // ����
		int fruit_count; // ��������

		ChainNode* next; // ��������� �� ��������� ���� � ������
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
	// ���-������� ��� ������ �������
	int hash_func(FruitName fr_name);

	// ������ ���������� �� ������
	ChainNode** chain_tops;
	// ���������� ���������� ������
	int mem_size;
	// ���������� ����������� ��� ����-��������
	int count;
};