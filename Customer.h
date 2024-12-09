#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>

class Customer {
private:
int customerId;
std::string customerName;
std::string customerAdress;
 
public: 
    Customer(int customerId, std::string customerName,std::string customerAdress) : customerId(customerId), customerName(customerName), customerAdress(customerAdress) {}
   
   
    Customer() : customerId(0), customerName(""), customerAdress("") {}

    int getCustomerId() const { return customerId; }
    std::string getCustomerName() const { return customerName; }
    std::string getCustomerAddress() const { return customerAdress; }

    void setCustomerId(int id) { customerId = id; }
    void setCustomerName(const std::string& name) { customerName = name; }
    void setCustomerAddress(const std::string& address) { customerAdress = address; }
}
#endif
