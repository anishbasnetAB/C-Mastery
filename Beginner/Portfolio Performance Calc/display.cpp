// display.cpp
#include "display.h"
#include <iostream>
#include <iomanip>
#include <string>

void printTableHeader()
{
    std::cout << std::string(80, '=') << '\n';
    std::cout << "Portfolio Performance Report\n";
    std::cout << std::string(80, '=') << '\n';
    
    std::cout << std::left  << std::setw(10) << "Symbol"
              << std::right << std::setw(10) << "Shares"
              << std::right << std::setw(12) << "Buy Price"
              << std::right << std::setw(12) << "Curr Price"
              << std::right << std::setw(13) << "Value"
              << std::right << std::setw(12) << "P&L"
              << std::right << std::setw(9)  << "P&L %"
              << '\n';
    
    std::cout << std::string(80, '-') << '\n';
}

void printPositionRow(std::string symbol, int shares, double buyPrice, 
                      double currentPrice, double value, double pnl, double pnlPercent)
{
    std::cout << std::fixed << std::setprecision(2);
    
    std::cout << std::left  << std::setw(10) << symbol
              << std::right << std::setw(10) << shares
              << std::right << std::setw(11) << "$" << buyPrice
              << std::right << std::setw(11) << "$" << currentPrice
              << std::right << std::setw(12) << "$" << value
              << std::right << std::setw(11) << "$" << pnl
              << std::right << std::setw(8)  << pnlPercent << "%"
              << '\n';
}

void printSummary(double totalValue, double totalPnL, double pnlPercent)
{
    std::cout << std::string(80, '=') << '\n';
    std::cout << '\n';
    
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "TOTAL PORTFOLIO VALUE: $" << totalValue << '\n';
    std::cout << "TOTAL P&L: $" << totalPnL 
              << " (" << pnlPercent << "%)" << '\n';
}