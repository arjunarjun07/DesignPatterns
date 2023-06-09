#include "Creational\Singleton.h"

Database* Database::m_instance = nullptr;
std::mutex Database::mutex;


Database* Database::getInstance()
{
	std::lock_guard<std::mutex> lock(mutex);

	if(m_instance == nullptr)
	{
		m_instance = new Database();
	}

	return m_instance;
}

void Database::queryData()
{
	std::cout << "Querying data from database" << std::endl;
}
