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
#include <fstream>
#include "windows.h"

int mainFunction(const int choice) {

	setlocale(LC_CTYPE, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int dataEntrySelection = -1, outputSelection = -1;
	std::vector<Product*> listOfProducts;
	
	std::string name, manufacturer;
	int quantity = 0, thePricePerUnitOfTheProduct = 0, storageTemperature = 0, stockAvailability = -1;

	switch (choice) {

	case solution:
	{
		greeetingText();

		do {

			while (dataEntrySelection != endOfInput) {
				menuInputText();

				dataEntrySelection = getInt();

				switch (dataEntrySelection) {
				case manually:
				{

					std::cout << "������� ������������ ������: \n";
					name = getString();

					while (quantity <= 0) {
						std::cout << "������� ���������� ������ (���������� �� ����� ���� ������������� ��� ������ 0!): \n";
						quantity = getInt();
					}

					std::cout << "������� ������������� ������: \n";
					manufacturer = getString();

					while (thePricePerUnitOfTheProduct <= 0) {
						std::cout << "������� ���� �� ������� ������� (���� �� ����� ���� ������������� ��� ������ 0!): \n";
						thePricePerUnitOfTheProduct = getInt();
					}

					std::cout << "���� �� ����� �� ������?: \n";
					while (stockAvailability != 0 && stockAvailability != 1) {
						std::cout << "1 - ����, 0 - ���\n";
						stockAvailability = getInt();
					}

					std::cout << "������� ����������� �������� ������ (����������� ����� ������������� ����� -100 � +100):\n";
					storageTemperature = getInt();
					while (storageTemperature > 100 or storageTemperature < -100) {
						std::cout << "����������� ����� ������������� ����� -100 � +100!\n";
						storageTemperature = getInt();
					}

					Product* newProduct = new Product_in_stock(name, manufacturer, quantity, thePricePerUnitOfTheProduct, stockAvailability, storageTemperature);

					listOfProducts.push_back(newProduct);
					quantity = 0, thePricePerUnitOfTheProduct = 0, storageTemperature = 0, stockAvailability = -1;

					break;
				}

				case fromTheFile:
				{

					std::ifstream inputFromAFile;
					int value�ontroller = 0, countOfDates = 0;
					std::string path, line;

					std::cout << "������� ���� �� �����: \n";

					for (;;) {

						std::cin >> path;
						std::cout << std::endl;
						inputFromAFile.open(path);

						if (inputFromAFile.is_open()) {

							while (getline(inputFromAFile, line, '\n')) {

								value�ontroller += 1;

								switch (value�ontroller) {
								case firstValue:

									if (yesOrNoData(line) == symbol || yesOrNoData(line) == number) {
										name = line;
										countOfDates += 1;
									}
									else
										std::cout << "\n������ ������ � ���� \"������������ ������\"!\n";

									break;

								case secondValue:
									if (yesOrNoData(line) == number) {
										if (stoi(line) <= 0)
											std::cout << "\n���������� �� ����� ���� ������������� ��� ������ 0!\n������ � ������ ������ ��� �������������: " << name << std::endl;
										else {
											quantity = std::stoi(line);
											countOfDates += 1;
										}
									}
									else if (yesOrNoData(line) == symbol)
										std::cout << "\n������������ �������� � ���� \"���������� ������\" � ������ ��� �������������: " << name << "!\n������� �����\n";
									else
										std::cout << "\n������ ������ � ���� \"���������� ������\" � ������ ��� �������������: " << name << "!\n";

									break;

								case thirdValue:
									if (yesOrNoData(line) == symbol || yesOrNoData(line) == number) {
										manufacturer = line;
										countOfDates += 1;
									}
									else
										std::cout << "\n������ ������ � ���� \"������������ ������\" � ������ ��� �������������: " << name << "!\n";

									break;

								case fourthValue:
									if (yesOrNoData(line) == number) {
										if (stoi(line) <= 0)
											std::cout << "\n���� �� ����� ���� ������������� ��� ������ 0!\n������ � ������ ������ ��� �������������: " << name << std::endl;
										else {
											thePricePerUnitOfTheProduct = stoi(line);
											countOfDates += 1;
										}
									}
									else if (yesOrNoData(line) == symbol)
										std::cout << "\n������������ �������� � ���� \"���� ������\" � ������ ��� �������������: " << name << "!\n������� �����\n";
									else
										std::cout << "\n������ ������ � ���� \"���� ������\" � ������ ��� �������������: " << name << "!\n";

									break;

								case fifthValue:
									if (yesOrNoData(line) == number) {

										if (stoi(line))
											stockAvailability = 1;
										else
											stockAvailability = 0;

										countOfDates += 1;
									}
									else if (yesOrNoData(line) == symbol)
										std::cout << "\n������������ �������� � ���� \"���� �� ����� �� ������\" � ������ ��� �������������: " << name << "!\n������� �����\n";
									else
										std::cout << "\n������ ������ � ���� \"���� �� ����� �� ������\" � ������ ��� �������������: " << name << "!\n";

									break;

								case sixValue:
									if (yesOrNoData(line) == number) {
										if (stoi(line) < -100 or stoi(line) > 100)
											std::cout << "\n����������� ����� ������������� ����� -100 � +100!\n������ � ������ ������ ��� �������������: " << name << std::endl;
										else {
											storageTemperature = stoi(line);
											countOfDates += 1;
										}
									}
									else if (yesOrNoData(line) == symbol)
										std::cout << "\n������������ �������� � ���� \"����������� �������� ������\" � ������ ��� �������������: " << name << "!\n������� �����\n";
									else
										std::cout << "\n������ ������ � ���� \"����������� �������� ������\" � ������ ��� �������������: " << name << "!\n";

									break;
								}

								if (value�ontroller == 6 && countOfDates == 6) {
									Product* newProduct = new Product_in_stock(name, manufacturer, quantity, thePricePerUnitOfTheProduct, stockAvailability, storageTemperature);
									listOfProducts.push_back(newProduct);
									quantity = 0, thePricePerUnitOfTheProduct = 0, storageTemperature = 0, stockAvailability = -1, value�ontroller = 0, countOfDates = 0;
								}
								if (value�ontroller == 6 && countOfDates != 6) {
									std::cout << "\n������ ��� ������ ������!\n������� ��� ������������� \"" << name << "\" ������� �� �����!\n";
									quantity = 0, thePricePerUnitOfTheProduct = 0, storageTemperature = 0, stockAvailability = -1, value�ontroller = 0, countOfDates = 0;
								}
							}

							break;
						}
						else {
							std::cout << "����� � ����� ���� ���! B������ ������ ����:\n";
							continue;
						}
					}

					inputFromAFile.close();
					break;
				}

				case saveDataInAFile:
				{
					if(listOfProducts.size() == 0) {
						std::cout << "\n�� �� ����� �� ������ ������!\n";
						dataEntrySelection = -1;
					}
					else
						savingDataToAFile(listOfProducts);

					break;
				}

				case endOfInput:
				{
					std::cout << "\n���� ������ ��������\n\n";
					break;
				}

				default:
					std::cout << "\n������ " << dataEntrySelection << " ��� � ����\n\n";
					break;
				}

			};

			menuOutputText();

			outputSelection = getInt();
			std::cout << std::endl;

			switch (outputSelection) {
			case output:
			{
				int savingInFile = -1;
				if (listOfProducts.size() == 0)
					std::cout << "\n�� �� ����� �� ������ ������!\n";
				else {

					std::cout << "������ ��������� ������ � �����?\n1 - ��, 0 - ���\n";
					savingInFile = getInt();
					while (savingInFile != 0 && savingInFile != 1) {
						std::cout << "�� ������ ������� ���� ���� �� �������!\n1 - ��, 0 - ���\n";
						savingInFile = getInt();
					}
					std::cout << std::endl;

					if (savingInFile) {
						savingDataToAFile(listOfProducts);
					}

					for (int i = 0; i < listOfProducts.size(); i++)
					{
						listOfProducts[i]->Information();
						std::cout << std::endl << std::endl;
					}
				}
				break;
			}

			case newData:
			{

				for (int i = 0; i < listOfProducts.size(); i++)
					delete listOfProducts[i];

				listOfProducts.clear();
				dataEntrySelection = -1;
				std::cout << "������ ���� ��������\n";

				break;
			}

			case addData:
			{
				dataEntrySelection = -1;
				std::cout << "���������� ������\n";
				break;
			}

			case quit:
				std::cout << "���������� ������ ���������\n";
				break;

			default:
				std::cout << "\n������ " << outputSelection << " ��� � ����\n\n";
				break;
			}
			
		}while (outputSelection != quit);

		break;
	}

	case testing:
	{
		if (testingFunction()) 
			std::cout << "���������� ��������� �������\n\n";

		break;
	}

	}

	return 0;
}