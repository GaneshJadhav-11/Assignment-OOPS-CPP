#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
private:
    int accountNumber;
    string customerName;
    double balance;
    static int totalAccounts;

public:
    // Parameterized Constructor
    BankAccount(int accNo, string name, double bal)
    {
        accountNumber = accNo;
        customerName = name;
        balance = bal;
        totalAccounts++;
        cout << "\nParameterized Constructor Called";
    }

    // Destructor
    ~BankAccount()
    {
        cout << "\nDestructor Called for Account: "
             << accountNumber;
    }

    // Deposit Function
    void deposit(double amount)
    {
        balance += amount;
    }

    // Withdraw Function
    void withdraw(double amount)
    {
        if (balance >= amount)
            balance -= amount;
        else
            cout << "\nInsufficient Balance!";
    }

    // Static Function
    static void showTotalAccounts()
    {
        cout << "\nTotal Bank Accounts: " << totalAccounts;
    }

    // Friend Function
    friend void displayAccount(BankAccount acc);
};

// Static member initialization
int BankAccount::totalAccounts = 0;

// Friend Function
void displayAccount(BankAccount acc)
{
    cout << "\n---------------------------";
    cout << "\nAccount Number : " << acc.accountNumber;
    cout << "\nCustomer Name  : " << acc.customerName;
    cout << "\nBalance        : " << acc.balance;
    cout << "\n---------------------------";
}

int main()
{
    int n;
    cout << "Enter Number of Customers: ";
    cin >> n;

    // Dynamic allocation of pointer array
    BankAccount **account = new BankAccount*[n];

    int accNo;
    string name;
    double balance;
    double depositAmount;
    double withdrawAmount;

    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter Account Number: ";
        cin >> accNo;

        cout << "Enter Customer Name: ";
        cin >> name;

        cout << "Enter Initial Balance: ";
        cin >> balance;

        // Create object using parameterized constructor
        account[i] = new BankAccount(accNo, name, balance);

        cout << "Enter Deposit Amount: ";
        cin >> depositAmount;
        account[i]->deposit(depositAmount);

        cout << "Enter Withdrawal Amount: ";
        cin >> withdrawAmount;
        account[i]->withdraw(withdrawAmount);
    }

    cout << "\n\nACCOUNT DETAILS";

    for (int i = 0; i < n; i++)
    {
        displayAccount(*account[i]);
    }

    BankAccount::showTotalAccounts();

    // Free memory
    for (int i = 0; i < n; i++)
    {
        delete account[i];
    }

    delete[] account;

    return 0;
}