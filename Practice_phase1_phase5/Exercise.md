Absolutely. Since you've now covered **Phases 1–5**, I'd recommend exercises that force you to combine concepts rather than isolated syntax drills.

I'll give you **10 exercises**, increasing in difficulty. I won't give solutions yet so you can implement them yourself.

## Phase 1–5 Exercise Set

| #  | Exercise              | Main concepts                                       | Difficulty |
| -- | --------------------- | --------------------------------------------------- | ---------- |
| 1  | Employee System       | structs/classes, `const`, references, encapsulation | ⭐          |
| 2  | Bank Account          | constructors, validation, private data              | ⭐⭐         |
| 3  | Inventory Manager     | vectors, references, pointers, RAII                 | ⭐⭐         |
| 4  | Vehicle Hierarchy     | inheritance, overriding, `virtual`                  | ⭐⭐⭐        |
| 5  | Shape System          | abstract classes, polymorphism                      | ⭐⭐⭐        |
| 6  | Smart Pointer Zoo     | `unique_ptr`, ownership, polymorphic collections    | ⭐⭐⭐        |
| 7  | Notification System   | interfaces, polymorphism                            | ⭐⭐⭐⭐       |
| 8  | Game Character System | inheritance + polymorphism + encapsulation          | ⭐⭐⭐⭐       |
| 9  | Library System        | composition + polymorphism + ownership              | ⭐⭐⭐⭐⭐      |
| 10 | Mini Project          | Phases 1–5 together                                 | ⭐⭐⭐⭐⭐      |

---

# Exercise 1 — Employee System

Create an `Employee` class.

Requirements:

```text
Employee
├── name
├── age
└── salary
```

Rules:

* `name` cannot be empty.
* `age` must be between 18 and 100.
* `salary` cannot be negative.
* Members must be private.
* Provide appropriate constructors.
* Provide getters.
* Don't create setters automatically; think about which operations actually make sense.

Then write:

```cpp
void printEmployee(const Employee& employee);
```

### Concepts tested

* class
* private/public
* constructors
* `const`
* `const&`
* encapsulation
* invariants

---

# Exercise 2 — Bank Account

Create:

```text
BankAccount
├── account number
├── owner name
└── balance
```

Operations:

```cpp
deposit()
withdraw()
getBalance()
```

Rules:

* Account must have an owner.
* Deposit must be positive.
* Withdrawal must be positive.
* Withdrawal cannot exceed balance.
* Balance must never become negative.

Then create:

```cpp
void transfer(BankAccount& from,
              BankAccount& to,
              double amount);
```

The function should transfer money between two accounts.

### Think carefully

Why is:

```cpp
BankAccount& from
```

better than:

```cpp
BankAccount from
```

here?

---

# Exercise 3 — Inventory Manager

Create:

```text
Product
├── name
├── price
└── quantity
```

Then create:

```text
Inventory
└── vector<Product>
```

Operations:

```cpp
addProduct()
removeProduct()
findProduct()
printInventory()
```

Use:

```cpp
std::vector<Product>
```

rather than manually allocated arrays.

Then implement:

```cpp
Product* findProduct(const std::string& name);
```

and:

```cpp
const Product* findProduct(const std::string& name) const;
```

### Think about this

Why are there two versions?

```cpp
Product*
const Product*
```

And why is the function itself sometimes `const`?

This is a very good exercise for understanding **const correctness**.

---

# Exercise 4 — Vehicle Hierarchy

Create:

```text
Vehicle
├── Car
├── Motorcycle
└── Truck
```

Base class:

```cpp
class Vehicle
{
public:
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual ~Vehicle() = default;
};
```

Each derived class should implement the behavior differently.

For example:

```text
Car        → "Car starts"
Motorcycle → "Motorcycle starts"
Truck      → "Truck starts"
```

Then:

```cpp
void startVehicle(const Vehicle& vehicle);
```

The function should not know whether it received a `Car`, `Motorcycle`, or `Truck`.

### Concepts

* inheritance
* abstract classes
* pure virtual functions
* overriding
* `override`
* virtual destructor
* base references

---

# Exercise 5 — Shape System

Now build the Shape system you've already been discussing.

```text
Shape
├── Circle
├── Rectangle
└── Triangle
```

Every shape must support:

```cpp
calculateArea()
```

and:

```cpp
scale()
```

For example:

```cpp
shape.scale(2.0F);
```

should double the dimensions.

Create:

```cpp
std::vector<std::unique_ptr<Shape>>
```

containing different shapes.

Then:

```cpp
for (const auto& shape : shapes)
{
    std::cout << shape->calculateArea() << '\n';
}
```

### Extra challenge

Add:

```cpp
calculatePerimeter()
```

to the common interface.

Ask yourself:

> Does this operation genuinely make sense for every Shape?

---

# Exercise 6 — Smart Pointer Zoo

Create:

```text
Animal
├── Dog
├── Cat
└── Bird
```

Each animal has:

```cpp
speak()
```

Then create:

```cpp
std::vector<std::unique_ptr<Animal>>
```

and store different animals inside it.

Example:

```text
Dog  → Woof
Cat  → Meow
Bird → Tweet
```

Then iterate through the collection and call:

```cpp
animal->speak();
```

### Extra challenge

Add:

```cpp
getName()
```

to the base class.

Then add a `Dog`-specific function:

```cpp
fetch()
```

Try to call `fetch()` through:

```cpp
std::unique_ptr<Animal>
```

You should discover that you can't.

Then investigate how:

```cpp
dynamic_cast
```

could be used.

This directly tests the question you were asking earlier.

---

# Exercise 7 — Notification System

Design:

```text
Notification
├── EmailNotification
├── SMSNotification
└── PushNotification
```

Common interface:

```cpp
send(const std::string& message)
```

Then:

```cpp
std::vector<std::unique_ptr<Notification>>
```

could contain:

```text
Email
SMS
Push
Email
Push
SMS
```

Your main code should simply do:

```cpp
for (const auto& notification : notifications)
{
    notification->send("Hello");
}
```

It should **not** contain:

```cpp
if (email)
{
}
else if (sms)
{
}
else if (push)
{
}
```

### Goal

This exercise tests whether you've really understood:

> **One interface, many implementations.**

---

# Exercise 8 — Game Character System

Create:

```text
Character
├── Warrior
├── Mage
└── Archer
```

Every character has:

```text
name
health
```

Common operations:

```cpp
attack()
takeDamage()
isAlive()
```

But each character attacks differently.

For example:

```text
Warrior → sword attack
Mage    → magic attack
Archer  → arrow attack
```

Requirements:

* private member variables
* constructor establishes a valid state
* `health` cannot become negative
* polymorphic `attack()`
* polymorphic `takeDamage()`
* `std::unique_ptr`
* `std::vector`

Then create:

```cpp
std::vector<std::unique_ptr<Character>>
```

and simulate a battle.

### Extra challenge

Give `Mage` a special method:

```cpp
castSpell()
```

Try to access it through:

```cpp
Character*
```

and decide whether `dynamic_cast` is appropriate.

---

# Exercise 9 — Library System

This one combines **composition + polymorphism + ownership**.

Create:

```text
Library
 │
 ├── Book
 ├── Magazine
 └── DVD
```

But don't automatically use inheritance just because they are all "library items."

Think about the design.

Maybe:

```text
LibraryItem
├── Book
├── Magazine
└── DVD
```

Common interface:

```cpp
getTitle()
getId()
borrow()
returnItem()
```

Then:

```cpp
Library
```

owns the items.

Consider:

```cpp
std::vector<std::unique_ptr<LibraryItem>>
```

The library should be responsible for the lifetime of its items.

### Questions to answer

1. Who owns the items?
2. Why `unique_ptr`?
3. Should `LibraryItem` have a virtual destructor?
4. Which functions belong in the base class?
5. Should `Book` have book-specific functions?
6. When would `dynamic_cast` be appropriate?

This is a **very good Phase 1–5 integration exercise**.

---

# Exercise 10 — Mini Project: Vehicle Management System

This is the one I'd recommend doing after the others.

Build:

```text
Vehicle Management System

                 Vehicle
                    │
       ┌────────────┼────────────┐
       │            │            │
      Car       Motorcycle      Truck
```

### `Vehicle`

Common information:

```text
brand
model
year
```

Common operations:

```cpp
start()
stop()
calculateFuelConsumption()
```

### `Car`

Additional:

```text
numberOfDoors
```

### `Motorcycle`

Additional:

```text
hasSidecar
```

### `Truck`

Additional:

```text
cargoCapacity
```

---

## Requirements

Your program should have:

### 1. Encapsulation

Don't allow:

```cpp
vehicle.year = -500;
```

Protect the state.

---

### 2. Constructors

An object should never start in an obviously invalid state.

---

### 3. Inheritance

Use the appropriate `Vehicle` hierarchy.

---

### 4. Polymorphism

Store everything in:

```cpp
std::vector<std::unique_ptr<Vehicle>>
```

Then:

```cpp
for (const auto& vehicle : vehicles)
{
    vehicle->start();
}
```

---

### 5. RAII

Do **not** use:

```cpp
new
delete
```

manually.

Use:

```cpp
std::make_unique
```

and:

```cpp
std::unique_ptr
```

---

### 6. References

Create functions such as:

```cpp
void serviceVehicle(Vehicle& vehicle);
```

instead of unnecessarily copying the vehicle.

---

### 7. `const`

For operations that don't modify the object:

```cpp
void printVehicle(const Vehicle& vehicle);
```

and:

```cpp
const
```

member functions where appropriate.

---

### 8. Dynamic casting

Give one derived class a genuinely specialized operation.

For example:

```cpp
Truck::loadCargo()
```

Then decide:

> Should `loadCargo()` be part of `Vehicle`?

Probably not.

Then experiment with accessing it through a `Vehicle*` using `dynamic_cast`.

---

# Recommended order

Don't jump straight to #10.

I'd do:

```text
#1  Employee
 ↓
#2  BankAccount
 ↓
#3  Inventory
 ↓
#4  Vehicle inheritance
 ↓
#5  Shape polymorphism
 ↓
#6  Smart-pointer polymorphism
 ↓
#7  Notification interface
 ↓
#8  Game characters
 ↓
#9  Library
 ↓
#10 Vehicle Management System
```

For **#1–#3**, focus on whether your classes protect their own state.

For **#4–#7**, focus on:

> "What belongs in the base interface?"

For **#8–#10**, focus on the bigger architectural question:

> **"Who owns what, what does each class know, and what behavior should be polymorphic?"**

And throughout, keep your MISRA-oriented habits: explicit initialization, `const` correctness, RAII, no raw `new/delete`, no C-style casts, and no unnecessary type flags.
