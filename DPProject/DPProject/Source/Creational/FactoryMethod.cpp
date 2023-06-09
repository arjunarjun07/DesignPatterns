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