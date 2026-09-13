This is a **solid attempt**. More importantly, I can see you're starting to think about the right things: ownership of references, invariants, constructor validation, parameter passing, and transactional behavior.

I'd give it **7/10** for the exercise, with a few important bugs to fix.

## 1. What you did well ✅

### Encapsulation

Good:

```cpp
private:
    int account_number_;
    std::string owner_name_;
    int balance_;
```

The outside world can't directly manipulate the balance.

That's exactly what we wanted.

---

### `transfer()` uses references correctly

Your comment is correct:

```cpp
void transfer(BankAccount& from, BankAccount& to, int amount)
```

`from` and `to` refer to the existing objects.

So:

```cpp
transfer(from, to, 30);
```

doesn't create copies.

Your mental model is correct:

```text
from ──────────┐
               ▼
        original BankAccount

to ────────────┐
               ▼
        original BankAccount
```

---

### `deposit()` protects the invariant

```cpp
if (amount > 0)
{
    balance_ += amount;
    ret = true;
}
```

Good.

You're preventing:

```cpp
deposit(-100);
```

from corrupting the account.

---

### Withdrawal checks the balance

You correctly don't allow the account to go negative:

```cpp
if (balance_ - amount >= 0)
```

The intention is right.

However, there's an important bug here that we'll fix below.

---

# 2. Important bug: empty string check ❌

You wrote:

```cpp
else if (owner_name.length() < 0)
```

This can **never be true**.

`length()` returns an unsigned size type, so its value cannot be negative.

You want:

```cpp
owner_name.empty()
```

So:

```cpp
if (owner_name.empty())
{
    // invalid
}
```

This is a great example of why thinking about types matters.

You essentially wrote:

```text
length < 0 ?
```

but string length is:

```text
0, 1, 2, 3, ...
```

So the condition can never succeed.

---

# 3. Your constructor validation idea is correct, but implementation can improve

You currently have:

```cpp
if (account_number < 0)
{
    throw ...
}
else if (...)
{
    ...
}
else
{
    account_number_ = account_number;
    ...
}
```

Conceptually, you're doing:

```text
input
 ↓
validate
 ↓
invalid → reject
 ↓
valid → create object
```

That's good.

But there's a problem with your actual object initialization.

You're doing:

```cpp
account_number_ = account_number;
owner_name_ = owner_name;
balance_ = balance;
```

inside the constructor body.

Prefer member initialization:

```cpp
BankAccount::BankAccount(...)
    : account_number_{account_number},
      owner_name_{owner_name},
      balance_{balance}
{
    ...
}
```

However, this introduces another question:

> "What happens if validation fails?"

We'll come back to that.

---

# 4. You correctly asked about `const` parameters

You asked:

> Constructors are like setters, should I pass const type& for every member?

No.

Your current intuition is basically correct:

```text
small/simple type → pass by value
large object       → const reference
```

So:

```cpp
BankAccount(int account_number,
            std::string owner_name,
            int balance);
```

is already reasonable, although we can improve the string parameter depending on the desired ownership/copy behavior.

For your learning stage:

```cpp
int                    → int
float                  → float
bool                   → bool
std::string             → const std::string&
```

is a good rule of thumb.

But constructors aren't "like setters" in terms of parameter passing. A constructor's more important responsibility is:

> **Establish a valid initial state.**

---

# 5. Your `withdraw()` has a real bug ⚠️

You have:

```cpp
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
```

What happens with:

```cpp
account.widthdraw(-100);
```

Suppose:

```text
balance = 50
amount  = -100
```

Then:

```text
50 - (-100) = 150
```

The condition is true.

Then:

```text
balance -= -100
```

becomes:

```text
balance = 150
```

You've accidentally **increased the balance by withdrawing a negative amount**.

So `withdraw()` needs **two checks**:

```cpp
if ((amount > 0) && (amount <= balance_))
{
    balance_ -= amount;
    return true;
}
```

This is a very important lesson:

> **Don't only check the final state; validate the operation's input too.**

---

# 6. Your `transfer()` has a more serious design problem

You have:

```cpp
if (from.widthdraw(amount))
{
    if (to.deposit(amount))
    {
        std::cout << "Transfered $" << amount << std::endl; 
    }
}
```

Imagine:

```text
from.withdraw(30) → SUCCESS
to.deposit(30)     → FAILURE
```

Then you've already removed the money from `from`.

You have:

```text
From: $50 → $20

To: $20 → $20
```

The $30 disappeared.

That's a **transactional/invariant problem**.

You need to think about:

> **What should happen if the entire operation cannot complete?**

In your current implementation, `deposit()` only fails when `amount <= 0`, while `transfer()` already checks `amount > 0`, so in *this exact implementation* the second failure isn't likely.

But good design should still reason about the whole operation.

---

# 7. There's an even simpler transfer design

Because both `withdraw()` and `deposit()` validate positive amounts, you could do:

```cpp
bool transfer(BankAccount& from,
              BankAccount& to,
              int amount)
{
    if (amount <= 0)
    {
        return false;
    }

    if (!from.withdraw(amount))
    {
        return false;
    }

    const bool deposited = to.deposit(amount);

    // ...
}
```

But you've now discovered a deeper problem:

**What if `deposit()` fails after withdrawal?**

For a real financial system, you'd want the operation to be designed so that partial completion cannot happen.

For this beginner exercise, you can make the preconditions strong enough that the second operation cannot fail after the first succeeds.

For example, if:

```cpp
deposit(amount)
```

only fails when:

```cpp
amount <= 0
```

and you've already guaranteed:

```cpp
amount > 0
```

then it cannot fail.

That's a useful design technique:

> **Establish preconditions so that later operations are guaranteed to succeed.**

---

# 8. Account number validation

You asked:

> Where do I implement a function to check it?

Good question.

Suppose your rule is:

> Account number must contain exactly 12 digits.

You could create a validation function:

```cpp
bool isValidAccountNumber(int accountNumber)
{
    ...
}
```

But there's an important problem with representing a 12-digit account number as `int`.

A typical 32-bit `int` can't represent all 12-digit values.

For example:

```text
999,999,999,999
```

is much larger than a 32-bit signed `int`.

So this is actually a **data-modeling problem**.

An account number is often better represented as:

```cpp
std::string
```

because it is an **identifier**, not something you're mathematically calculating with.

For example:

```text
"000123456789"
```

must preserve the leading zeros.

If you used an integer:

```text
000123456789
```

becomes:

```text
123456789
```

and you've lost information.

This is a great example of:

> **Choose a type based on what the data means, not just what it looks like.**

---

# 9. Naming mistakes

You have:

```cpp
widthdraw
```

This should be:

```cpp
withdraw
```

And:

```cpp
onwer_name
```

should be:

```cpp
owner_name
```

And:

```cpp
Transfered
```

should be:

```text
Transferred
```

These don't affect the concept, but fix them because naming consistency becomes extremely important in larger projects.

---

# 10. Missing include

You're using:

```cpp
std::invalid_argument
```

but your `.cpp` only includes:

```cpp
#include "bank_account.hpp"
#include <iostream>
```

You should explicitly include the header that declares it:

```cpp
#include <stdexcept>
```

So:

```cpp
#include "bank_account.hpp"
#include <stdexcept>
```

Don't rely on another header indirectly including it.

---

# 11. Your constructor questions reveal an important concept

You asked:

> Where do I implement a function to check it?

There are two different kinds of validation.

### Validation that belongs to the object

For example:

```text
BankAccount
 ├── balance >= 0
 ├── owner name isn't empty
 └── valid account number
```

These are **BankAccount invariants**.

The class should enforce them.

### Validation that belongs to user input

For example:

```text
User enters:
"abc"
 ↓
parse input
 ↓
is this a valid integer?
```

That's an input/UI concern.

Don't mix:

```text
user input parsing
```

with:

```text
BankAccount invariant enforcement
```

They are different responsibilities.

---

# Overall assessment

| Area                 | Assessment                               |
| -------------------- | ---------------------------------------- |
| Encapsulation        | ✅ Excellent                              |
| References           | ✅ Good                                   |
| Constructors         | 🟡 Good concept, improve implementation  |
| Validation           | 🟡 Good idea, bugs present               |
| `const`              | 🟢 Good understanding                    |
| Invariants           | 🟢 Improving                             |
| RAII                 | 🟢 Not really needed yet                 |
| Error handling       | 🟡 Needs more thought                    |
| Data type selection  | 🟡 Account number is worth reconsidering |
| Transaction design   | 🟡 Important issue discovered            |
| MISRA-oriented style | 🟡 Several improvements needed           |

### Score: **7/10**

But I'd emphasize that the **conceptual understanding is better than the score suggests**. Your questions in the comments are actually very good questions.

The two bugs I most want you to remember are:

```cpp
owner_name.length() < 0
```

→ impossible condition.

And:

```cpp
balance_ - amount >= 0
```

without checking:

```cpp
amount > 0
```

→ allows negative withdrawals.

Those are exactly the kinds of boundary-condition bugs that encapsulation is supposed to prevent.

**Next challenge:** before moving to Exercise 3, revise this `BankAccount` so that **no public operation can ever make the object invalid**, and decide whether `account_number_` should remain an `int`.
