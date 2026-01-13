

# ✅ PROJECT 3 — GUESSING GAME ENGINE (STRUCT + STATE CONTROL)

### 🎯 Goal

Teach you to control **program state cleanly**.

---

## ✅ STRUCT (MANDATORY)

```cpp
struct Game {
    int target;
    int guesses[7];
    int attempts;
    bool won;
};
```

---

## ✅ RULES

1. Random number between **1–100**
2. Player gets **exactly 7 guesses**
3. After each guess:

   * Store in `guesses[]`
   * Increment `attempts`
4. If guessed correctly:

   * `won = true`
   * Quit guessing loop
5. If after 7 guesses and not correct:

   * `won = false`

---

## ✅ END GAME REPORT (MANDATORY)

After game ends, print:

```
Result: WON / LOST
Target: X
Guesses: g1 g2 g3 ...
Distance per guess:
Guess 1: |g1 - target|
Guess 2: |g2 - target|
...
```

---

## ✅ REQUIRED FUNCTIONS

```cpp
void initGame(Game* g);
bool processGuess(Game* g, int guess);
void printReport(const Game* g);
```

You MUST pass the struct using **pointer**.

---

## ✅ PASS CONDITIONS

You pass only if:

* You never reset the struct accidentally
* Guess history is correct
* No garbage output
* You fully control game flow without globals

---

# ✅ PROJECT 4 — BANK ACCOUNT SIMULATOR (POINTER CONTROL + LOGIC SAFETY)

This one separates hobbyists from engineers.

---

## ✅ STRUCT

```cpp
struct Account {
    int id;
    double balance;
    bool active;
};
```

---

## ✅ SYSTEM CAPACITY

* Maximum **100 accounts**
* Stored in:

```cpp
Account accounts[100];
```

---

## ✅ MENU SYSTEM

```
1. Create Account
2. Deposit
3. Withdraw
4. Transfer
5. Close Account
6. Print All Accounts
7. Exit
```

Loop forever until exit.

---

## ✅ ACCOUNT CREATION

* Assign auto-incremented ID starting at 1000
* Initial balance must be ≥ 0
* Set `active = true`

---

## ✅ DEPOSIT RULES

* Must locate account by ID
* Must be active
* Deposit amount > 0
* Use **pointer access**

---

## ✅ WITHDRAW RULES

* Must not overdraft
* Must be active
* Show error if insufficient funds

---

## ✅ TRANSFER RULES

* Two valid IDs required
* Both active
* Sender must have sufficient funds
* One transaction only if all checks pass

---

## ✅ CLOSE ACCOUNT RULES

* Set `active = false`
* Balance must be 0 first

---

## ✅ REQUIRED FUNCTIONS

```cpp
int findAccountById(Account* arr, int size, int id);
void createAccount(Account* arr, int& count);
void deposit(Account* arr, int count);
void withdraw(Account* arr, int count);
void transfer(Account* arr, int count);
void closeAccount(Account* arr, int count);
void printAccounts(const Account* arr, int count);
```

---

## ✅ PASS CONDITIONS

You pass only if:

* No crashes from bad IDs
* No negative balances possible
* No inactive account can transact
* Transfers never partially complete

---

# ⚠️ BLUNT TRUTH

If you can’t cleanly pass **PROJECTS 1–4**, you are **not ready** for:

* Matching engines
* Market replay
* Latency testing
* Or real HFT systems

These are your **mechanical lifts**. Skip them and your ceiling stays low.

---

# ✅ YOUR NEXT STEP (DO THIS NOW)

Start **PROJECT 1 (Calculator)**.

When you're done, send me:

* Your full program flow (not code)
* What failed first
* What took the longest to debug

Then I’ll unlock **Projects 5–7 (Order Book + Matching Engine)** with the same high-detail spec.

You want HFT?
Then earn it one brutal project at a time.
