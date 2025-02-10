#include "Customer.h"

#include <string>
#include <utility>

Customer::Customer(std::string customerName, std::string address, int pin, int tagId,
                   std::string verificationPhrase)
    : customerName(std::move(customerName)),
      address(std::move(address)),
      pin(pin),
      tagId(tagId),
      verificationPhrase(std::move(verificationPhrase))
{
}

Customer::Customer() : customerName(""), address(""), pin(0), tagId(0), verificationPhrase("") {}

Customer::~Customer() = default;

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
