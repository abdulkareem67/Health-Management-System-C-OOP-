#include <iostream>
using namespace std;

const int SIZE = 100;

string names[SIZE];
int ages[SIZE];
int genders[SIZE]; // 1 for male, 0 for female
string dates[SIZE];
string doctors[SIZE];
int count = 0;

void addRecord() {
    if (count >= SIZE) {
        cout << "Cannot add more records.\n";
        return;
    }

    cout << "Enter name: ";
    cin.ignore();
    getline(cin, names[count]);

    cout << "Enter age: ";
    cin >> ages[count];

    cout << "Enter gender (1=Male, 0=Female): ";
    cin >> genders[count];

    cout << "Enter date (YYYY-MM-DD): ";
    cin >> dates[count];

    cout << "Enter doctor name: ";
    cin.ignore();
    getline(cin, doctors[count]);

    count++;
    cout << "Record added.\n";
}

void viewRecords() {
    if (count == 0) {
        cout << "No records found.\n";
        return;
    }

    for (int i = 0; i < count; i++) {
        cout << "\nRecord " << (i + 1) << ":\n";
        cout << "Name: " << names[i] << "\n";
        cout << "Age: " << ages[i] << "\n";
        cout << "Gender: " << (genders[i] == 1 ? "Male" : "Female") << "\n";
        cout << "Date: " << dates[i] << "\n";
        cout << "Doctor: " << doctors[i] << "\n";
    }
}

void deleteRecord() {
    int index;
    cout << "Enter record number to delete: ";
    cin >> index;
    index--;

    if (index < 0 || index >= count) {
        cout << "Invalid record number.\n";
        return;
    }

    for (int i = index; i < count - 1; i++) {
        names[i] = names[i + 1];
        ages[i] = ages[i + 1];
        genders[i] = genders[i + 1];
        dates[i] = dates[i + 1];
        doctors[i] = doctors[i + 1];
    }

    count--;
    cout << "Record deleted.\n";
}

int main() {
    int choice;

    do {
        cout << "\n--- Health Record System ---\n";
        cout << "1. Add Record\n";
        cout << "2. View Records\n";
        cout << "3. Delete Record\n";
        cout << "4. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        if (choice == 1) {
            addRecord();
        } else if (choice == 2) {
            viewRecords();
        } else if (choice == 3) {
            deleteRecord();
        } else if (choice == 4) {
            cout << "Exiting...\n";
        } else {
            cout << "Invalid option.\n";
        }

    } while (choice != 4);

    return 0;
}
