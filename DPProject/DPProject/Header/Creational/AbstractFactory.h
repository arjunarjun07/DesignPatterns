#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H

#include "stdafx.h"

/*
* About:
	Abstract Factory defines an interface for creating all distinct products but leaves the 
	actual product creation to concrete factory classes. Each factory type corresponds to a 
	certain product variety.
*/

/*
* Example:

	Usually when we have products vs category matrix - we can go for abstract factory

	say,
				Modern	   |	Vintage		|
		----------------------------------------
		chair |	m.chair	   |	v.chair		|

		table |	m.table	   |	v.table		|

		* Tha products are abstracted with interfaces. (chair & table)
		* The categories are abstracted with factories. (IFurnitureFactory -> ModernFurnitureFactory & VintageFurnitureFactory

*/

/*
Uses:
	- Use the Abstract Factory when your code needs to work with various families of related products, but you don’t want it to depend on the concrete classes of those products—they might
	  be unknown beforehand or you simply want to allow for future extensibility.

	- Consider implementing the Abstract Factory when you have a class with a set of Factory Methods
	  that blur its primary responsibility.
*/

class IChair
{
public:
	virtual ~IChair() {};
	virtual std::string chairName() = 0;
};

class ModernChair : public IChair
{
public:
	std::string chairName() override
	{
		return "Modern Chair";
	}
};

class VintageChair : public IChair
{
public:
	std::string chairName() override
	{
		return "Vintage Chair";
	}
};


class ITable
{
public:
	virtual ~ITable() {};
	virtual std::string tableName() = 0;
};

class ModernTable : public ITable
{
public:
	std::string tableName() override
	{
		return "Modern Table";
	}
};

class VintageTable : public ITable
{
public:
	std::string tableName() override
	{
		return "Vintage Table";
	}
};

class IFurnitureFactory
{
public:
	virtual ~IFurnitureFactory() {};
	virtual IChair* createChair() = 0;
	virtual ITable* createTable() = 0;
};

class ModernFurnitureFactory : public IFurnitureFactory
{
public:
	IChair* createChair() override;
	ITable* createTable() override;
};

class VintageFurnitureFactory : public IFurnitureFactory
{
public:
	IChair* createChair() override;
	ITable* createTable() override;
};

#endif // !ABSTRACTFACTORY_H