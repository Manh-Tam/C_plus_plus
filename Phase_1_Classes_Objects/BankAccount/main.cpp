#include <iostream>

class BankAccount
{
private:
    int balance;
public:
    BankAccount()
    {
        balance = 0;
    }
    BankAccount(int balance)
    {
        this->balance = balance;
    }
    void showBalance()
    {
        std::cout << "Balance: " << balance << std::endl;
    }
    void deposit(int amount)
    {
        balance += amount;
    }
    void widthdraw(int amount)
    {
        balance -= amount;
    }
    ~BankAccount()
    {
        std::cout << "Bank account deleted" << std::endl;
    }
};

int main()
{
    BankAccount bankAccount;
    bankAccount.showBalance();
    bankAccount.deposit(5);
    bankAccount.showBalance();
    bankAccount.widthdraw(3);
    bankAccount.showBalance();
    return 0;
}