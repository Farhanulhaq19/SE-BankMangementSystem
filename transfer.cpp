ransfer(int fromAccount, int toAccount, double amount) {
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
