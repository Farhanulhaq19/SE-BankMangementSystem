#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
using namespace std;

const int MAX_ACCOUNTS = 100;

struct Account {
    int accountNumber;
    string name;
    double balance;
    string mobileNumber;
};

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;
int nextAccountNumber = 1001;

bool isValidName(const string& name) {
    for (char c : name) {
        if (!isalpha(c) && c != ' ') {
            return false;
        }
    }
    return true;
}

bool isValidMobileNumber(const string& mobile) {
    if (mobile.length() != 11 || mobile[0] != '0' || mobile[1] != '3') return false;
    for (char c : mobile) {
        if (!isdigit(c)) return false;
    }
    return true;
}

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        cout << "Account limit reached. Cannot create more accounts.\n";
        return;
    }

    Account newAccount;
    newAccount.accountNumber = nextAccountNumber++;

    cout << "Enter the account holder's name: ";
    cin.ignore();
    getline(cin, newAccount.name);
    while (!isValidName(newAccount.name)) {
        cout << "Invalid name. Please enter a valid name:\n";
        getline(cin, newAccount.name);
    }

    bool validMobile = false;
    while (!validMobile) {
        cout << "Enter mobile number (11 digits, starts with 03): ";
        cin >> newAccount.mobileNumber;
        if (!isValidMobileNumber(newAccount.mobileNumber)) {
            cout << "Invalid mobile number. Try again.\n";
        } else {
            validMobile = true;
        }
    }

    cout << "Enter initial deposit amount (minimum 500): ";
    cin >> newAccount.balance;
    while (cin.fail() || newAccount.balance < 500) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid amount. Please enter 500 or more:\n";
        cin >> newAccount.balance;
    }

    accounts[accountCount++] = newAccount;
    cout << "Account created successfully! Account Number: " << newAccount.accountNumber << "\n";
}

void viewAccountDetails(int accountNumber) {
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            cout << "\nAccount Number: " << accounts[i].accountNumber << "\n";
            cout << "Account Holder: " << accounts[i].name << "\n";
            cout << "Mobile Number: " << accounts[i].mobileNumber << "\n";
            cout << "Balance: $" << fixed << setprecision(2) << accounts[i].balance << "\n\n";
            return;
        }
    }
    cout << "Account not found.\n";
}

void deposit(int accountNumber, double amount) {
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            accounts[i].balance += amount;
            cout << "Deposit successful. New balance: $" << fixed << setprecision(2) << accounts[i].balance << "\n";
            return;
        }
    }
    cout << "Account not found.\n";
}

void withdraw(int accountNumber, double amount) {
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            if (accounts[i].balance >= amount) {
                accounts[i].balance -= amount;
                cout << "Withdrawal successful. New balance: $" << fixed << setprecision(2) << accounts[i].balance << "\n";
            } else {
                cout << "Insufficient funds.\n";
            }
            return;
        }
    }
    cout << "Account not found.\n";
}

void transfer(int fromAccount, int toAccount, double amount) {
    int fromIndex = -1, toIndex = -1;
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == fromAccount) fromIndex = i;
        if (accounts[i].accountNumber == toAccount) toIndex = i;
    }

    if (fromIndex == -1 || toIndex == -1) {
        cout << "One or both accounts not found.\n";
        return;
    }

    if (accounts[fromIndex].balance >= amount) {
        accounts[fromIndex].balance -= amount;
        accounts[toIndex].balance += amount;
        cout << "Transfer successful.\n";
    } else {
        cout << "Insufficient funds in source account.\n";
    }
}

void deleteAccount(int accountNumber) {
    int index = -1;
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Account not found.\n";
        return;
    }

    for (int i = index; i < accountCount - 1; i++) {
        accounts[i] = accounts[i + 1];
    }
    accountCount--;
    cout << "Account deleted successfully.\n";
}

void viewAllAccounts() {
    if (accountCount == 0) {
        cout << "No accounts to display.\n";
        return;
    }
    
    for (int i = 0; i < accountCount; i++) {
        cout << "\nAccount Number: " << accounts[i].accountNumber << "\n";
        cout << "Account Holder: " << accounts[i].name << "\n";
        cout << "Mobile Number: " << accounts[i].mobileNumber << "\n";
        cout << "Balance: $" << fixed << setprecision(2) << accounts[i].balance << "\n";
    }
    cout << "\n";
}

void searchAccount(int accountNumber) {
    viewAccountDetails(accountNumber);
}

void displayMenu() {
    cout << "\n1. Create Account\n2. View Account Details\n3. Deposit Money\n4. Withdraw Money\n5. Transfer Funds\n6. Delete Account\n7. View All Accounts\n8. Search Account\n9. Exit\nEnter your choice: ";
}

int main() {
    int choice;
    do {
        displayMenu();
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Enter a number.\n";
            continue;
        }

        int accountNumber, toAccount;
        double amount;
        switch (choice) {
            case 1: createAccount(); break;
            case 2: 
                cout << "Enter account number: ";
                cin >> accountNumber;
                viewAccountDetails(accountNumber); break;
            case 3: 
                cout << "Enter account number: ";
                cin >> accountNumber;
                cout << "Enter amount to deposit: ";
                cin >> amount;
                deposit(accountNumber, amount); break;
            case 4: 
                cout << "Enter account number: ";
                cin >> accountNumber;
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                withdraw(accountNumber, amount); break;
            case 5: 
                cout << "Enter source account number: ";
                cin >> accountNumber;
                cout << "Enter destination account number: ";
                cin >> toAccount;
                cout << "Enter amount to transfer: ";
                cin >> amount;
                transfer(accountNumber, toAccount, amount); break;
            case 6: 
                cout << "Enter account number to delete: ";
                cin >> accountNumber;
                deleteAccount(accountNumber); break;
            case 7: viewAllAccounts(); break;
            case 8: 
                cout << "Enter account number: ";
                cin >> accountNumber;
                searchAccount(accountNumber); break;
            case 9: cout << "Thank you for using the system.\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 9);

    return 0;
}
