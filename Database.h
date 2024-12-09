#ifndef DATABASE_H
#define DATABASE_H

#include "Customer.h"
#include "Component.h"
#include "AlarmEvent.h"

#include <iostream>
#include <list>
#include <vector>

class Database
{
private:
    std::string filename;

public:
    Database(std::string filename) : filename(filename) {}
    virtual ~Database() {}
    virtual void createEmptyDatabase()                       = 0;
    virtual void saveCustomer(const Customer& customer)      = 0;
    virtual void saveComponent(const Component& component)   = 0;
    virtual void logAlarmEvent(const AlarmEvent& alarmevent) = 0;
    virtual std::vector<Customer> getCustomers()             = 0;
    std::string getFilename() const { return filename; }
};

#endif  // DATABASE_H