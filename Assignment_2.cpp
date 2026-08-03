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

    BankAccount(int accNo, string name, double bal)
    {
        accountNumber = accNo;
        customerName = name;
        balance = bal;
        totalAccounts++;
        cout << "\nParameterized Constructor Called";
    }

    
    ~BankAccount()
    {
        cout << "\nDestructor Called for Account: "
             << accountNumber;
    }

    
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

    
    static void showTotalAccounts()
    {
        cout << "\nTotal Bank Accounts: " << totalAccounts;
    }

    
    friend void displayAccount(BankAccount acc);
};


int BankAccount::totalAccounts = 0;

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

    
    for (int i = 0; i < n; i++)
    {
        delete account[i];
    }

    delete[] account;

    return 0;
}







// Output:
// Enter Number of Customers: 1

// Enter Account Number: 1
// Enter Customer Name: Ganesh
// Enter Initial Balance: 1000

// Parameterized Constructor CalledEnter Deposit Amount: 200
// Enter Withdrawal Amount: 100


// ACCOUNT DETAILS
// ---------------------------
// Account Number : 1
// Customer Name  : Ganesh
// Balance        : 1100
// ---------------------------
// Destructor Called for Account: 1
// Total Bank Accounts: 1
// Destructor Called for Account: 1
