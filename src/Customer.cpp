#include "Customer.h"

#include <string>

Customer::Customer(std::string customerName, std::string address, int pin, int tagId,
                   std::string verificationPhrase)
    : customerName(customerName),
      address(address),
      pin(pin),
      tagId(tagId),
      verificationPhrase(verificationPhrase)
{
}

Customer::Customer() : customerName(""), address(""), pin(0), tagId(0), verificationPhrase("") {}

Customer::~Customer() {}

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
    return address;
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
    address = city;
}

void Customer::setPin(int pinCode)
{
    pin = pinCode;
}

void Customer::setTagId(int tag)
{
    tagId = tag;
}

void Customer::setVerificationPhrase(const std::string& phrase)
{
    verificationPhrase = phrase;
}
