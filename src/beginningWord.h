#pragma once

#include "Trie.h"

void inputtWords() {
	std::cout << "__________________���� �����!___________________________" << std::endl;

	Trie tr;
	tr.insert("cat");
	tr.insert("cal");
	tr.insert("cu");
	tr.insert("run");
	tr.insert("rut");
	tr.insert("colt");
	while (true) {
		std::cout << "��� ����� ����� ������� ����� ����� \n���� ������ ����� ������� - n" << std::endl;
		char enterExit;
		std::cin >> enterExit;
		switch (enterExit) {
		case 'n':
			return;
		default:
			std::cout << "����� ���� �����, ������� �����!" << std::endl;
			tr.print();
			std::string word;
			std::cin >> word;
			tr.compareWord(word);				
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			break;
		}
		
	}
	
}