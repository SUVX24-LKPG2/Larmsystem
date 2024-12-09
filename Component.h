#include <iostream>

class Component{
    private: 
        std::string type;
        std::string name;
        std::string uniqueID;
    public: 
        Component(std::string type, std::string name, std::string uniqueID) : type(type), name(name), uniqueID(uniqueID) {}
};