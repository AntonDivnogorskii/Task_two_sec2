#pragma once
#include "Product.h"
#include <iostream>

class Product_in_stock : public Product {

	bool stockAvailability;
	int storageTemperature;

public:

	Product_in_stock(std::string name, std::string manufacturer, int quantity, int thePricePerUnitOfTheProduct, bool stockAvailability, int storageTemperature) {
		this->name = name;
		this->manufacturer = manufacturer;
		this->quantity = quantity;
		this->thePricePerUnitOfTheProduct = thePricePerUnitOfTheProduct;
		this->totalPrice = this->thePricePerUnitOfTheProduct * this->quantity;
		this->stockAvailability = stockAvailability;
		this->storageTemperature = storageTemperature;
	}

	void Information() override {
		std::cout << "Наименование товара: " << this->name << std::endl << "Проиводителей: " << this->manufacturer << std::endl
			<< "Количество товара: " << this->quantity << std::endl << "Цена за единицу изделия: " << this->thePricePerUnitOfTheProduct << std::endl
			<< "Общая цена: " << this->totalPrice << std::endl << "Температура хранения: " << this->storageTemperature << std::endl << "Имеется на складе: ";
		if (stockAvailability)
			std::cout << "Да";
		else
			std::cout << "Нет";
	}

	~Product_in_stock() = default;

	std::string getName() {
		return this->name;
	}

	std::string getManufacturer() {
		return this->manufacturer;
	}

	int getQuantity() {
		return quantity;
	}

	int getThePricePerUnitOfTheProduct() {
		return thePricePerUnitOfTheProduct;
	}

	bool getStockAvailability() {
		return stockAvailability;
	}
	
	int getStorageTemperature() {
		return storageTemperature;
	}
};