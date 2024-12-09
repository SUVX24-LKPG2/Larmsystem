#include "DatabaseJson.h"

#include <fstream>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

#include "nlohmann/json.hpp"

using json = nlohmann::json;

DatabaseJson::DatabaseJson(const std::string& db) : Database{db} {}

void DatabaseJson::saveCustomer(const Customer& customer)
{
    json j;
    std::ifstream inputFile(getFilename());
    if (inputFile.is_open())
    {
        inputFile >> j;
        inputFile.close();
    }

    // Check if the last_id key exists in the json object
    if (!j.contains("last_id"))
    {
        j["last_id"] = 0;
    }

    // Increment the last_id and add the new customer to the json object
    int newId = j["last_id"].get<int>() + 1;
    j["last_id"] = newId;

    // Add the new customer to the json object
    json custJson = {{"id", newId},
                     {"name", customer.getName()},
                     {"city", customer.getCity()},
                     {"pin", customer.getPin()},
                     {"tagId", customer.getTagId()},
                     {"verificationPhrase", customer.getVerificationPhrase()}};
    j["customers"].push_back(custJson);

    std::ofstream outputFile(getFilename());
    if (outputFile.is_open())
    {
        outputFile << j.dump(4);
        outputFile.close();
    }
    else
    {
        std::cerr << "Failed to open database file for writing\n";
    }
}

void DatabaseJson::saveComponent(const Component& component)
{
    // Save component to database
}

void DatabaseJson::logAlarmEvent(const AlarmEvent& alarmEvent)
{
    // Log alarm event to database
}

std::vector<Customer> DatabaseJson::getCustomers()
{
    // Get customers from database
    return {};
}

DatabaseJson::~DatabaseJson() {}