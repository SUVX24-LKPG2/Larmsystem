#ifndef COMPONENT_H
#define COMPONENT_H
#include <iostream>

class Component{
    private: 
        std::string type;
        std::string name;
        std::string uniqueID;
    public: 
        Component(std::string type, std::string name, std::string uniqueID) : type(type), name(name), uniqueID(uniqueID) {}
        std::string getType() const { return type; }
        std::string getName() const { return name; }
        std::string getUniqueID() const { return uniqueID; }
        void setType(std::string type) { this->type = type; }
        void setName(std::string name) { this->name = name; }
        void setUniqueID(std::string uniqueID) { this->uniqueID = uniqueID; }
        ~Component() {}
};
#endif