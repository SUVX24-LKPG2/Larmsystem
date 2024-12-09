#ifndef DATABASESQLITE3_H
#define DATABASESQLITE3_H
#include <iostream>
#include <vector>
#include "Database.h"
#include "Customer.h"
#include "Component.h"
#include "AlarmEvent.h"
class DatabaseSqlite3 : public Database {
    public: 
        DatabaseSqlite3(std::string filename) : Database(filename) {}
        void createEmptyDatabase() override;
        void saveCustomer(const Customer& customer) override;
        void saveComponent(const Component& component) override;
        void logAlarmEvent(const AlarmEvent& alarmevent) override;
        std::vector <Customer> getCustomers() override;
        ~DatabaseSqlite3();
};
#endif