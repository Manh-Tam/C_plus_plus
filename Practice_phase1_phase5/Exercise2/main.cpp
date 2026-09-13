#include <iostream>
#include "bank_account.hpp"

/*BankAccount& uses from directly, not a copy of from*/
void transfer(BankAccount& from, BankAccount& to, int amount)
{
    if (amount > 0)
    {
        if (from.widthdraw(amount))
        {
            if (to.deposit(amount))
            {
                std::cout << "Transfered $" << amount << std::endl; 
            }
        }
    }
}

int main()
{
    BankAccount from(1234, "Tam1", 50);
    BankAccount to(5670, "Tam2", 20);
    transfer(from, to, 30);
    std::cout << "From balance " << from.getBalance() << std::endl;
    std::cout << "To balance " << to.getBalance() << std::endl;
    return 0;
}