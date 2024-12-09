#ifndef DB_JSON_H
#define DB_JSON_H

#include <string>

#include "Database.h"
#include "nlohmann/json.hpp"

using json = nlohmann::json;

class DatabaseJson : public Database
{
public:
    DatabaseJson(const std::string& db);
    ~DatabaseJson();
    void saveCustomer(const Customer& customer) override;
    void saveComponent(const Component& component) override;
    void logAlarmEvent(const AlarmEvent& alarmEvent) override;
    std::vector<Customer> getCustomers() override;
};

#endif  // DB_JSON_H