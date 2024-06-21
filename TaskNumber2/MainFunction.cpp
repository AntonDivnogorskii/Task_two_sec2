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

					std::cout << "Введите наименование товара: \n";
					name = getString();

					while (quantity <= 0) {
						std::cout << "Введите количество товара (количество не может быть отрицательным или равным 0!): \n";
						quantity = getInt();
					}

					std::cout << "Введите производителя товара: \n";
					manufacturer = getString();

					while (thePricePerUnitOfTheProduct <= 0) {
						std::cout << "Введите цену за единицу изделия (цена не может быть отрицательной или равной 0!): \n";
						thePricePerUnitOfTheProduct = getInt();
					}

					std::cout << "Есть ли товар на складе?: \n";
					while (stockAvailability != 0 && stockAvailability != 1) {
						std::cout << "1 - есть, 0 - нет\n";
						stockAvailability = getInt();
					}

					std::cout << "Введите температуру хранения товара (температура может варьироваться между -100 и +100):\n";
					storageTemperature = getInt();
					while (storageTemperature > 100 or storageTemperature < -100) {
						std::cout << "Температура может варьироваться между -100 и +100!\n";
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
					int valueСontroller = 0, countOfDates = 0;
					std::string path, line;

					std::cout << "Введите путь до файла: \n";

					for (;;) {

						std::cin >> path;
						std::cout << std::endl;
						inputFromAFile.open(path);

						if (inputFromAFile.is_open()) {

							while (getline(inputFromAFile, line, '\n')) {

								valueСontroller += 1;

								switch (valueСontroller) {
								case firstValue:

									if (yesOrNoData(line) == symbol || yesOrNoData(line) == number) {
										name = line;
										countOfDates += 1;
									}
									else
										std::cout << "\nПустая строка в поле \"наименование товара\"!\n";

									break;

								case secondValue:
									if (yesOrNoData(line) == number) {
										if (stoi(line) <= 0)
											std::cout << "\nКоличество не может быть отрицательным или равным 0!\nОшибка в данных товара под наименованием: " << name << std::endl;
										else {
											quantity = std::stoi(line);
											countOfDates += 1;
										}
									}
									else if (yesOrNoData(line) == symbol)
										std::cout << "\nНекорректное значение в поле \"количество товара\" у товара под наименованием: " << name << "!\nВведите число\n";
									else
										std::cout << "\nПустая строка в поле \"количество товара\" у товара под наименованием: " << name << "!\n";

									break;

								case thirdValue:
									if (yesOrNoData(line) == symbol || yesOrNoData(line) == number) {
										manufacturer = line;
										countOfDates += 1;
									}
									else
										std::cout << "\nПустая строка в поле \"прозводитель товара\" у товара под наименованием: " << name << "!\n";

									break;

								case fourthValue:
									if (yesOrNoData(line) == number) {
										if (stoi(line) <= 0)
											std::cout << "\nЦена не может быть отрицательной или равной 0!\nОшибка в данных товара под наименованием: " << name << std::endl;
										else {
											thePricePerUnitOfTheProduct = stoi(line);
											countOfDates += 1;
										}
									}
									else if (yesOrNoData(line) == symbol)
										std::cout << "\nНекорректное значение в поле \"цена товара\" у товара под наименованием: " << name << "!\nВведите число\n";
									else
										std::cout << "\nПустая строка в поле \"цена товара\" у товара под наименованием: " << name << "!\n";

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
										std::cout << "\nНекорректное значение в поле \"есть ли товар на складе\" у товара под наименованием: " << name << "!\nВведите число\n";
									else
										std::cout << "\nПустая строка в поле \"есть ли товар на складе\" у товара под наименованием: " << name << "!\n";

									break;

								case sixValue:
									if (yesOrNoData(line) == number) {
										if (stoi(line) < -100 or stoi(line) > 100)
											std::cout << "\nТемпература может варьироваться между -100 и +100!\nОшибка в данных товара под наименованием: " << name << std::endl;
										else {
											storageTemperature = stoi(line);
											countOfDates += 1;
										}
									}
									else if (yesOrNoData(line) == symbol)
										std::cout << "\nНекорректное значение в поле \"температура хранения товара\" у товара под наименованием: " << name << "!\nВведите число\n";
									else
										std::cout << "\nПустая строка в поле \"температура хранения товара\" у товара под наименованием: " << name << "!\n";

									break;
								}

								if (valueСontroller == 6 && countOfDates == 6) {
									Product* newProduct = new Product_in_stock(name, manufacturer, quantity, thePricePerUnitOfTheProduct, stockAvailability, storageTemperature);
									listOfProducts.push_back(newProduct);
									quantity = 0, thePricePerUnitOfTheProduct = 0, storageTemperature = 0, stockAvailability = -1, valueСontroller = 0, countOfDates = 0;
								}
								if (valueСontroller == 6 && countOfDates != 6) {
									std::cout << "\nОшибки при чтении данных!\nПродукт под наименованием \"" << name << "\" сохранён не будет!\n";
									quantity = 0, thePricePerUnitOfTheProduct = 0, storageTemperature = 0, stockAvailability = -1, valueСontroller = 0, countOfDates = 0;
								}
							}

							break;
						}
						else {
							std::cout << "Файла с таким путём нет! Bведите другой путь:\n";
							continue;
						}
					}

					inputFromAFile.close();
					break;
				}

				case saveDataInAFile:
				{
					if(listOfProducts.size() == 0) {
						std::cout << "\nВы не ввели ни одного товара!\n";
						dataEntrySelection = -1;
					}
					else
						savingDataToAFile(listOfProducts);

					break;
				}

				case endOfInput:
				{
					std::cout << "\nВвод данных завершён\n\n";
					break;
				}

				default:
					std::cout << "\nПункта " << dataEntrySelection << " нет в меню\n\n";
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
					std::cout << "\nВы не ввели ни одного товара!\n";
				else {

					std::cout << "Хотите сохранить данные в файле?\n1 - Да, 0 - Нет\n";
					savingInFile = getInt();
					while (savingInFile != 0 && savingInFile != 1) {
						std::cout << "Вы можете выбрать лишь один из пунктов!\n1 - Да, 0 - Нет\n";
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
				std::cout << "Данные были сброшены\n";

				break;
			}

			case addData:
			{
				dataEntrySelection = -1;
				std::cout << "Добавление данных\n";
				break;
			}

			case quit:
				std::cout << "Завершение работы программы\n";
				break;

			default:
				std::cout << "\nПункта " << outputSelection << " нет в меню\n\n";
				break;
			}
			
		}while (outputSelection != quit);

		break;
	}

	case testing:
	{
		if (testingFunction()) 
			std::cout << "Тестировка завершена успешно\n\n";

		break;
	}

	}

	return 0;
}