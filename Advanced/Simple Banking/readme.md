### Challenge 10: Mini Banking System

**Topics: Multiple functions, Scope, Static variables, Control flow, Input validation**

Create a simple banking program with these features:

```cpp
// Use static local variable to maintain balance across function calls
void deposit();
void withdraw();
void checkBalance();
void displayTransactionCount(); // Use another static variable
```

**Requirements:**

- Starting balance is $1000 (static variable in one of the functions)
- Track number of total transactions (another static variable)
- Validate all inputs (no negative deposits/withdrawals)
- Don't allow overdraft (balance can't go negative)
- Create a menu system with proper loop
- Use proper function separation

**Menu:**

1. Deposit
2. Withdraw
3. Check Balance
4. Transaction History (just count)
5. Exit