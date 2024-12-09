#include <iostream>

#include "Menu.h"
#include "Settings.h"
#include "Database.h"

int main()
{
    Settings settings;

    if (!settings.loadSettings("settings.json"))
    {
        std::cout << "Failed to load settings file\n";
        std::cout << "Please choose a database type (json or sqlite3): ";
        std::string dbType;
        while (std::cin >> dbType)
        {
            if (dbType == "json" || dbType == "sqlite3")
            {
                break;
            }
            std::cout << "Invalid database type. Please choose json or sqlite3: ";
        }
        settings.setSetting("database", dbType);
        settings.saveSettings("settings.json");
    }

    std::unique_ptr<Database> db;
    if (settings.getSetting("database") == "json")
    {
        db = std::make_unique<DatabaseJson>("database.json");
    }
    else if (settings.getSetting("database") == "sqlite3")
    {
        db = std::make_unique<DatabaseSqlite3>("database.db");
    }

    Menu menu(std::move(db));
    menu.start();

    std::cout << std::endl;
    std::cout << "Exiting program..." << std::endl;

    return 0;
}