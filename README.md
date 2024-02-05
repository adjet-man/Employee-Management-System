# Introduction 
This program is an employee management system that allows you to perform the following tasks:
    • Add new employees 
    • Display all employees 
    • Save employees data to file 
    • Delete an employee 
    • Edit an employee 
    • Display total number of employees 
# Employee class definition
The Employee class has the following attributes:
    • name: name of the employee (string) 
    • position: position of the employee (string) 
    • startDate: start date of employment (string in dd-mm-yyyy format) 
    • status: status of employment (active, resigned or terminated) (string) 
    • salary: salary of the employee (integer) 
It also has two constructors - a default constructor and a parameterized constructor.
# Functions
The program has several functions that perform various tasks:
# addEmployee()
This function allows you to add a new employee. It takes input from the user for the name, position, start date, status and salary of the employee. It then creates a new Employee object with these attributes and adds it to the vector of employees.
# displayAllEmployees()
This function displays all employees stored in the vector. If there are no employees, it displays a message saying so.
saveToFile()
This function saves all employee data to a file named "employees.txt". It opens the file in write mode and writes each attribute of each employee to a separate line in the file.
# loadFromFile()
This function loads all employee data from the "employees.txt" file into the vector. If there is no such file, it displays a message saying so.
# deleteEmployee()
This function allows you to delete an existing employee based on their name. It takes input from the user for the name of the employee to be deleted, searches for that name in the vector and deletes that element if found.
# editEmployee()
This function allows you to edit an existing employee based on their name. It takes input from the user for the name of the employee to be edited, searches for that name in the vector and prompts the user to enter new values for the position, start date, status and salary attributes of that employee.
# displayTotalEmployees()
This function displays the total number of employees stored in the vector.
# Main function
The main function is where all these functions are called based on user input. It displays a menu with options for each task and prompts the user to enter a choice. It then calls the appropriate function based on that choice. The program continues to run until the user chooses to exit.
