#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class BankAccount {
protected:
    string accountNumber;
    string accountHolder;
    double balance;

public:
    BankAccount(string accNum, string accHolder, double initialBalance)
        : accountNumber(accNum), accountHolder(accHolder), balance(initialBalance) {}

    virtual void deposit(double amount) {
        balance += amount;
        cout << "Deposited $" << amount << " into " << accountNumber << endl;
    }

    virtual void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrawn $" << amount << " from " << accountNumber << endl;
        } else {
            cout << "Insufficient balance in " << accountNumber << endl;
        }
    }

    void display() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Balance: $" << balance << endl;
    }
};

class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount(string accNum, string accHolder, double initialBalance, double rate)
        : BankAccount(accNum, accHolder, initialBalance), interestRate(rate) {}

    void applyInterest() {
        double interest = balance * interestRate / 100;
        balance += interest;
        cout << "Interest of $" << interest << " applied to " << accountNumber << endl;
    }

    void withdraw(double amount) override {
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrawn $" << amount << " from " << accountNumber << endl;
        } else {
            cout << "Insufficient balance in " << accountNumber << endl;
        }
    }
};

class CurrentAccount : public BankAccount {
private:
    double overdraftLimit;

public:
    CurrentAccount(string accNum, string accHolder, double initialBalance, double limit)
        : BankAccount(accNum, accHolder, initialBalance), overdraftLimit(limit) {}

    void withdraw(double amount) override {
        if (balance + overdraftLimit >= amount) {
            balance -= amount;
            cout << "Withdrawn $" << amount << " from " << accountNumber << endl;
        } else {
            cout << "Withdrawal limit exceeded for " << accountNumber << endl;
        }
    }
};

class Bank {
private:
    string name;
    map<string, BankAccount*> accounts;

public:
    Bank(string bankName) : name(bankName) {}

    void addAccount(BankAccount* account) {
        accounts[account->accountNumber] = account;
    }

    BankAccount* getAccount(string accountNumber) {
        if (accounts.find(accountNumber) != accounts.end()) {
            return accounts[accountNumber];
        }
        return nullptr;
    }

    void displayAccount(string accountNumber) {
        BankAccount* account = getAccount(accountNumber);
        if (account) {
            account->display();
        } else {
            cout << "Account not found in " << name << endl;
        }
    }
};

int main() {
    Bank BankA("BankA");
    Bank BankB("BankB");

    SavingsAccount savingsA("SA123", "Alice (BankA)", 5000.0, 5.0);
    CurrentAccount currentA("CA456", "Bob (BankA)", 3000.0, 1000.0);
    SavingsAccount savingsB("SA789", "Charlie (BankB)", 8000.0, 4.0);

    BankA.addAccount(&savingsA);
    BankA.addAccount(&currentA);
    BankB.addAccount(&savingsB);

    // Perform transactions for BankA
    cout << "BankA Transactions:" << endl;
    BankA.displayAccount("SA123");
    savingsA.deposit(1000.0);
    savingsA.withdraw(2000.0);
    currentA.withdraw(4000.0);
    BankA.displayAccount("SA123");
    BankA.displayAccount("CA456");

    // Perform transactions for BankB
    cout << "\nBankB Transactions:" << endl;
    BankB.displayAccount("SA789");
    savingsB.deposit(1500.0);
    savingsB.withdraw(3000.0);
    BankB.displayAccount("SA789");

    return 0;
}
