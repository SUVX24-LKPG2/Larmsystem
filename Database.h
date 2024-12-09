#include <iostream>
#include <array>
#include <list>
#include "Customer.h"
#include "Component.h"
#include "AlarmEvent.h"
class Database {
    private: 
        std::string filename;
    public: 
        Database(std::string filename) : filename(filename) {}
        virtual std::array<Customer> saveCustomer() = 0;
        virtual std::array<Component> saveComponent() = 0;
        virtual std::array<AlarmEvent> logAlarmEvent() = 0;
        virtual std::list <Customer> getCustomers() = 0;
        virtual ~Database();
};