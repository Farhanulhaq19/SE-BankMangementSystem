
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
