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
        virtual void CreateEmptyDatabase() = 0;
        virtual void saveCustomer(const Customer& customer) = 0;
        virtual void saveComponent(const Component& component) = 0;
        virtual void logAlarmEvent(const AlarmEvent& alarmevent) = 0;
        virtual std::list <Customer> getCustomers() = 0;
        virtual ~Database();
        std::string getFilename() const { return filename; }
};