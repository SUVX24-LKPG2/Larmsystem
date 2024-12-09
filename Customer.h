#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>

class Customer {
private:
int customerId;
std::string customerName;
std::string adress;
int pin;
int tagId;
std::string verificationPhrase;
static int nextId;
 
public: 
    Customer(int customerId, std::string customerName,std::string adress,int pin, 
    int tagId, std::string verificationPhrase) : customerId(customerId), customerName(customerName), 
    adress(adress), pin(pin), tagId(tagId), verificationPhrase(verificationPhrase)  {}
   
   
    Customer() : customerId(nextId++), customerName(""), adress(""), pin(0), tagId(0), verificationPhrase("")  {}
    ~Customer() {}

    int getId() const { return customerId; }
    std::string getName() const { return customerName; }
    std::string getCity() const { return adress; }
    int getPin() const { return pin; }
    int getTagId() const { return tagId; }
    std::string getVerificationPhrase() const { return verificationPhrase; }

    void setId(int id) { customerId = id; }
    void setName(const std::string& name) { customerName = name; }
    void setCity(const std::string& city) { adress = city; }
    void setPin(int pinCode) { pin = pinCode; }
    void setTagId(int tag) { tagId = tag; }
    void setVerificationPhrase(const std::string& phrase) { verificationPhrase = phrase; }
};

int CustomerId = 1;
#endif
