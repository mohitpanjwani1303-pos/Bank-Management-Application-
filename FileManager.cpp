#include "FileManager.h"
#include <fstream>

void writeAccount() {
    BankAccount acc;

    ofstream outFile("accounts.dat", ios::binary | ios::app);

    acc.createAccount();

    outFile.write(reinterpret_cast<char*>(&acc), sizeof(acc));

    outFile.close();

    cout << "Account Created Successfully.\n";
}

void displayAccount(int accNo) {
    BankAccount acc;
    bool found = false;

    ifstream inFile("accounts.dat", ios::binary);

    while (inFile.read(reinterpret_cast<char*>(&acc), sizeof(acc))) {
        if (acc.getAccountNumber() == accNo) {
            acc.displayAccount();
            found = true;
        }
    }

    inFile.close();

    if (!found) {
        cout << "Account Not Found.\n";
    }
}

void modifyAccount(int accNo, int option) {
    BankAccount acc;

    fstream file("accounts.dat", ios::binary | ios::in | ios::out);

    bool found = false;

    while (!file.eof() && !found) {

        streampos pos = file.tellg();

        file.read(reinterpret_cast<char*>(&acc), sizeof(acc));

        if (acc.getAccountNumber() == accNo) {

            acc.displayAccount();

            float amt;

            if (option == 1) {
                cout << "\nEnter Amount to Deposit: ";
                cin >> amt;
                acc.deposit(amt);
            }
            else if (option == 2) {
                cout << "\nEnter Amount to Withdraw: ";
                cin >> amt;
                acc.withdraw(amt);
            }

            file.seekp(pos);

            file.write(reinterpret_cast<char*>(&acc), sizeof(acc));

            cout << "Record Updated Successfully.\n";

            found = true;
        }
    }

    file.close();

    if (!found) {
        cout << "Account Not Found.\n";
    }
}
