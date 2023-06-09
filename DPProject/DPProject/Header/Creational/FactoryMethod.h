//header guards
#ifndef FACTORYMETHOD_H
#define FACTORYMETHOD_H

#include "stdafx.h"

/*
* About:
	A factory method is a creational design pattern that provides an interface for creating objects, but allows subclasses to decide which class to instantiate. It encapsulates the object creation logic in a separate method, often called the factory method, which can be overridden by derived classes to produce different types of objects.
*/

/*
Example:
		Imagine a scenario where you have an online store that sells different types of product	
		such as electronics, books, and clothing. Each product category has its own
		implementation of the Product class, and you want to create objects of these product 
		classes dynamically based on user input.
*/

/*
Uses:
	- when you don’t know beforehand the exact types and dependencies of the objects your code should work with.
	- when you want to provide users of your library or framework with a way to extend its internal components.
	- when you want to save system resources by reusing existing objects instead of rebuilding them each time.
*/

//Interface for the products
class IProduct
{
public:
	virtual ~IProduct() {};
	virtual std::string GetProductName() const = 0;
};

class Electronics : public IProduct
{
public:
	std::string GetProductName() const override
	{
		return "Electronics";
	}
};

class Books : public IProduct
{
public:
	std::string GetProductName() const override
	{
		return "Books";
	}
};

class FactoryMethod
{
public:
	//Factory method
	static IProduct* CreateProduct(const std::string& type);
};

#endif // !FACTORYMETHOD_H