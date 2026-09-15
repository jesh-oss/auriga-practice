#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Employee {
    int id;
    string name;
    string department;
    double salary;
};

vector<Employee> employees;

void addEmployee() {
    Employee e;

    cout << "Enter ID: ";
    cin >> e.id;

    for (const auto& emp : employees) {
        if (emp.id == e.id) {
            cout << "ID already exists.\n";
            return;
        }
    }

    cout << "Enter name: ";
    cin >> e.name;

    cout << "Enter department: ";
    cin >> e.department;

    cout << "Enter salary: ";
    cin >> e.salary;

    if (e.salary <= 0) {
        cout << "Salary must be greater than 0.\n";
        return;
    }

    employees.push_back(e);
    cout << "Employee added successfully.\n";
}

void searchEmployee() {
    int id;
    cout << "Enter ID: ";
    cin >> id;

    for (const auto& e : employees) {
        if (e.id == id) {
            cout << e.id << " " << e.name << " "
                 << e.department << " " << e.salary << "\n";
            return;
        }
    }

    cout << "Employee not found.\n";
}

void deleteEmployee() {
    int id;
    cout << "Enter ID: ";
    cin >> id;

    auto it = find_if(employees.begin(), employees.end(),
                      [id](const Employee& e) {
                          return e.id == id;
                      });

    if (it != employees.end()) {
        employees.erase(it);
        cout << "Employee deleted.\n";
    } else {
        cout << "Employee not found.\n";
    }
}

void updateSalary() {
    int id;
    double salary;

    cout << "Enter ID: ";
    cin >> id;

    for (auto& e : employees) {
        if (e.id == id) {
            cout << "Enter new salary: ";
            cin >> salary;

            if (salary <= 0) {
                cout << "Salary must be greater than 0.\n";
                return;
            }

            e.salary = salary;
            cout << "Salary updated.\n";
            return;
        }
    }

    cout << "Employee not found.\n";
}

void displayAll() {
    for (const auto& e : employees) {
        cout << e.id << " | "
             << e.name << " | "
             << e.department << " | "
             << e.salary << "\n";
    }
}

void sortBySalary() {
    sort(employees.begin(), employees.end(),
         [](const Employee& a, const Employee& b) {
             return a.salary > b.salary;
         });

    displayAll();
}

int main() {
    int choice;

    do {
        cout << "\n1. Add\n";
        cout << "2. Search\n";
        cout << "3. Delete\n";
        cout << "4. Update Salary\n";
        cout << "5. Display All\n";
        cout << "6. Sort by Salary\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: searchEmployee(); break;
            case 3: deleteEmployee(); break;
            case 4: updateSalary(); break;
            case 5: displayAll(); break;
            case 6: sortBySalary(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}