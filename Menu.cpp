#include "menu.h"

#include <iostream>
#include <memory>
#include <string>
#include <string_view>

#include "Database.h"

#ifdef _WIN32
#    include <windows.h>
#else
#    include <unistd.h>
#endif

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
    std::cin.ignore();
    std::cin.get();
}

void Menu::registerCustomer()
{
    // std::unique_ptr<Customer> customer = std::make_unique<Customer>();
    Customer customer;

    Menu::clearScreen();
    std::string name;
    std::cout << "Register name: ";
    std::cin >> name;
    customer.setName(name);
    std::string address;
    std::cout << "Address: ";
    std::cin >> address;
    customer.setAddress(address);
    Menu::getUserInput();
    m_db->saveCustomer(customer);
}

void Menu::registerComponent()
{
    // code
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
        std::cout << "      Larmsystem\n"
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