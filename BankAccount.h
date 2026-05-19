#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <iostream>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    char name[50];
    float balance;

public:
    void createAccount();
    void displayAccount() const;

    void deposit(float amount);
    void withdraw(float amount);

    int getAccountNumber() const;
    float getBalance() const;
};

#endif
