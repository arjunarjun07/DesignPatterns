#include <iostream>
#include "Creational/FactoryMethod.h"
#include "Creational/AbstractFactory.h"
#include "Creational/Builder.h"


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

void BuilderTest()
{
	PizzaDirector director;
	IPizzaBuilder* builder = new MargharittaPizzaBuilder();

	director.setPizzaBuilder(builder);

	Pizza* pizza = director.constructPizza();
	
	std::cout << "Pizza size : " << pizza->getSize() << std::endl;
	std::cout << "Pizza crust : " << pizza->getCrustType() << std::endl;
	std::cout << "Pizza toppings : ";
	
	for (auto topping : pizza->getToppings())
	{
		std::cout << topping << " ";
	}
	
	std::cout << std::endl;
	
	//pizza will get deleted implicitly when builder is deleted
	delete builder;

	//setting pizza to null to avoid dangling pointer
	pizza = nullptr;
}

int main()
{
	//FactoryMethodTest();

	//AbstractFitureFactoryTest();

	BuilderTest();

	return 0;
}