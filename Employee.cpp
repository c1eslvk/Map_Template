#include <iostream>
#include "Employee.h"
using namespace std;

Employee::Employee() {
    fullName = "";
    position = "";
    age = 0;
}

Employee::Employee(string fullName, string position, int age) {
    this->fullName = fullName;
    this->position = position;
    this->age = age;
}

Employee::Employee(const Employee& other) {
    fullName = other.fullName;
    position = other.position;
    age = other.age;
}

Employee::~Employee() {}

Employee& Employee::operator=(const Employee& other) {
    if (this != &other) {
        fullName = other.fullName;
        position = other.position;
        age = other.age;
    }
    return *this;    
}

ostream& operator<<(ostream& os, const Employee& emp) {
    os << "name: " << emp.fullName << ", position: " << emp.position << ", age: " << emp.age;
    return os;
}