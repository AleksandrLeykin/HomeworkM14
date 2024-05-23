#pragma once

#include "Trie.h"

void inputtWords() {
	std::cout << "__________________ВВод слова!___________________________" << std::endl;

	Trie tr;
	tr.insert("cat");
	tr.insert("cal");
	tr.insert("cu");
	tr.insert("run");
	tr.insert("rut");
	tr.insert("colt");
	while (true) {
		std::cout << "для ввода слова нажмите любую букву \nесли хотите выйти нажмите - n" << std::endl;
		char enterExit;
		std::cin >> enterExit;
		switch (enterExit) {
		case 'n':
			return;
		default:
			std::cout << "Перед вами слова, введите любое!" << std::endl;
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