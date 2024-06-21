#pragma once
#include "MainFunction.h"
#include "The_product_is_in_stock.h"
#include <iostream>
#include <vector>

bool checkingForReservedName(const std::string userPath);

std::string highlightingFileName(std::string userPath);

bool checkingForSpecialCharacters(const std::string userPath);

bool fileExists(const std::string userPath);

bool fileIsEmpty(const std::string userPath);

bool fileOpenForReading(const std::string userPath);

void savingDataToAFile(const std::vector <Product*> savingList);