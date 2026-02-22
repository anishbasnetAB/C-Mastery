# C++ OOP — Bank Account System

A beginner project built to learn and apply core C++ Object-Oriented Programming concepts.

---

## What We Built

A simple Bank Account System with three classes:

```
Account              ← abstract base class
├── SavingsAccount   ← earns interest, standard withdrawal rules
└── CurrentAccount   ← no interest, overdraft allowed
```

---

## Concepts Used

### Classes & Constructors
- Parameterized constructor to initialize objects at birth
- Delegating constructor — `SavingsAccount(name, number)` delegates to full constructor with defaults
- Virtual destructor in base class to prevent memory leaks
- Member initializer list to initialize members before constructor body runs
- Validation inside constructors — negative balance becomes 0, bad interest rate becomes 0.03

### Encapsulation
- Private and protected members — data hidden from outside world
- Public interface — only way to interact with the object
- Validation in `deposit()` and `withdraw()` — object protects its own balance
- Getters marked `const` — reading data never modifies the object

### Inheritance
- `SavingsAccount` and `CurrentAccount` inherit from `Account`
- Base constructor called explicitly from derived constructor
- `protected` members — accessible to derived classes, hidden from outside
- Construction order — base constructor always runs first, destructor last

### Polymorphism
- `virtual` functions — `getInfo()`, `withdraw()`, `getType()`, `applyInterest()`
- `override` keyword — compiler checks the signature matches base exactly
- `vector<Account*>` — stores different account types under one base pointer
- Loop calls correct function for each type automatically at runtime

### Abstraction
- Pure virtual functions `getType()` and `applyInterest()` — base class sets the contract
- Derived classes must implement them or they won't compile
- `Account` is abstract — cannot create an `Account` object directly

### `this` Pointer
- `return *this` in `deposit()` and `withdraw()`
- `Account&` return type — returns reference to same object, not a copy
- Enables method chaining: `acc.deposit(500).withdraw(100)`

---

## Key Lessons

- A class member is either a member variable (data) or a member function (behavior)
- Constructors cannot be overridden — only called
- Each class initializes what it owns — base initializes its members, derived initializes its own
- `return *this` returns the object, `&` makes sure it's the same object not a copy
- `vector<Account*>` works because pointers to derived objects can be stored as base pointers
- Virtual functions enable the right version to run automatically based on the actual object

---

## Files
- `main.cpp` — all classes and test cases in one file