#include "Functions.h"
#include <string>
#include <iostream>

int getInt() {

	int userNumber = 0;
	std::string s;

	while (!(std::cin >> userNumber))
	{
		std::cin.clear();
		std::cin >> s;
		while (std::cin.get() != '\n');
		std::cout << "\nÎøèáêà ââîäà. Ââåäèòå ÷èñëî:\n";
	}

	std::cin.clear();
	while (std::cin.get() != '\n');

	return userNumber;
}

int yesOrNoData(const std::string fileValue) {

	for (char value : fileValue) {
		for (char symbol : "qwertyuiopasdfghjklzxcvbnméöóêåíãøùçõúôûâàïðîëäæýÿ÷ñìèòüáþ")
			if (value == symbol)
				return 1;
		for (char number : "1234567890")
			if (value == number)
				return 2;
	}

	return 0;
}

std::string getString() {

	std::string userString;

	std::cin >> userString;

	std::cin.clear();
	while (std::cin.get() != '\n');

	return userString;
}