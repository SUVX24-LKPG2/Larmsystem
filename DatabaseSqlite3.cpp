#include "DatabaseSqlite3.h"

#include <iostream>

DatabaseSqlite3::DatabaseSqlite3(const std::string& filename) : Database(filename) {}
void DatabaseSqlite3::createEmptyDatabase()
{
    // code
}
void DatabaseSqlite3::saveCustomer(const Customer& customer)
{
    // code
}
void DatabaseSqlite3::saveComponent(const Component& component)
{
    // code
}
void DatabaseSqlite3::logAlarmEvent(const AlarmEvent& alarmevent)
{
    // code
}
std::vector<Customer> getCustomers()
{
    return {};
}
DatabaseSqlite3::~DatabaseSqlite3() {}