#include "pch.h"
#include "Sentence.h"

int main()
{
	char choice;
	do {
		Sentence Sentence;
		Sentence.showSentence();
		std::cout << "Again? [Y/N] ";
		std::cin >> choice;
		while (std::strchr("ynYN", choice) == nullptr) {
			std::cout << "Enter y or n: ";
			std::cin >> choice;
		}
	} while (choice != 'n');

	std::cout << "\nGoodbye.\n";
	return 0;
}
