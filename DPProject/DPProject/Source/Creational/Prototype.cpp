#include "Creational/Prototype.h"

IShape* Rectangle::clone()
{
	return new Rectangle(*this);
}

void Rectangle::draw()
{
	cout << "Rectangle " << "height = " << m_height << "width = " << m_width << "color = " << m_color << endl;
}

Rectangle::Rectangle(int width, int height, string color) : m_width(width), m_height(height), m_color(color)
{

}

IShape* Circle::clone()
{
	return new Circle(*this);
}

void Circle::draw()
{
	cout << "Circle " <<"radius = " << m_radius << "color = " << m_color << endl;
}

Circle::Circle(int radius, string color) : m_radius(radius), m_color(color)
{

}

std::unordered_map<string, IShape*> ShapePrototypeRegistry::shapeMap;

IShape* ShapePrototypeRegistry::getShape(string shapeId)
{
	if (shapeMap.find(shapeId) != shapeMap.end())
	{
		return shapeMap[shapeId]->clone();
	}
	
	return nullptr;
}

void ShapePrototypeRegistry::addShape(string shapeID, IShape* shapeIns)
{
	shapeMap[shapeID] = shapeIns;
}

ShapePrototypeRegistry::~ShapePrototypeRegistry()
{
	for (auto& shape : shapeMap)
	{
		delete shape.second;
	}
}
