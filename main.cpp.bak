#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"
using json = nlohmann::json;

struct Customer {
    int CustomerId;
    std::string CustomerName;
    std::string CustomerAddress;
};

struct Users /*: public Customer*/ {
    /*using Customer::CustomerId;*/
    int UserId;
    int UserCode;                
    std::string UserTagId;
    std::string UserPhrase;
};

struct Components {
    int ComponentId;
    std::string ComponentName;
    std::string ComponentType;
};

/*struct CustomerComponents : public Customer, public Components {
    using Customer::CustomerId;
    using Components::ComponentId;

};*/


bool doesDatabaseExist(const std::string& name) {
    std::ifstream file(name);
    return file.good();
}

int OpenJSONFile(json Filename, std::string& databaseName)
{
    
    std::ifstream file(databaseName);
    if(!file){
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }
    file >> Filename;
    std::cout <<"File opened successfully!" << std::endl;
    return 0;
}

/*int OpenJSONFile(const std::string& filename, std::string& databaseName)
{
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return -1;
    }
    else 
    {
        std::cout << "File opened successfully!" << std::endl;
    }

    json j;
    try {
        file >> j;
    } catch (const json::parse_error& e) {
        std::cerr << "Parse error: " << e.what() << std::endl;
        return -1;
    }

    if (!j.is_object()) {
        std::cerr << "JSON is not an object" << std::endl;
        return -1;
    }

    if (!j.contains("Securitydb") || !j["Securitydb"].is_object()) {
        std::cerr << "JSON does not contain 'Securitydb' object" << std::endl;
        return -1;
    }

    // Now you can safely use the JSON object
    // Example: databaseName = j["Securitydb"]["Customer"][0]["CustomerName"];

    return 0;
}*/

// Funktion för att skriva ut varje objekt i JSON
void processSecuritydb(const json& Securitydb) {
  if (!Securitydb.contains("Securitydb") || !Securitydb["Securitydb"].is_object()) {
        std::cerr << "JSON does not contain 'Securitydb' object" << std::endl;
        return;
    }

    const auto& securitydb = Securitydb["Securitydb"];


    // Hantera Customers
    std::cout << "Customers:\n";
    for (const auto& customer : securitydb["Customer"]) {
        std::cout << "  ID: " << customer["CustomerId"] << ", "
                  << "Name: " << customer["CustomerName"] << ", "
                  << "Address: " << customer["CustomerAddress"] << "\n";
    }

    // Hantera Users
    std::cout << "\nUsers:\n";
    for (const auto& user : securitydb["Users"]) {
        std::cout << "  ID: " << user["UserId"] << ", "
                  << "Code: " << user["UserCode"] << ", "
                  << "Tag: " << user["UserTagId"] << ", "
                  << "Phrase: " << user["UserPhrase"] << "\n";
    }

    // Hantera CustomerComponents
    /*std::cout << "\nCustomerComponents:\n";
    for (const auto& custComp : securitydb["CustomerComponents"]) {
        std::cout << "  CustomerID: " << custComp["CustomerId"] << ", "
                  << "ComponentID: " << custComp["ComponentId"] << "\n";
    }*/

    // Hantera Components
    std::cout << "\nComponents:\n";
    for (const auto& component : securitydb["Components"]) {
        std::cout << "  ID: " << component["ComponentId"] << ", "
                  << "Name: " << component["ComponentName"] << ", "
                  << "Type: " << component["ComponentType"] << "\n";
    }
}



int main() {
    json Securitydb;
    std::string databaseName = "Securitydb.json";
    if (doesDatabaseExist(databaseName)) {
        std::cout << "JSON database exist!" << std::endl;
        OpenJSONFile(Securitydb, databaseName);
        std::cout <<"Database opened";
    } else {
        std::cout << "Database does not exist!" << std::endl;
    }

    processSecuritydb(Securitydb);
    return 0;
}