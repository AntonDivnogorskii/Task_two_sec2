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
		std::cout << "������������ ������: " << this->name << std::endl << "�������������: " << this->manufacturer << std::endl
			<< "���������� ������: " << this->quantity << std::endl << "���� �� ������� �������: " << this->thePricePerUnitOfTheProduct << std::endl
			<< "����� ����: " << this->totalPrice << std::endl << "����������� ��������: " << this->storageTemperature << std::endl << "������� �� ������: ";
		if (stockAvailability)
			std::cout << "��";
		else
			std::cout << "���";
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