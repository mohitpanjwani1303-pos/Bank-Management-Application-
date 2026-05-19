#include "BankAccount.h"
#include <cstring>

void BankAccount::createAccount() {
    cout << "Enter Account Number: ";
    cin >> accountNumber;

    cin.ignore();

    cout << "Enter Account Holder Name: ";
    cin.getline(name, 50);

    cout << "Enter Initial Balance: ";
    cin >> balance;
}

void BankAccount::displayAccount() const {
    cout << "\nAccount Number : " << accountNumber;
    cout << "\nAccount Holder : " << name;
    cout << "\nBalance        : " << balance << endl;
}

void BankAccount::deposit(float amount) {
    balance += amount;
    cout << "Amount Deposited Successfully.\n";
}

void BankAccount::withdraw(float amount) {
    if (amount > balance) {
        cout << "Insufficient Balance!\n";
    } else {
        balance -= amount;
        cout << "Amount Withdrawn Successfully.\n";
    }
}

int BankAccount::getAccountNumber() const {
    return accountNumber;
}

float BankAccount::getBalance() const {
    return balance;
}
