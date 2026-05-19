#include <iostream>
#include "FileManager.h"

using namespace std;

int main() {

    int choice;
    int accNo;

    do {
        cout << "\n===== BANK MANAGEMENT SYSTEM =====\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Amount\n";
        cout << "3. Withdraw Amount\n";
        cout << "4. Balance Inquiry\n";
        cout << "5. Exit\n";

        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            writeAccount();
            break;

        case 2:
            cout << "Enter Account Number: ";
            cin >> accNo;
            modifyAccount(accNo, 1);
            break;

        case 3:
            cout << "Enter Account Number: ";
            cin >> accNo;
            modifyAccount(accNo, 2);
            break;

        case 4:
            cout << "Enter Account Number: ";
            cin >> accNo;
            displayAccount(accNo);
            break;

        case 5:
            cout << "Thank You for Using Bank Management System.\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 5);

    return 0;
}
