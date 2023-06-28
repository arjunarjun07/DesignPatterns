#ifndef FACADE_H
#define FACADE_H

#include "stdafx.h"

/*
* About:
* Facade is a structural design pattern that provides a simplified interface to a library, a framework, or any other complex set of classes.
* 
* Facade = front door to your app that hides all the complexity of your app behind a simple interface.
* 
* Facade defines a higher-level interface that makes the subsystem easier to use.
*/

/*
* Example:
* When you call a shop to place a phone order, an operator is your facade to all services and departments of the shop. The operator provides you with a simple voice interface to the ordering system, payment gateways, and various delivery services.
*/

/*
* Uses:
* Use the Facade pattern when you need to have a limited but straightforward interface to a complex subsystem.
*/

class Cpu
{
public:
	bool start();

	bool execute();

	bool stop();
};

class Memory
{
public:
	bool load();

	bool free();
};

class Storage
{
public:
	bool read();

	bool write();
};

class Computer
{
public:
	Computer(Cpu* cpu, Memory* memory, Storage* storage);

	void start();

	void stop();

	~Computer();

private:
	Cpu* m_cpu;
	Memory* m_memory;
	Storage* m_storage;
};

#endif // !FACADE_H
