#include "verificationFunctions.h"
#include "MainFunction.h"
#include "The_product_is_in_stock.h"
#include "Functions.h"
#include <string>
#include <iostream>
#include <vector>
#include <fstream>

void savingDataToAFile(const std::vector <Product*> savingList) {

    std::ofstream outputDataForSaving;
    std::string pathForSaving, fileName;
    bool fileExist = 0, fileEmpty = -1;

    std::cout << "������� ���� �� �����, ����� ��������� � ���� ������:\n";

    for (;;) {
        fileExist = 0, fileEmpty = 1;

        getline(std::cin, pathForSaving, '\n');

        fileName = highlightingFileName(pathForSaving);

        //��������� ������ ���� \.txt
        if (fileName == "") {
            std::cout << "��� ����� �� ����� ���� �������!\n";
            continue;
        }

        if (checkingForReservedName(fileName)) {
            std::cout << "����������������� ���! �������� ���� �����: \n";
            continue;
        }

        if (checkingForSpecialCharacters(fileName)) {
            std::cout << "��� ��� ����� �� ������ ��������� ��������� ������: \\ / : * ? \" < > |\n";
            continue;
        }

        if (fileExists(pathForSaving))
            fileExist = 1;
        else
            fileExist = 0;

        if (fileOpenForReading(pathForSaving)) {
            std::cout << "���� �������� ������ ��� ������! ������� ����� ����:\n";
            continue;
        }

        if (fileIsEmpty(pathForSaving)) {
            for(;;){
                std::cout << "� ����� ��� �������� ������. ���� �� ������ ������������ ���� - ������� 1, ����� 0\n";

                fileEmpty = getInt();

                if (fileEmpty == 1 || fileEmpty == 0)
                    break;
            }
        }
        
        
        if (fileExist && fileEmpty) {

            outputDataForSaving.open(pathForSaving);

            for (const auto& object : savingList) {
                if (Product_in_stock* Product_in_stock_object = dynamic_cast<Product_in_stock*>(object)) {
                    outputDataForSaving << Product_in_stock_object->getName() << "\n" << Product_in_stock_object->getQuantity() << "\n" << Product_in_stock_object->getManufacturer() << "\n"
                        << Product_in_stock_object->getThePricePerUnitOfTheProduct() << "\n" << Product_in_stock_object->getStockAvailability() << "\n" << Product_in_stock_object->getStorageTemperature() << '\n';
                }
            }

            std::cout << "������ ��������� � �����: " << pathForSaving << std::endl << std::endl;
            outputDataForSaving.close();
            break;
        }

        if (!fileEmpty) {
            std::cout << "������� ���� �� �����, ����� ��������� � ���� ������:\n";
            continue;
        }

        if (!fileExist) {

            outputDataForSaving.open(pathForSaving);

            for (const auto& object : savingList) {
                if (Product_in_stock* Product_in_stock_object = dynamic_cast<Product_in_stock*>(object)) {
                    outputDataForSaving << Product_in_stock_object->getName() << "\n" << Product_in_stock_object->getQuantity() << "\n" << Product_in_stock_object->getManufacturer() << "\n"
                        << Product_in_stock_object->getThePricePerUnitOfTheProduct() << "\n" << Product_in_stock_object->getStockAvailability() << "\n" << Product_in_stock_object->getStorageTemperature() << '\n';
                }
            }

            std::cout << "��� ������ ����: " << pathForSaving << ". ������ ���� ��������� � ����\n\n";
            outputDataForSaving.close();
            break;
        }
    }
}

//��������� �������� �����
std::string highlightingFileName(const std::string userPath) {

    std::string fileName;
    int countOfSlashes = 0, countOfPoints = 0;

    //���� ��� ����������� ���� �� . ��� \ � ������ 
    for (int i = 0; i < userPath.length(); i++) {
        if (userPath[i] == '.')
            countOfPoints += 1;
        else if (userPath[i] == '\\')
            countOfSlashes += 1;
    }

    //���� ��� . � \ ������ ������ ���� CON
    if (countOfPoints == 0 && countOfSlashes == 0)
        return userPath;

    //���� ������ . ������ ������ ���� CON.txt
    if (countOfPoints > 0 && countOfSlashes == 0) {
        for (char toPoint : userPath) {

            if (toPoint == '.')
                return fileName;

            fileName += toPoint;
        }
    }

    //���� ������ \ ������ ������ ���� ...\CON
    if (countOfSlashes > 0 && countOfPoints == 0) {
        for (size_t i = userPath.size(); i != -1; i--) {
            if (userPath[i] == '\\') {
                reverse(fileName.begin(), fileName.end());
                return fileName;
            }

            fileName += userPath[i];
        }
    }

    //���� . � \ ���� ������ ������ ���� ..\CON.txt
    if (countOfPoints > 0 && countOfSlashes > 0) {
        countOfPoints = 0, countOfSlashes = 0;
        for (size_t i = userPath.size() - 1; i != -1; i--) {

            if (userPath[i] == '\\') {
                reverse(fileName.begin(), fileName.end());
                return fileName;
            }

            if (countOfPoints == 1)
                fileName += userPath[i];

            if (userPath[i] == '.')
                countOfPoints = 1;
        }
    }

    return "";
}

//�������� ������������ ����� �� ����������������� �����
bool checkingForReservedName(const std::string userPath) {

    std::vector<std::string> reservedNames = {
        "con", "Con", "cOn", "coN", "COn", "cON", "CoN", "CON",
        "prn", "Prn", "pRn", "prN", "PRn", "pRN", "PrN", "PRN",
        "aux", "Aux", "aUx", "auX", "AUx", "aUX", "AuX", "AUX",
        "nul", "Nul", "nUl", "nuL", "NUl", "nUL", "NuL", "NUL",
        "com", "Com", "cOm", "coM", "COm", "cOM", "CoM", "COM",
        "lpt", "Lpt", "lPt", "lpT", "LPt", "lPT", "LpT", "LPT", };

    for (std::string reservedName : reservedNames)
        for(char number : "0123456789")
            if (userPath == (reservedName + '\0') || userPath == (reservedName + number) || userPath == (reservedName + number + '\0') || userPath == reservedName)
                return 1;
    return 0;
}

//�������� �� ����������� �������
bool checkingForSpecialCharacters(const std::string userPath) {

    for (char specialCharacter : userPath)
        if (specialCharacter == '\\' || specialCharacter == '/' || specialCharacter == ':' || specialCharacter == '*' || specialCharacter == '?' ||
            specialCharacter == '\"' || specialCharacter == '<' || specialCharacter == '>' || specialCharacter == '|')
            return 1;
    return 0;
}

//�������� �� ������������� �����
bool fileExists(const std::string userPath) {

    std::fstream testOutPut(userPath);

    if (testOutPut.is_open())
        return 1;

    testOutPut.close();

    return 0;
}

//�������� �� ������� �����
bool fileIsEmpty(const std::string userPath) {

    std::string line;

    std::ifstream testOutPut(userPath);

    if (testOutPut.is_open()) {
        if(getline(testOutPut, line))
            return 1;
    }

    return 0;
}

//�������� �� ��, ��� ���� ������ ������ ��� ������
bool fileOpenForReading(const std::string userPath) {

    std::ofstream testOutPut(userPath, std::ios_base::app);

    if (!(testOutPut.is_open())) {
        testOutPut.close();
        return 1;
    }

    testOutPut.close();
    return 0;
}