#include <iostream>
#include <vector>
using namespace std;

struct Expense {
    int id;
    string description;
    string category;
    double amount;
};

vector<Expense> expenses;

void addExpense() {
    Expense e;

    cout << "Enter ID: ";
    cin >> e.id;

    for (const auto& x : expenses) {
        if (x.id == e.id) {
            cout << "ID already exists.\n";
            return;
        }
    }

    cout << "Enter description: ";
    cin >> e.description;

    cout << "Enter category: ";
    cin >> e.category;

    if (e.category.empty()) {
        cout << "Category cannot be empty.\n";
        return;
    }

    cout << "Enter amount: ";
    cin >> e.amount;

    if (e.amount <= 0) {
        cout << "Amount must be greater than 0.\n";
        return;
    }

    expenses.push_back(e);
    cout << "Expense added successfully.\n";
}

void viewAllExpenses() {
    if (expenses.empty()) {
        cout << "No expenses found.\n";
        return;
    }

    for (const auto& e : expenses) {
        cout << e.id << " | "
             << e.description << " | "
             << e.category << " | "
             << e.amount << "\n";
    }
}

void searchByCategory() {
    string category;
    cout << "Enter category: ";
    cin >> category;

    bool found = false;

    for (const auto& e : expenses) {
        if (e.category == category) {
            cout << e.id << " | "
                 << e.description << " | "
                 << e.amount << "\n";
            found = true;
        }
    }

    if (!found)
        cout << "No expenses found for this category.\n";
}

void updateAmount() {
    int id;
    double amount;

    cout << "Enter ID: ";
    cin >> id;

    for (auto& e : expenses) {
        if (e.id == id) {
            cout << "Enter new amount: ";
            cin >> amount;

            if (amount <= 0) {
                cout << "Amount must be greater than 0.\n";
                return;
            }

            e.amount = amount;
            cout << "Amount updated successfully.\n";
            return;
        }
    }

    cout << "Expense not found.\n";
}

void deleteExpense() {
    int id;
    cout << "Enter ID: ";
    cin >> id;

    for (auto it = expenses.begin(); it != expenses.end(); ++it) {
        if (it->id == id) {
            expenses.erase(it);
            cout << "Expense deleted successfully.\n";
            return;
        }
    }

    cout << "Expense not found.\n";
}

void calculateTotal() {
    double total = 0;

    for (const auto& e : expenses)
        total += e.amount;

    cout << "Total expenses: " << total << "\n";
}

void findHighestExpense() {
    if (expenses.empty()) {
        cout << "No expenses found.\n";
        return;
    }

    const Expense* highest = &expenses[0];

    for (const auto& e : expenses) {
        if (e.amount > highest->amount)
            highest = &e;
    }

    cout << "Highest expense: "
         << highest->description << " | "
         << highest->amount << "\n";
}

int main() {
    int choice;

    do {
        cout << "\n1. Add Expense\n";
        cout << "2. View All\n";
        cout << "3. Search by Category\n";
        cout << "4. Update Amount\n";
        cout << "5. Delete Expense\n";
        cout << "6. Calculate Total\n";
        cout << "7. Highest Expense\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addExpense(); break;
            case 2: viewAllExpenses(); break;
            case 3: searchByCategory(); break;
            case 4: updateAmount(); break;
            case 5: deleteExpense(); break;
            case 6: calculateTotal(); break;
            case 7: findHighestExpense(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}