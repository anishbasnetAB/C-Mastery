# Trading Strategy Backtester

A C++ implementation of a moving average crossover strategy backtester that analyzes historical price data and generates trading signals.

## Overview

This project implements a technical analysis tool that:
- Calculates 5-day and 10-day simple moving averages (SMA) from user-provided price data
- Detects bullish and bearish crossover signals
- Executes a simulated backtest with position tracking
- Generates performance statistics including P&L, win rate, and trade history

## Strategy Logic

The backtester uses a **Moving Average Crossover Strategy**:
- **Buy Signal**: When the 5-day MA crosses above the 10-day MA (bullish crossover)
- **Sell Signal**: When the 5-day MA crosses below the 10-day MA (bearish crossover)

This is a trend-following strategy that attempts to capture momentum shifts in price movement.

## Project Structure
```
project2/
├── data.h              # Price data input/output declarations
├── data.cpp            # Price data input/output implementations
├── indicators.h        # Technical indicator declarations (SMA, crossover)
├── indicators.cpp      # Technical indicator implementations
├── backtest.h          # Backtest engine and Trade struct declarations
├── backtest.cpp        # Backtest engine implementation
├── stats.h             # Performance statistics declarations
├── stats.cpp           # Performance statistics implementations
├── main.cpp            # Program orchestration
└── README.md           # This file
```

## File Responsibilities

### Data Layer (`data.h/cpp`)
Handles all user input and price data management:
- `getPriceData()`: Accepts 10-30 daily prices from user input
- `printPrices()`: Displays entered prices for verification

### Indicators Layer (`indicators.h/cpp`)
Implements technical analysis calculations:
- `calculateSMA()`: Computes simple moving average for a given period
- `detectCrossover()`: Identifies when fast MA crosses slow MA (generates signals)

### Backtest Layer (`backtest.h/cpp`)
Executes the trading strategy simulation:
- `Trade` struct: Stores individual trade data (entry/exit prices, P&L)
- `runBacktest()`: State machine that processes signals and tracks positions

### Statistics Layer (`stats.h/cpp`)
Analyzes backtest results:
- `calculateTotalReturn()`: Sums all trade P&L
- `calculateWinRate()`: Percentage of profitable trades
- `findLargestWin()`: Best performing trade
- `findLargestLoss()`: Worst performing trade
- `printTradeHistory()`: Displays all completed trades
- `printSummary()`: Shows aggregate performance metrics

### Main (`main.cpp`)
Coordinates the entire workflow:
1. Collects price data from user
2. Calculates moving averages
3. Runs backtest simulation
4. Displays results

## Compilation
```bash
g++ -std=c++17 -Wall -Wextra -o backtest \
    main.cpp data.cpp indicators.cpp backtest.cpp stats.cpp
```

## Usage
```bash
./backtest
```

The program will prompt for:
1. Number of price data points (10-30 days)
2. Daily closing prices for each day

Example session:
```
=== Moving Average Crossover Backtest ===

Enter number of days (10-30): 15
Enter 15 daily closing prices:
Day 1: $100.00
Day 2: $102.00
...
Day 15: $115.00

Calculating 5-day and 10-day moving averages...
Running backtest...

=== Trade History ===
Trade 1:
  Entry: Day 11 @ $108.50
  Exit:  Day 14 @ $113.25
  P&L: $4.75 (4.38%)

=== Performance Summary ===
Total Trades: 1
Total P&L: $4.75
Win Rate: 100.00%
Largest Win: $4.75
Largest Loss: $0.00
Average P&L per Trade: $4.75
```

## Implementation Details

### SMA Calculation Algorithm
```
For day i with period N:
  if i < N-1:
    SMA[i] = 0 (insufficient data)
  else:
    SMA[i] = (prices[i-N+1] + ... + prices[i]) / N
```

### Crossover Detection Logic
```
Bullish: fastMA_previous < slowMA_previous AND fastMA_current > slowMA_current
Bearish: fastMA_previous > slowMA_previous AND fastMA_current < slowMA_current
```

### Position State Machine
```
State: NOT_IN_POSITION
  → BUY signal → State: IN_POSITION (record entry)

State: IN_POSITION
  → SELL signal → State: NOT_IN_POSITION (record exit, calculate P&L)
```

## Testing Recommendations

### Test Case 1: Uptrend
Input consistent rising prices. Expected: Single long trade with positive P&L.

### Test Case 2: Downtrend
Input consistent falling prices. Expected: Delayed entry or losing trades.

### Test Case 3: Oscillating Market
Input alternating high/low prices. Expected: Multiple crossovers, mixed P&L.

### Edge Cases
- Minimum 10 prices (required for 10-day MA)
- All identical prices (no signals generated)
- Extreme volatility (multiple rapid crossovers)

## Learning Objectives

This project reinforces:
- Multi-file C++ project organization
- Array manipulation and boundary checking
- State machine implementation
- Algorithmic thinking (SMA calculation, signal detection)
- Separation of concerns (I/O, computation, presentation)
- Struct usage for data aggregation
- Incremental testing methodology

## Performance Metrics Explained

- **Total P&L**: Sum of all trade profits/losses in dollars
- **Win Rate**: Percentage of trades that were profitable
- **Largest Win/Loss**: Best and worst individual trade performance
- **Average P&L**: Mean profit/loss per completed trade

## Limitations

- Assumes instant execution at closing prices (no slippage)
- No transaction costs or commissions
- No position sizing (always trades fixed quantity)
- Simplified strategy (real-world trading requires more sophisticated signals)
- No risk management (stop losses, position limits)

## Future Enhancements

Potential extensions:
- Dynamic array sizing (vectors) instead of fixed arrays
- File I/O for loading historical price data (CSV support)
- Multiple strategy comparison
- Additional technical indicators (RSI, MACD, Bollinger Bands)
- Position sizing and risk management
- Visualization of price and MA curves
- Monte Carlo simulation for strategy robustness testing

## Requirements

- C++17 or later
- Standard library only (no external dependencies)
- Compiler: g++, clang++, or MSVC

## Author Notes

This is a learning project focused on multi-file organization and algorithmic implementation. The strategy implemented is for educational purposes only and should not be used for actual trading decisions without significant enhancement and proper risk management.