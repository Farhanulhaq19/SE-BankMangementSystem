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
