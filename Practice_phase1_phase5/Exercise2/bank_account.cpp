#include "bank_account.hpp"
#include <iostream>

BankAccount::BankAccount(int account_number, std::string owner_name, int balance)
{
    /*if the rule is that account_number should have 12 digits.*/
    /*Where do I implement a function to check it?*/
    /*Constructors are like setters, should I pass const type& for every member?*/
    /*I think const type for primitive types*/
    /*and const type& for large size type like string*/
    if (account_number < 0)
    {
        throw std::invalid_argument("Account number cannot be negative");
    }
    else if (owner_name.length() < 0)
    {
        throw std::invalid_argument("Onwer name cannot be empty");
    }
    else if (balance < 0)
    {
        throw std::invalid_argument("Balance cannot be negative");
    }
    else
    {
        account_number_ = account_number;
        owner_name_ = owner_name;
        balance_ = balance;
    }
}
bool BankAccount::deposit(int amount)
{
    bool ret = false;
    if (amount > 0)
    {
        balance_ += amount;
        ret = true;
    }
    return ret;
}
bool BankAccount::widthdraw(int amount)
{
    bool ret = false;
    if (balance_ - amount >= 0)
    {
        balance_ -= amount;
        ret = true;
    }
    return ret;
}
int BankAccount::getBalance() const
{
    return balance_;
}
