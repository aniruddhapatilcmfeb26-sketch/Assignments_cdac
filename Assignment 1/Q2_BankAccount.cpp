#include <iostream>
#include <string>

using namespace std;

class BankAccount {
private:
    int accountNumber;
    string accountHolderName;
    double balance;

public:

    BankAccount() : accountNumber(0), accountHolderName(""), balance(0.0) {}

    BankAccount(int accNo, string name, double initialBalance) {
        accountNumber = accNo;
        accountHolderName = name;
        balance = initialBalance;
    }

    int getAccountNumber() const { return accountNumber; }
    string getAccountHolderName() const { return accountHolderName; }
    double getBalance() const { return balance; }

    void setAccountNumber(int accNo) { accountNumber = accNo; }
    void setAccountHolderName(const string& name) { accountHolderName = name; }
    void setBalance(double b) { balance = b; }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Successfully deposited Rs." << amount << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && balance >= amount) {
            balance -= amount;
            cout << "Successfully withdrew Rs." << amount << endl;
        } else if (amount > balance) {
            cout << "Insufficient balance! Your current balance is Rs." << balance << endl;
        } else {
            cout << "Invalid withdrawal amount!" << endl;
        }
    }

    void displayAccountDetails() const {
        cout << "\n--- Account Details ---" << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Balance: Rs." << balance << endl;
        cout << "-----------------------" << endl;
    }
};

int main() {
    BankAccount account;
    int choice;
    double amount;

    account.setAccountNumber(101102);
    account.setAccountHolderName("Anirudh Patil");
    account.setBalance(5000.0);

    do {
        cout << "\n--- Bank Menu ---\n";
        cout << "1. Deposit Money\n";
        cout << "2. Withdraw Money\n";
        cout << "3. Display Account Details\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter deposit amount: ";
                cin >> amount;
                account.deposit(amount);
                break;
            case 2:
                cout << "Enter withdrawal amount: ";
                cin >> amount;
                account.withdraw(amount);
                break;
            case 3:
                account.displayAccountDetails();
                break;
            case 4:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Please select between 1 and 4." << endl;
        }
    } while (choice != 4);

    return 0;
}
