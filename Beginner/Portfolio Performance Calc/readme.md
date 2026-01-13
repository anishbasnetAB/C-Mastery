# Portfolio Performance Calculator

A command-line C++ application for tracking stock portfolio performance with real-time profit/loss calculations.

---

## 🎯 Project Goals

**What we built:** A professional portfolio analyzer that accepts stock positions, calculates performance metrics, and displays results in a formatted table.

**Why we built it:** To master C++ fundamentals through a real-world financial application, focusing on modular design and clean code practices.

---

## 🏗️ Architecture

### File Structure (8 files)
```
├── input.h / input.cpp       → User input & validation
├── calculations.h / .cpp     → Pure calculation logic
├── display.h / .cpp          → Formatted output
└── main.cpp                  → Program orchestration
```

### Design Principles
- **Separation of Concerns**: Each module has one responsibility
- **Pure Functions**: Calculations have no side effects (easy to test)
- **DRY**: Reusable validation functions eliminate code duplication
- **Guard Clauses**: Early returns keep code flat and readable

---

## 💡 Key Concepts Implemented

### 1. Multi-File Organization
- Header guards prevent multiple inclusion
- Forward declarations (`.h`) separate from implementations (`.cpp`)
- Modular compilation and linking

### 2. Input Validation
```cpp
while (true) {
    std::cin >> value;
    if (std::cin.fail() || value <= 0) {
        std::cin.clear();
        std::cin.ignore(...);
        continue;  // Retry
    }
    return value;  // Valid input
}
```
- Validates types and ranges
- Clears error states
- Loops until valid input

### 3. Buffer Management
```cpp
std::cin >> value;
std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Critical!
std::getline(std::cin, symbol);  // Now works correctly
```
**Why:** `std::cin >>` leaves `\n` in buffer; must clean it before `getline()`.

### 4. Formatted Output
```cpp
std::cout << std::fixed << std::setprecision(2);
std::cout << std::left << std::setw(10) << symbol;
std::cout << std::right << std::setw(12) << "$" << value;
```
Professional table alignment with precise decimal control.

---

## 🚫 Why No Arrays?

**Intentional constraint** to master fundamentals first:
```cpp
// Without arrays (what we did):
std::string symbol1, symbol2, symbol3;
if (numPositions >= 1) { /* handle position 1 */ }
if (numPositions >= 2) { /* handle position 2 */ }
// ...repetitive but explicit

// With arrays (next project):
Stock positions[5];
for (int i = 0; i < numPositions; ++i) { /* handle positions[i] */ }
```

**Rationale:**
1. Build strong foundations (variables, functions, I/O) before adding array complexity
2. Appreciate the power of arrays after experiencing manual repetition
3. Simulate real-world constraints in legacy systems

---

## 📊 Sample Output
```
=== Portfolio Performance Calculator ===

How many positions (1-5): 2

Position 1:
Stock symbol: AAPL
Shares: 100
Buy price: $150.00
Current price: $175.50

Position 2:
Stock symbol: GOOGL
Shares: 50
Buy price: $2800.00
Current price: $2750.00

================================================================================
Portfolio Performance Report
================================================================================
Symbol      Shares    Buy Price  Curr Price      Value        P&L      P&L %
--------------------------------------------------------------------------------
AAPL           100     $150.00     $175.50  $17,550.00   $2,550.00    17.00%
GOOGL           50   $2,800.00   $2,750.00 $137,500.00  -$2,500.00    -1.79%
================================================================================

TOTAL PORTFOLIO VALUE: $155,050.00
TOTAL P&L: $50.00 (0.03%)
```

---

## 🔧 Build & Run
```bash
# Compile
g++ -std=c++17 main.cpp input.cpp calculations.cpp display.cpp -o portfolio

# Run
./portfolio
```

---

## ✅ Skills Demonstrated

**Technical:**
- Multi-file project organization
- Function decomposition
- Input validation & error handling
- Formatted output with `<iomanip>`
- Buffer management in I/O
- Type conversion (`static_cast`)

**Software Engineering:**
- Separation of concerns
- Single Responsibility Principle
- Incremental development & testing
- Pure function design
- Professional documentation

---

## 🎓 What You Learned

- How to structure real C++ programs (not toy exercises)
- Why modular design matters (change one part without breaking others)
- The importance of testing each component before integration
- Professional coding practices used in production software

**Next:** Project 2 introduces arrays to eliminate the repetition you just experienced.

---

*Built as part of a structured C++ curriculum focusing on fundamentals and professional development practices.*