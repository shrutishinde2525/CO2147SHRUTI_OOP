#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
private:
    int accountNumber;
    string accountHolderName;
    double accountBalance;
    string accountType;

    static int accountCount;

public:

    // Constructor using this pointer
    BankAccount(int accountNumber, string accountHolderName,
                double accountBalance, string accountType)
    {
        this->accountNumber = accountNumber;
        this->accountHolderName = accountHolderName;
        this->accountBalance = accountBalance;
        this->accountType = accountType;

        accountCount++;

        cout << "\n[Constructor Called - Account Created]" << endl;
    }

    // Function to display account details
    void display()
    {
        cout << "\n----- Bank Account Details -----" << endl;
        cout << "Account Number     : " << accountNumber << endl;
        cout << "Account Holder     : " << accountHolderName << endl;
        cout << "Account Balance    : " << accountBalance << endl;
        cout << "Account Type       : " << accountType << endl;
    }

    // Static function
    static void displayAccountCount()
    {
        cout << "\n[Static Function Called]" << endl;
        cout << "Total Accounts Created : " << accountCount << endl;
    }

    // Friend function declaration
    friend void compareBalance(BankAccount a1, BankAccount a2);

    // Inline function
    inline void calculateInterest(double rate, double time)
    {
        double interest;

        interest = accountBalance * rate * time / 100;
        accountBalance = accountBalance + interest;

        cout << "\n[Inline Function Called]" << endl;
        cout << "Interest Rate      : " << rate << "%" << endl;
        cout << "Time Period        : " << time << " years" << endl;
        cout << "Interest Earned    : " << interest << endl;
        cout << "Updated Balance    : " << accountBalance << endl;
    }
};

// Definition of static data member
int BankAccount::accountCount = 0;


// Friend Function
void compareBalance(BankAccount a1, BankAccount a2)
{
    cout << "\n[Friend Function Called]" << endl;

    cout << "Balance of Account 1 : " << a1.accountBalance << endl;
    cout << "Balance of Account 2 : " << a2.accountBalance << endl;

    if (a1.accountBalance > a2.accountBalance)
    {
        cout << "Account 1 has higher balance." << endl;
    }
    else if (a2.accountBalance > a1.accountBalance)
    {
        cout << "Account 2 has higher balance." << endl;
    }
    else
    {
        cout << "Both accounts have equal balance." << endl;
    }
}


int main()
{
    cout << "========================================" << endl;
    cout << "     BANK ACCOUNT MANAGEMENT SYSTEM" << endl;
    cout << "========================================" << endl;


    // Creating first account
    cout << "\n1. CREATING ACCOUNT 1" << endl;

    BankAccount account1(101, "Aliya", 50000, "Savings");

    account1.display();


    // Creating second account
    cout << "\n2. CREATING ACCOUNT 2" << endl;

    BankAccount account2(102, "Taha", 75000, "Current");

    account2.display();


    // Calculate interest using inline function
    cout << "\n3. CALCULATING INTEREST FOR ACCOUNT 1" << endl;

    account1.calculateInterest(5, 2);


    // Display updated account
    cout << "\nUpdated Account 1 Details:";
    account1.display();


    // Compare balances using friend function
    cout << "\n4. COMPARING ACCOUNT BALANCES" << endl;

    compareBalance(account1, account2);


    // Display total accounts using static function
    cout << "\n5. DISPLAYING TOTAL ACCOUNT COUNT" << endl;

    BankAccount::displayAccountCount();


    cout << "\n========================================" << endl;
    cout << "Program Completed Successfully." << endl;
    cout << "========================================" << endl;

    return 0;
}
