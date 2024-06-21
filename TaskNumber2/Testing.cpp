#include "MainFunction.h"
#include "TextFunctions.h"
#include "verificationFunctions.h"
#include "Functions.h"
#include "Product.h"
#include "The_product_is_in_stock.h"
#include "Testing.h"
#include <locale.h>
#include <iostream>
#include <vector>

bool testingFunction() {

	//���������� ��� �����
	int jobOptions = 0, numberOfTests = 5;
	//���������� ��� ����������� ������
	bool checkTestData = false;

	for (jobOptions = 0; jobOptions < numberOfTests; jobOptions++) {

		if (jobOptions == firstTesting) {

			std::string stringToCheck = "am", checedString = "am.nym";

			if (highlightingFileName(checedString) == stringToCheck)
				checkTestData = true;
			else {
				std::cout << "��������� ���������: " << stringToCheck << "\n���������� ���������: " << highlightingFileName(checedString) << std::endl;
				return false;
			}
		}

		else if (jobOptions == secondTesting) {
			
			std::string stringToCheck = "Gojo", checedString = "D:\\The\\Best\\Person\\Is\\Gojo.Satoru";

			if (highlightingFileName(checedString) == stringToCheck)
				checkTestData = true;
			else {
				std::cout << "��������� ���������: " << stringToCheck << "\n���������� ���������: " << highlightingFileName(checedString) << std::endl;
				return false;
			}
		}

		else if (jobOptions == thirdTesting) {

			std::string stringToCheck = "", checedString = "\\.txt";

			if (highlightingFileName(checedString) == stringToCheck)
				checkTestData = true;
			else {
				std::cout << "��������� ���������: " << stringToCheck << "\n���������� ���������: " << highlightingFileName(checedString) << std::endl;
				return false;
			}
		}

		else if (jobOptions == fourthTesting) {
			
			std::string checedString = "CoN1";
			bool valueToCheck = 1;

			if (checkingForReservedName(checedString) == valueToCheck)
				checkTestData = true;
			else {
				std::cout << "��������� ���������: " << valueToCheck << "\n���������� ���������: " << checkingForReservedName(checedString) << std::endl;
				return false;
			}
		}

		else if (jobOptions == fifthTesting) {
			
			std::string checedString = "An|on";
			bool valueToCheck = 1;

			if(checkingForSpecialCharacters(checedString) == valueToCheck)
				checkTestData = true;
			else {
				std::cout << "��������� ���������: " << valueToCheck << "\n���������� ���������: " << checkingForSpecialCharacters(checedString) << std::endl;
				return false;
			}
		}
	}

	return checkTestData;
}
