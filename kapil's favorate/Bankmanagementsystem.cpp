#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Account
{
public:
    string name;
    int acc_no;
    double balance;
    string acc_type;
    Account(int acc_no, string name, double balance, string acc_type)
    {
        this->acc_no = acc_no;
        this->name = name;
        this->balance = balance;
        this->acc_type = acc_type;
    }
    virtual void Display()
    {
        cout << "Account_No : " << acc_no << endl
             << "Name : " << name << endl
             << "Balance : " << balance << endl
             << "Account_Type : " << acc_type << endl;
    }
};

class Member
{
public:
    string member_name, member_job;
    Member(string member_name, string member_job)
    {
        this->member_name = member_name;
        this->member_job = member_job;
    }
    void Display()
    {
        cout << "Member_Name : " << member_name << endl
             << "Member_Job : " << member_job << endl;
    }
};

class Bank
{
public:
    vector<Account> Accounts;
    vector<Member> Members;
    void AddBankAccount(int acc_no, string name, double balance, string acc_type)
    {
        Accounts.push_back(Account(acc_no, name, balance, acc_type));
        cout << "Your Account added successfully." << endl;
    }
    void ShowAccounts()
    {
        for (auto &account : Accounts)
        {
            account.Display();
        }
    }
    void FindAccount(string name, int acc_no)
    {
        bool found3 = false;
        for (auto &account : Accounts)
        {
            if (account.name == name && account.acc_no == acc_no)
            {
                account.Display();
                found3 = true;
            }
        }
        if (!found3)
        {
            cout << "This account is not found." << endl;
        }
    }
    void AddMember(string member_name, string member_job)
    {
        Members.push_back(Member(member_name, member_job));
        cout << "Now you are the member of our bank.Your job details will be send to you through your Mail. " << endl;
    }
    void ShowMembers()
    {
        for (auto &member : Members)
        {
            member.Display();
        }
    }
    void DepositMoney(int acc_no, float amount)
    {
        bool found2 = false;
        for (auto &account : Accounts)
        {
            if (account.acc_no == acc_no)
            {
                account.balance += amount;
                found2 = true;
                cout << "Your money is credited to your account successfully." << endl
                     << "Your Total_Balance : " << account.balance << endl;
            }
        }
        if (!found2)
        {
            cout << "This account is not found." << endl;
        }
    }
    void WithdrawMoney(int acc_no, float amount)
    {
        bool found1 = false;
        for (auto &account : Accounts)
        {
            if (account.acc_no == acc_no)
            {
                account.balance -= amount;
                found1 = true;
                cout << "Your money is withdrawn successfully." << endl
                     << "Your Total_Balance : " << account.balance << endl;
            }
        }
        if (!found1)
        {
            cout << "This account is not found." << endl;
        }
    }
    void CheckBalance(int acc_no, string acc_type)
    {
        bool found = false;
        for (auto &account : Accounts)
        {

            if (account.acc_no == acc_no && account.acc_type == acc_type)
            {
                cout << "Your Total_Balance : " << account.balance << endl;
                found = true;
            }
        }
        if (!found)
        {
            cout << "This account is not found." << endl;
        }
    }
};
int main()
{
    Bank bank;
    int choice;

    do
    {
        cout << "\n=== BANK MANAGEMENT SYSTEM MENU ===\n";
        cout << "1. Add Bank Account\n";
        cout << "2. Show All Accounts\n";
        cout << "3. Find an Account\n";
        cout << "4. Add Bank Member\n";
        cout << "5. Show All Members\n";
        cout << "6. Deposit Money\n";
        cout << "7. Withdraw Money\n";
        cout << "8. Check Balance\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int acc_no;
            string name, acc_type;
            double balance;
            cout << "Enter Account Number: ";
            cin >> acc_no;
            cin.ignore();
            cout << "Enter Name: ";
            getline(cin, name);
            cout << "Enter Balance: ";
            cin >> balance;
            cout << "Enter Account Type: ";
            cin >> acc_type;
            bank.AddBankAccount(acc_no, name, balance, acc_type);
            break;
        }
        case 2:
            bank.ShowAccounts();
            break;
        case 3:
        {
            int acc_no;
            string name;
            cout << "Enter Account Number: ";
            cin >> acc_no;
            cin.ignore();
            cout << "Enter Name: ";
            getline(cin, name);
            bank.FindAccount(name, acc_no);
            break;
        }
        case 4:
        {
            string name, job;
            cin.ignore();
            cout << "Enter Member Name: ";
            getline(cin, name);
            cout << "Enter Member Job: ";
            getline(cin, job);
            bank.AddMember(name, job);
            break;
        }
        case 5:
            bank.ShowMembers();
            break;
        case 6:
        {
            int acc_no;
            float amount;
            string name;
            cout << "Enter Account Number: ";
            cin >> acc_no;
            cin.ignore();
            cout << "Enter Name: ";
            getline(cin, name);
            cout << "Enter Amount to Deposit: ";
            cin >> amount;
            bank.DepositMoney(acc_no, amount);
            break;
        }
        case 7:
        {
            int acc_no;
            float amount;
            string name;
            cout << "Enter Account Number: ";
            cin >> acc_no;
            cin.ignore();
            cout << "Enter Name: ";
            getline(cin, name);
            cout << "Enter Amount to Withdraw: ";
            cin >> amount;
            bank.WithdrawMoney(acc_no,amount);
            break;
        }
        case 8:
        {
            int acc_no;
            string acc_type, name;
            cout << "Enter Account Number: ";
            cin >> acc_no;
            cin.ignore();
            cout << "Enter Name: ";
            getline(cin, name);
            cout << "Enter Account Type: ";
            cin >> acc_type;
            bank.CheckBalance(acc_no, acc_type);
            break;
        }
        case 9:
            cout << "Thank you for using the Bank Management System.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 9);

    return 0;
}
