#pragma once

#include <string>

class Product {

protected:

	std::string name, manufacturer;
	int quantity = 0, thePricePerUnitOfTheProduct = 0, totalPrice = 0;

public:

	Product() {};

	Product(std::string name, std::string manufacturer, int quantity, int thePricePerUnitOfTheProduct) {
		this->name = name;
		this->manufacturer = manufacturer;
		this->quantity = quantity;
		this->thePricePerUnitOfTheProduct = thePricePerUnitOfTheProduct;
		this->totalPrice = this->quantity * this->thePricePerUnitOfTheProduct;
	}

	virtual ~Product() = default;

	virtual void Information() = 0;

	std::string getName() {
		return this->name;
	}

	std::string getManufacturer() {
		return this->manufacturer;
	}

	int getQuantity() {
		return this->quantity;
	}

	int getThePricePerUnitOfTheProduct() {
		return this->thePricePerUnitOfTheProduct;
	}

	int getTotalPrice() {
		return totalPrice;
	}

};