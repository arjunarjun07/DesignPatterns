#include "Structural\Facade.h"

bool Cpu::start()
{
	std::cout << "Cpu::start()" << std::endl;
	return false;
}

bool Cpu::execute()
{
	std::cout << "Cpu::execute()" << std::endl;
	return false;
}

bool Cpu::stop()
{
	std::cout << "Cpu::stop()" << std::endl;
	return false;
}

bool Memory::load()
{
	std::cout << "Memory::load()" << std::endl;
	return false;
}

bool Memory::free()
{
	std::cout << "Memory::free()" << std::endl;
	return false;
}

bool Storage::read()
{
	std::cout << "Storage::read()" << std::endl;
	return false;
}

bool Storage::write()
{
	std::cout << "Storage::write()" << std::endl;
	return false;
}

Computer::Computer(Cpu* cpu, Memory* memory, Storage* storage) : m_cpu(cpu), m_memory(memory), m_storage(storage)
{

}

void Computer::start()
{	
	cout << "Computer::start()" << endl;

	m_cpu->start();
	m_memory->load();
	m_storage->read();
	m_cpu->execute();
}

void Computer::stop()
{
cout << "Computer::stop()" << endl;

	m_memory->free();
	m_storage->write();
	m_cpu->stop();
}

Computer::~Computer()
{
	if (m_cpu)
	{
		delete m_cpu;
		m_cpu = nullptr;
	}

	if (m_memory)
	{
		delete m_memory;
		m_memory = nullptr;
	}

	if (m_storage)
	{
		delete m_storage;
		m_storage = nullptr;
	}

}
