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
    Customer(int customerId, std::string customerName,std::string adress,int pin, int tagId, std::string verificationPhrase); 
    Customer(); 
    ~Customer();

    int getId() const; 
    std::string getName() const; 
    std::string getCity() const;
    int getPin() const;
    int getTagId() const;
    std::string getVerificationPhrase() const;

    void setId(int id);
    void setName(const std::string& name);
    void setCity(const std::string& city);
    void setPin(int pinCode);
    void setTagId(int tag);
    void setVerificationPhrase(const std::string& phrase);
};
#endif
