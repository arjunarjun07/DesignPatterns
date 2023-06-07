#include "..\Header\Creational\FactoryMethod.h"

IProduct* FactoryMethod::CreateProduct(const std::string& type)
{
	if (type == "Electronics")
	{
		return new Electronics();
	}
	else if (type == "Books")
	{
		return new Books();
	}
	else
	{
		return nullptr;
	}
}

/*
Uses:
	- when you don’t know beforehand the exact types and dependencies of the objects your code should work with.
	- when you want to provide users of your library or framework with a way to extend its internal components.
	- when you want to save system resources by reusing existing objects instead of rebuilding them each time.
*/