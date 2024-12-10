#include "DatabaseSqlite3.h"

#include <sqlite3.h>

#include <iostream>

DatabaseSqlite3::DatabaseSqlite3(const std::string& filename) : Database(filename) {}

void DatabaseSqlite3::saveCustomer(const Customer& customer)
{
    sqlite3* db;
    char* zErrMsg = 0;
    int rc;

    rc = sqlite3_open(getFilename().c_str(), &db);

    if (rc)
    {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return;
    }

    std::string sql = "";

    // Create table if it doesn't exist
    sql =
        "CREATE TABLE IF NOT EXISTS customers (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, "
        "address TEXT, "
        "pin INTEGER, tag_id INTEGER, verification_phrase TEXT);";

    rc = sqlite3_exec(db, sql.c_str(), nullptr, 0, &zErrMsg);
    if (rc != SQLITE_OK)
    {
        std::cerr << "SQL error: " << zErrMsg << std::endl;
        sqlite3_free(zErrMsg);
    }
    else
    {
        std::cout << "Table created successfully" << std::endl;
    }

    // Insert customer data
    sql = "INSERT INTO customers (name, address, pin, tag_id, verification_phrase) VALUES ('" +
          customer.getName() + "', '" + customer.getCity() + "', " +
          std::to_string(customer.getPin()) + ", " + std::to_string(customer.getTagId()) + ", '" +
          customer.getVerificationPhrase() + "');";

    rc = sqlite3_exec(db, sql.c_str(), nullptr, 0, &zErrMsg);
    if (rc != SQLITE_OK)
    {
        std::cerr << "SQL error: " << zErrMsg << std::endl;
        sqlite3_free(zErrMsg);
    }
    else
    {
        std::cout << "Record created successfully" << std::endl;
    }

    sqlite3_close(db);
}
void DatabaseSqlite3::saveComponent(const Component& component)
{
    sqlite3* db;
    char* zErrMsg = 0;
    int rc;

    rc = sqlite3_open(getFilename().c_str(), &db);

    if (rc)
    {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return;
    }

    std::string sql = "";

    // Create table if it doesn't exist
    sql =
        "CREATE TABLE IF NOT EXISTS components (id INTEGER PRIMARY KEY AUTOINCREMENT, type TEXT, "
        "name TEXT, "
        "unique_id TEXT);";

    rc = sqlite3_exec(db, sql.c_str(), nullptr, 0, &zErrMsg);
    if (rc != SQLITE_OK)
    {
        std::cerr << "SQL error: " << zErrMsg << std::endl;
        sqlite3_free(zErrMsg);
    }
    else
    {
        std::cout << "Table created successfully" << std::endl;
    }

    // Insert customer data
    sql = "INSERT INTO components (type, name, unique_id) VALUES ('" + component.getType() +
          "', '" + component.getName() + "', '" + component.getUniqueID() + "');";

    rc = sqlite3_exec(db, sql.c_str(), nullptr, 0, &zErrMsg);
    if (rc != SQLITE_OK)
    {
        std::cerr << "SQL error: " << zErrMsg << std::endl;
        sqlite3_free(zErrMsg);
    }
    else
    {
        std::cout << "Record created successfully" << std::endl;
    }

    sqlite3_close(db);
}
void DatabaseSqlite3::logAlarmEvent(const AlarmEvent& alarmevent)
{
    // code
}
std::vector<Customer> DatabaseSqlite3::getCustomers()
{
    return {};
}
DatabaseSqlite3::~DatabaseSqlite3() {}