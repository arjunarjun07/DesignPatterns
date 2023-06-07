#include "..\Header\Creational\AbstractFactory.h"

IChair* ModernFurnitureFactory::createChair()
{
    return new ModernChair();
}

ITable* ModernFurnitureFactory::createTable()
{
    return new ModernTable();
}

IChair* VintageFurnitureFactory::createChair()
{
    return new VintageChair();
}

ITable* VintageFurnitureFactory::createTable()
{
    return new VintageTable();
}

/*
Uses:
    - Use the Abstract Factory when your code needs to work with various families of related products, but you don’t want it to depend on the concrete classes of those products—they might
      be unknown beforehand or you simply want to allow for future extensibility.

    - Consider implementing the Abstract Factory when you have a class with a set of Factory Methods
      that blur its primary responsibility.
*/