#include "DatabaseJson.h"

#include <fstream>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

#include "nlohmann/json.hpp"

using json = nlohmann::json;

DatabaseJson::DatabaseJson(const std::string& db) : Database{db}
{
    createEmptyDatabase();
}

void DatabaseJson::saveCustomer(const Customer& customer)
{
    json j;
    std::ifstream inputFile(getFilename());
    if (inputFile.is_open())
    {
        inputFile >> j;
        inputFile.close();
    }

    json custJson = {
        {"id", customer.getId()},       {"name", customer.getName()},
        {"city", customer.getCity()},   {"pin", customer.getPin()},
        {"tagId", customer.getTagId()}, {"verificationPhrase", customer.getVerificationPhrase()}};
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

void DatabaseJson::createEmptyDatabase()
{
    json j;
    std::ofstream file{getFilename()};
    if (!file)
    {
        std::cerr << "Failed to create database file\n";
        exit(1);
    }
    else
    {
        file << j.dump(4);
    }
}

std::vector<Customer> DatabaseJson::getCustomers()
{
    // Get customers from database
    return {};
}

DatabaseJson::~DatabaseJson() {}