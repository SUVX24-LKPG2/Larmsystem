#include "Customer.h"

int Customer::nextId = 1;

Customer::Customer(int customerId, std::string customerName, std::string adress,int pin, int tagId, std::string verificationPhrase)
    : customerId(customerId), customerName(customerName), adress(adress),
      pin(0), tagId(tagId), verificationPhrase(verificationPhrase) {}

Customer::Customer()
    : customerId(nextId++), customerName(""), adress(""), pin(0), tagId(0), verificationPhrase("") {}

int Customer::getId() const
{
    return customerId;
}

std::string Customer::getName() const
{

    return customerName;
}

std::string Customer::getCity() const
{
    return adress;
}

int Customer::getPin() const
{
    return pin;
}
int Customer::getTagId() const 
{
    return tagId;
}
std::string Customer::getVerificationPhrase() const 
{
    return verificationPhrase;
}

void Customer::setId(int id) 
{
    customerId = id;
}

void Customer::setName(const std::string& name) 
{
    customerName = name;
}

void Customer::setCity(const std::string& city) 
{
    adress = city;
}

void Customer::setPin(int pinCode) 
{
    pin = pinCode;
}

void Customer::setTagId(int tag) 
{
    tagId = tag;
}

void Customer::setCity(const std::string& phrase) 
{
    verificationPhrase = phrase;
}

