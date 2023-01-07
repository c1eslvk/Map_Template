#include <iostream>
using namespace std;

class Employee {
    public:
        string fullName;
        string position;
        int age;
        Employee();
        Employee(string fullName, string position, int age);
        Employee(const Employee& other);
        ~Employee();
        Employee& operator=(const Employee& other);
        friend ostream& operator<<(ostream& os, const Employee& emp);
};