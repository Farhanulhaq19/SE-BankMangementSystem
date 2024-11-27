
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
