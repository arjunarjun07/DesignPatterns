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