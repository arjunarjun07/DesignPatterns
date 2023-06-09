#ifndef SINGLETON_H
#define SINGLETON_H

#include "stdafx.h"
#include <mutex>

/*
* About:
* Singleton is a creational design pattern, which ensures that only one object of its kind exists and provides a single point of access to it for any other code.
*/

/*
* Example:
* The government is an excellent example of the Singleton pattern. A country can have only one official government. Regardless of the personal identities of the individuals who form governments, the title, “The Government of X”, is a global point of access that identifies the group of people in charge.
*/

/*
* Uses:
* - Use the Singleton pattern when a class in your program should have just a single instance available to all clients; for example, a single database object shared by different parts of the program.
* - Use the Singleton pattern when you need stricter control over global variables.
*/

class Database {
private:
    static Database* m_instance;
    static std::mutex mutex;

    // Private constructor to prevent direct instantiation
    Database() {}

public:
    // Static method to access the singleton instance
    static Database* getInstance();

    // Dummy method to demonstrate the functionality of the singleton
    void queryData();
};

#endif // !SINGLETON_H
