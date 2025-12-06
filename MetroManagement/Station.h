#pragma once
#include<iostream>
using namespace std;
/*Class Station
Attributes:
• private: name, location
Methods:
• DisplayInfo()*/
class Station {
protected:
    string name;
    string location;
public:
    //Constructor
    Station(string _name, string _location) {
        set_name(_name);
        set_location(_location);
    }
    //getter and setter
    void set_name(string name) {
        if (name.empty()) throw invalid_argument("Station name cannot be empty!");
        this->name = name;
    }
    void set_location(string location)
    {
        if (location.empty()) throw invalid_argument("Station location cannot be empty!");
        this->location = location;
    }
    string get_name() { return this->name; }
    string get_location() { return this->location; }
    //Display
    void display() {
        cout << "Staion name: " << this->name << endl;
        cout << "Staion location: " << this->location << endl;
    }
};