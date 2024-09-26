#include <iostream>
#include <fstream>
//#include <sstream>
//#include <string>

using namespace std;

const string FILE_NAME = "bank_records.txt";

struct Record {
    string account_number;
    string name;
    float balance;
};

void addRecord() {
    Record record;
    cout << "Enter account holder's name: ";
    cin >> record.name;
    cout << "Enter account number: ";
    cin >> record.account_number;
    cout << "Enter account balance: ";
    cin >> record.balance;

    ofstream file(FILE_NAME, ios::app);
    if (file.is_open()) {
        file << record.account_number << "," << record.name << "," << record.balance << endl;
        cout << "Record added successfully!" << endl;
    } else {
        cout << "Error opening file!" << endl;
    }
    file.close();
}

void showRecords() {
    ifstream file(FILE_NAME);
    if (!file) {
        cout << "No records found." << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        Record record;
        getline(ss, record.account_number, ',');
        getline(ss, record.name, ',');
        ss >> record.balance;

        cout << "Account Number: " << record.account_number
             << ", Name: " << record.name
             << ", Balance: " << record.balance << endl;
    }
    file.close();
}

void searchRecord() {
    string account_number;
    cout << "Enter account number to search: ";
    cin >> account_number;

    ifstream file(FILE_NAME);
    if (!file) {
        cout << "No records found." << endl;
        return;
    }

    string line;
    bool found = false;
    while (getline(file, line)) {
        if (line.substr(0, line.find(',')) == account_number) {
            stringstream ss(line);
            Record record;
            getline(ss, record.account_number, ',');
            getline(ss, record.name, ',');
            ss >> record.balance;

            cout << "Account Number: " << record.account_number
                 << ", Name: " << record.name
                 << ", Balance: " << record.balance << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Record not found." << endl;
    }
    file.close();
}

void editRecord() {
    string account_number;
    cout << "Enter account number to edit: ";
    cin >> account_number;

    ifstream file(FILE_NAME);
    if (!file) {
        cout << "No records found." << endl;
        return;
    }

    ofstream tempFile("temp.txt");
    string line;
    bool found = false;

    while (getline(file, line)) {
        if (line.substr(0, line.find(',')) == account_number) {
            Record record;
            getline(file, record.account_number, ',');
            getline(file, record.name, ',');
            file >> record.balance;

            cout << "Editing record for account number: " << account_number << endl;
            cout << "Enter new name: ";
            cin >> record.name;
            cout << "Enter new balance: ";
            cin >> record.balance;

            tempFile << record.account_number << "," << record.name << "," << record.balance << endl;
            cout << "Record updated successfully!" << endl;
            found = true;
        } else {
            tempFile << line << endl;
        }
    }

    file.close();
    tempFile.close();
    remove(FILE_NAME.c_str());
    rename("temp.txt", FILE_NAME.c_str());

    if (!found) {
        cout << "Record not found." << endl;
    }
}

void deleteRecord() {
    string account_number;
    cout << "Enter account number to delete: ";
    cin >> account_number;

    ifstream file(FILE_NAME);
    if (!file) {
        cout << "No records found." << endl;
        return;
    }

    ofstream tempFile("temp.txt");
    string line;
    bool found = false;

    while (getline(file, line)) {
        if (line.substr(0, line.find(',')) != account_number) {
            tempFile << line << endl;
        } else {
            found = true;
            cout << "Record deleted successfully!" << endl;
        }
    }

    file.close();
    tempFile.close();
    remove(FILE_NAME.c_str());
    rename("temp.txt", FILE_NAME.c_str());

    if (!found) {
        cout << "Record not found." << endl;
    }
}

int main() {
    while (true) {
        cout << "\nBanking Record System" << endl;
        cout << "1. Add Record" << endl;
        cout << "2. Show/List Data" << endl;
        cout << "3. Search Record" << endl;
        cout << "4. Edit Record" << endl;
        cout << "5. Delete Record" << endl;
        cout << "6. Exit" << endl;

        int choice;
        cout << "Choose an operation: ";
        cin >> choice;

        switch (choice) {
            case 1: addRecord(); break;
            case 2: showRecords(); break;
            case 3: searchRecord(); break;
            case 4: editRecord(); break;
            case 5: deleteRecord(); break;
            case 6: cout << "Exiting..." << endl; return 0;
            default: cout << "Invalid choice. Please try again." << endl; break;
        }
    }

    return 0;
}