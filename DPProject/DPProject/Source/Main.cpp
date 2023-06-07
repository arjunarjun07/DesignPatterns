// DPProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Creational/FactoryMethod.h"
#include "Creational/AbstractFactory.h"

void FactoryMethodTest()
{
	IProduct* product = FactoryMethod::CreateProduct("Electronics");

	if (product)
	{
		std::cout << product->GetProductName() << std::endl;
		delete product;
	}

	product = FactoryMethod::CreateProduct("Books");
	
	if (product)
	{
		std::cout << product->GetProductName() << std::endl;
		delete product;
	}
}

void AbstractFitureFactoryTest()
{
	IFurnitureFactory* vfactory = new VintageFurnitureFactory();
	auto vChair = vfactory->createChair();
	auto vTable = vfactory->createTable();

	std::cout << "Vintage products : " << vChair->chairName() << "&" << vTable->tableName() << std::endl;

	IFurnitureFactory* mfactory = new ModernFurnitureFactory();
	auto mChair = mfactory->createChair();
	auto mTable = mfactory->createTable();

	std::cout << "Modern products : " << mChair->chairName() << "&" << mTable->tableName() << std::endl;

	delete vChair;
	delete vTable;

	delete mChair;
	delete mTable;

}

int main()
{
	FactoryMethodTest();

	AbstractFitureFactoryTest();

	return 0;
}