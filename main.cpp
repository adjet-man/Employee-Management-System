#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib> 
#include <string>
#include <filesystem> 

using namespace std;

// Employee class definition
class Employee {
    public:
        string name;
        string position;
        string startDate;
        string status;
        int salary;

        // Default constructor
        Employee() {}

        // Parameterized constructor
        Employee(string n, string pos, string start, string stat, int sal) {
            name = n;
            position = pos;
            startDate = start;
            status = stat;
            salary = sal;
        }

        // Print employee details
        void print() {
            cout << "Name: " << name << endl;
            cout << "Position: " << position << endl;
            cout << "Start Date: " << startDate << endl;
            cout << "Status: " << status << endl;
            cout << "Salary: " << salary << endl;
        }
};

// Function to add a new employee
void addEmployee(vector<Employee>& employees) {
    string n, pos, start, stat;
    int sal;

    cout<<"Enter employee name: ";
    getline(cin>>ws, n);
    cout<<"Enter employee position: ";
    getline(cin>>ws, pos);
    cout<<"Enter employee start date (dd-mm-yyyy): ";
    getline(cin>>ws, start);
    cout<<"Enter employee status (active/resigned/terminated): ";
    getline(cin>>ws, stat);

    while (true) {
      cout<<"Enter employee salary (positive integer): ";
      cin>>sal;

      if (sal > 0) break;

      cout<<"Invalid input! Please enter a positive integer."<<endl;  
  }

    Employee e(n, pos, start, stat, sal);
    employees.push_back(e);

    cout<<"Employee added successfully."<<endl;
}

// Function to display all employees
void displayAllEmployees(vector<Employee>& employees) {
    if (employees.size() == 0) {
        cout<<"No employees found!"<<endl;
        return;
    }

    for (int i = 0; i < employees.size(); i++) {
        employees[i].print();
        cout << endl;
    }
}

// Function to save employees data to a file
void saveToFile(vector<Employee>& employees) {
    ofstream outfile;
    outfile.open("employees.txt");

    for (int i = 0; i < employees.size(); i++) {
        outfile << employees[i].name << " ";
        outfile << employees[i].position << " ";
        outfile << employees[i].startDate << " ";
        outfile << employees[i].status << " ";
        outfile << employees[i].salary << endl;
    }

    outfile.close();
    cout<<"Employees data saved to file."<<endl;
}

// Function to load employees data from a file
void loadFromFile(vector<Employee>& employees) {
  if (!std::filesystem::exists("employees.txt")) {
      cout<<"File not found!"<<endl;
      return;
  }

  ifstream infile;
  infile.open("employees.txt");

  string n, pos, start, stat;
  int sal;

  while (infile >> n >> pos >> start >> stat >> sal) {
      Employee e(n, pos, start, stat, sal);
      employees.push_back(e);
  }

  infile.close();
  cout<<"Employees data loaded from file."<<endl;
}

// Function to delete an employee based on their name
void deleteEmployee(vector<Employee>& employees) {
    string nameToDelete;

    if (employees.size() == 0) {
        cout<<"No employees found!"<<endl;
        return;
    }

    cout<<"Enter employee name to delete: ";
    getline(cin>>ws, nameToDelete);

    for (int i = 0; i < employees.size(); i++) {
        if (employees[i].name == nameToDelete) {
            employees.erase(employees.begin() + i);
            cout<<"Employee deleted successfully."<<endl;
            return;
        }
    }

    cout<<"Employee not found!"<<endl;
}

// Function to edit an employee based on their name
void editEmployee(vector<Employee>& employees) {
    string nameToEdit;

    if (employees.size() == 0) {
        cout<<"No employees found!"<<endl;
        return;
    }

    cout<<"Enter employee name to edit: ";
    getline(cin>>ws, nameToEdit);

    for (int i = 0; i < employees.size(); i++) {
        if (employees[i].name == nameToEdit) {
            string pos, start, stat;
            int sal;

            cout<<"Enter new position: ";
            getline(cin>>ws, pos);
            cout<<"Enter new start date (dd-mm-yyyy): ";
            getline(cin>>ws, start);
            cout<<"Enter new status (active/resigned/terminated): ";
            getline(cin>>ws, stat);

            while (true) {
                cout<<"Enter new salary (positive integer): ";
                cin>>sal;

                if (sal > 0) break;

                cout<<"Invalid input! Please enter a positive integer."<<endl;  
            }

            employees[i].position = pos;
            employees[i].startDate = start;
            employees[i].status = stat;
            employees[i].salary = sal;

            cout<<"Employee edited successfully."<<endl;

            return;
        }
    }

    cout<<"Employee not found!"<<endl;
}

// Function to display total number of employees
void displayTotalEmployees(vector<Employee>& employees) {
    cout<<"Total number of employees: "<<employees.size()<<endl;
}

int main() {
    vector<Employee> employees;

    // Load employee data from file (if exists)
    loadFromFile(employees);

    int choice;

    do {
        cout<<endl<<"Employee Management System" 
            <<endl<<"-------------------------" 
            <<endl<<"1. Add new employee" 
            <<endl<<"2. Display all employees" 
            <<endl<<"3. Save employees data to file" 
            <<endl<<"4. Delete an employee"
            <<endl<<"5. Edit an employee"
            <<endl<<"6. Display total number of employees"
            <<endl<<"7. Exit" 
            <<endl<<endl<<"Enter your choice (1-7): ";
        
        cin>>choice;

        switch (choice)
        {
        case 1:
            addEmployee(employees);
            break;

        case 2:
            displayAllEmployees(employees);
            break;

        case 3:
            saveToFile(employees);
            break;

        case 4:
            deleteEmployee(employees);
            break;

        case 5:
          editEmployee(employees);
          break;

      case 6:
          displayTotalEmployees(employees);
          break;

      case 7:
          cout<<"Exiting the program..."<<endl;
          exit(0);
          break;

      default:
          cout<<"Invalid choice! Please enter a valid choice."<<endl;
          break;
      }

  } while (choice != 7);

  return 0;
}