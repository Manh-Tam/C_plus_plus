#pragma once
#include <string>

class BankAccount
{
private:
    int account_number_;
    std::string owner_name_;
    int balance_;
public:
    BankAccount(int account_number, std::string onwer_name, int balance);
    bool deposit(int amount);
    bool widthdraw(int amount);
    int getBalance() const;
};