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
