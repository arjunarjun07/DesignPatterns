#ifndef PROTOTYPE_H
#define PROTOTYPE_H

#include "stdafx.h"
#include <unordered_map>

/*
* About:
* The Prototype design pattern is a creational pattern that allows you to create new objects by cloning existing ones, avoiding the need for explicit instantiation. It provides a way to create objects based on a prototype instance, which serves as a blueprint for creating new objects with similar properties.
*/

/*
* Example:
* Imagine you're building a game where players can customize their characters. You want to give them the ability to create a character based on an existing one, but with some modifications. The Prototype pattern can help you implement this functionality.
* 
* 
* Immutable objects, Undo/Redo, GUI Frameworks to copy elements, Copying complex objects that have circular references, Copying objects without knowing their concrete classes

* */

/*
* Uses:
* You can clone objects without coupling to their concrete classes.
* You can get rid of repeated initialization code in favor of cloning pre-built prototypes.
* You can produce complex objects more conveniently.
* You get an alternative to inheritance when dealing with configuration presets for complex objects.
*/

class IShape
{
public:
	virtual IShape* clone() = 0;

	virtual void draw() = 0;
	
	virtual ~IShape() {}
};

class Rectangle : public IShape
{
public:

	IShape* clone() override;

	void draw() override;

	Rectangle() = default;

	Rectangle(int width, int height, string color);

private:
	int m_width;
	int m_height;

	string m_color;
};

class Circle : public IShape
{
public:
	IShape* clone() override;

	void draw() override;

	Circle() = default;

	Circle(int radius, string color);

private:
	int m_radius;
	string m_color;
};

class ShapePrototypeRegistry
{

public:
	static IShape* getShape(string shapeId);

	static void addShape(string shapeID, IShape* shapeIns);

private:
	static std::unordered_map<string, IShape*> shapeMap;
};

#endif // !PROTOTYPE_H
