#ifndef MENU_H
#define MENU_H

#include <memory>

#include "Database.h"

class Menu
{
private:
    std::unique_ptr<Database> m_db;
    void clearScreen();
    void getUserInput();
    void cinIgnore();
    void registerCustomer();
    void registerComponent();
    void simulateAlarm();

public:
    explicit Menu(std::unique_ptr<Database> db) : m_db(std::move(db)) {}
    void start();
};

#endif  // MENU_H