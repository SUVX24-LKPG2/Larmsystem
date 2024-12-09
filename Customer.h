#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>

class Customer {
private:
int customerId;
std::string customerName;
std::string customerAddress;
static int nextId; 
 
public: 
    Customer(int customerId, std::string customerName,std::string customerAddress) : customerId(nextId++), customerName(customerName), customerAddress(customerAddress) {}
   
   
    Customer() : customerId(nextId++), customerName(""), customerAddress("") {}

    int getCustomerId() const { return customerId; }
    std::string getCustomerName() const { return customerName; }
    std::string getCustomerAddress() const { return customerAddress;}

    void setCustomerId(int id) { customerId = id; }
    void setCustomerName(const std::string& name) { customerName = name; }
    void setCustomerAddress(const std::string& address) { customerAddress = address; }
};

int customerId = 1;
#endif
