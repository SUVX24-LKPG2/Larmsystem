#include "Menu.h"

#include <cstdlib>
#include <iostream>
#include <limits>
#include <memory>
#include <string>
#include <string_view>
#include <vector>

#include "Component.h"
#include "Customer.h"
#include "Database.h"

void Menu::clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void Menu::getUserInput()
{
    std::cout << "Press a key to continue..." << std::endl;
    std::cin.get();
}

void Menu::cinIgnore()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Menu::registerCustomer()
{
    Customer customer;

    std::string name, address, phrase;
    int pin, tagId;

    Menu::clearScreen();

    std::cout << "Enter Customer Name: ";
    Menu::cinIgnore();
    std::getline(std::cin, name);

    std::cout << "Enter Customer Address: ";
    std::getline(std::cin, address);

    std::cout << "Enter PIN Code: ";
    std::cin >> pin;
    Menu::cinIgnore();

    std::cout << "Enter Tag ID: ";
    std::cin >> tagId;
    Menu::cinIgnore();

    std::cout << "Enter Verification Phrase: ";
    std::getline(std::cin, phrase);

    customer.setName(name);
    customer.setCity(address);
    customer.setPin(pin);
    customer.setTagId(tagId);
    customer.setVerificationPhrase(phrase);

    std::cout << "\nCustomer Information:\n";
    //std::cout << "ID: " << customer.getId() << "\n";
    std::cout << "Name: " << customer.getName() << "\n";
    std::cout << "Address: " << customer.getCity() << "\n";
    std::cout << "PIN Code: " << customer.getPin() << "\n";
    std::cout << "Tag ID: " << customer.getTagId() << "\n";
    std::cout << "Verification Phrase: " << customer.getVerificationPhrase() << "\n";

    m_db->saveCustomer(customer);

    getUserInput();
}

void Menu::registerComponent() 
{
    Component component;

    std::string type, name, uniqueID;

    Menu::clearScreen();

    std::cout << "Enter Component Type: ";
    std::cin >> type;

    std::cout << "Enter Component Name: ";
    std::cin >> name;

    std::cout << "Enter Unique ID: ";
    std::cin >> uniqueID;
    Menu::cinIgnore();

    component.setType(type);
    component.setName(name);
    component.setUniqueID(uniqueID);

    std::cout << "\nComponent Information:\n";
    std::cout << "Type: " << component.getType() << "\n";
    std::cout << "Name: " << component.getName() << "\n";
    std::cout << "Unique ID: " << component.getUniqueID() << "\n";

    m_db->saveComponent(component);

    getUserInput();
}

void Menu::simulateAlarm()
{
    // code
}

void Menu::start()
{
    while (true)
    {
        clearScreen();
        std::cout << "   Alarm Management\n"
                     "----------------------\n"
                     "1. Register Customer\n"
                     "2. Register Component\n"
                     "3. Simulate Alarm\n"
                     "4. Exit\n"
                     "Choose an option: ";
        int choice;
        std::cin >> choice;
        switch (choice)
        {
            case 1:
                registerCustomer();
                break;
            case 2:
                registerComponent();
                break;
            case 3:
                simulateAlarm();
                break;
            case 4:
                return;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    }
}