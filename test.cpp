#include "Employee.h"													// Defines class Employee
#include "Map.h"														// Defines template Map<Key, Value>
#include "BookInformations.h"
#include <iostream>

typedef unsigned int ID; 												// Identification number of employee
typedef Map<ID, Employee> Database; 									// Database of employees
typedef string TITLE;
typedef Map<TITLE, BookInformations> Library;

using namespace std;

void testEmployees();
void addEmployees(Database& database);
void modifyEmployees(Database& database);
void testKeyNotFound(Database& database);
void testAddingExisitingKey(Database& database);
void testBooks();
void addBooks(Library& database);
void printBooks(Library& database);


int main() {
    cout << "----- Test Employees -----" << endl;
    testEmployees();

    cout << endl << "----- Test Books -----" << endl;
    testBooks();

    return 0;
};

void testEmployees() {
	Database database;
	addEmployees(database);

	Database newDatabase = database;									// Make a copy of database
	newDatabase.add(830505432, Employee("Ewa Nowak", "charwoman", 43));	// Add fourth employee
	modifyEmployees(newDatabase);

	cout << "Original database:" << endl << database << endl;
	cout << "Modified database:" << endl << newDatabase << endl;

	database = newDatabase;												// Update original database

	cout << "Database after the assignment:" << endl << database << endl;

    testKeyNotFound(database);

    testAddingExisitingKey(database);
}

void addEmployees(Database& database) {
	database.add(761028073, Employee("Jan Kowalski", "salesman", 28)); 	// Add first employee: name: Jan Kowalski, position: salseman, age: 28,
	database.add(510212881, Employee("Adam Nowak", "storekeeper", 54));	// Add second employee
	database.add(730505129, Employee("Anna Zaradna", "secretary", 32));	// Add third employee
}

void modifyEmployees(Database& database) {
	Employee* employeePtr;

	employeePtr = database.find(510212881);								// Find employee using its ID
	employeePtr->position = "salesman";									// Modify the position of employee
	
	employeePtr = database.find(761028073);								// Find employee using its ID
	employeePtr->age = 29;												// Modify the age of employee
}

void testKeyNotFound(Database& database) {
    try {
        cout << database.find(123);
    } catch (KeyNotFoundException& e) {
        cout << e.what() << endl;
    }
}

void testAddingExisitingKey(Database& database) {
    try {
        database.add(761028073, Employee("John Brown", "programmer", 22));
    } catch (KeyExistsException& e) {
        cout << e.what() << endl;
    }
}

void testBooks() {
    Library database;

    addBooks(database);

    printBooks(database);    
}

void addBooks(Library& database) {
    database.add("Lord of The Rings", BookInformations("J.R.R Tolkien", "fantasy", 1128, "availabe"));
    database.add("Witcher", BookInformations("A. Sapkowski", "fantasy", 353, "borrowed"));
    database.add("Symfonia C++", BookInformations("J. Gębosz", "scientific", 1263, "borrowed"));
}

void printBooks(Library& database) {
    cout << database << endl;
}