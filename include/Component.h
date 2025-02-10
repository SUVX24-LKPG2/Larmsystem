#ifndef COMPONENT_H
#define COMPONENT_H
#include <iostream>
#include <utility>

class Component
{
    std::string type;
    std::string name;
    std::string uniqueID;

public:
    Component(std::string type, std::string name, std::string uniqueID)
        : type(std::move(type)), name(std::move(name)), uniqueID(std::move(uniqueID))
    {
    }
    Component()
    {
        type     = "";
        name     = "";
        uniqueID = "";
    }
    std::string getType() const { return type; }
    std::string getName() const { return name; }
    std::string getUniqueID() const { return uniqueID; }
    void setType(const std::string& type) { this->type = type; }
    void setName(const std::string& name) { this->name = name; }
    void setUniqueID(const std::string& uniqueID) { this->uniqueID = uniqueID; }
    ~Component() = default;
};
#endif