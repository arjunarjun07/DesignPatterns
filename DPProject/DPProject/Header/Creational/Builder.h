#ifndef BUILDER_H
#define BUILDER_H

#include "stdafx.h"

/*
* About:
*	The Builder design pattern is a creational pattern that allows you to construct complex objects step by step. It separates the construction of an object from its representation, enabling the same construction process to create different representations.
*/

/*
* Example:
*	Imagine you're building a pizza ordering system. The pizza can have various toppings, crust types, and sizes. The Builder pattern can help you construct different pizza configurations while keeping the construction logic separate from the client code.
*/

//Product

class Pizza
{
private:
	int size;
	string crustType;
	std::vector<string> toppings;

public:

	int getSize() const
	{
		return size;
	}

	void setSize(int size)
	{
		this->size = size;
	}

	string getCrustType() const
	{
		return crustType;
	}

	void setCrustType(string crustType)
	{
		this->crustType = crustType;
	}

	std::vector<string> getToppings() const
	{
		return toppings;
	}

	void setToppings(std::vector<string> toppings)
	{
		this->toppings = toppings;
	}

	string toString()
	{
		string str = "Pizza with size " + std::to_string(size) + ", crust type " + crustType + " and toppings: ";
		for (auto topping : toppings)
		{
			str += topping + " ";
		}
		return str;
	}

	~Pizza()
	{
		cout<< "Pizza object destroyed" << endl;
	}

};

//Abstract Builder - Interface

class IPizzaBuilder
{
public:
	virtual ~IPizzaBuilder() {};
	
	virtual void buildPizzaSize() = 0;
	virtual void buildPizzaCrust() = 0;
	virtual void buildPizzaToppings() = 0;

	virtual void reset() = 0;

	virtual Pizza* getPizzaObj() = 0;
};

// Concrete builder implementations - 1

class MargharittaPizzaBuilder : public IPizzaBuilder
{
public:

	// Inherited via IPizzaBuilder

	MargharittaPizzaBuilder();

	virtual void buildPizzaSize() override;
	virtual void buildPizzaCrust() override;
	virtual void buildPizzaToppings() override;

	virtual void reset() override;

	virtual Pizza* getPizzaObj() override;

	~MargharittaPizzaBuilder();

private:

	Pizza* m_pizza;
};

// Concrete builder implementations - 2 - Similar one with unique member values in Pizza object
//class PepperoniPizzaBuilder : public IPizzaBuilder

//Director - Handles the steps of building the object & return the fully built object to client

class PizzaDirector
{
public:

	PizzaDirector();

	void setPizzaBuilder(IPizzaBuilder* builder);

	Pizza* constructPizza();

	~PizzaDirector();

private:
	IPizzaBuilder* m_builder;
};

#endif // !BUILDER_H
