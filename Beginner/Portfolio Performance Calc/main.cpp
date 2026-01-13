#include <iostream>
#include <string>
#include "input.h"
#include "calculations.h"
#include "display.h"

int main()
{
    // ========== STEP 1: PRINT HEADER ==========
    std::cout << "=== Portfolio Performance Calculator ===\n\n";
    
    // ========== STEP 2: GET NUMBER OF POSITIONS ==========
    int numPositions = getIntegerInRange("How many positions (1-5): ", 1, 5);
    std::cout << '\n';
    
    // ========== STEP 3: DECLARE STORAGE FOR ALL POSITIONS ==========
    std::string symbol1, symbol2, symbol3, symbol4, symbol5;
    int shares1 = 0, shares2 = 0, shares3 = 0, shares4 = 0, shares5 = 0;
    double buyPrice1 = 0, buyPrice2 = 0, buyPrice3 = 0, buyPrice4 = 0, buyPrice5 = 0;
    double currentPrice1 = 0, currentPrice2 = 0, currentPrice3 = 0, currentPrice4 = 0, currentPrice5 = 0;
    
    double value1 = 0, value2 = 0, value3 = 0, value4 = 0, value5 = 0;
    double pnl1 = 0, pnl2 = 0, pnl3 = 0, pnl4 = 0, pnl5 = 0;
    double pnlPercent1 = 0, pnlPercent2 = 0, pnlPercent3 = 0, pnlPercent4 = 0, pnlPercent5 = 0;
    
    // ========== STEP 4: GET INPUT FOR EACH POSITION ==========
    
    // Position 1 (always present)
    if (numPositions >= 1) {
        std::cout << "Position 1:\n";
        symbol1 = getStockSymbol("Stock symbol: ");
        shares1 = static_cast<int>(getPositiveDouble("Shares: "));
        buyPrice1 = getPositiveDouble("Buy price: $");
        currentPrice1 = getPositiveDouble("Current price: $");
        std::cout << '\n';
    }
    
    // Position 2
    if (numPositions >= 2) {
        std::cout << "Position 2:\n";
        symbol2 = getStockSymbol("Stock symbol: ");
        shares2 = static_cast<int>(getPositiveDouble("Shares: "));
        buyPrice2 = getPositiveDouble("Buy price: $");
        currentPrice2 = getPositiveDouble("Current price: $");
        std::cout << '\n';
    }
    
    // Position 3
    if (numPositions >= 3) {
        std::cout << "Position 3:\n";
        symbol3 = getStockSymbol("Stock symbol: ");
        shares3 = static_cast<int>(getPositiveDouble("Shares: "));
        buyPrice3 = getPositiveDouble("Buy price: $");
        currentPrice3 = getPositiveDouble("Current price: $");
        std::cout << '\n';
    }
    
    // Position 4
    if (numPositions >= 4) {
        std::cout << "Position 4:\n";
        symbol4 = getStockSymbol("Stock symbol: ");
        shares4 = static_cast<int>(getPositiveDouble("Shares: "));
        buyPrice4 = getPositiveDouble("Buy price: $");
        currentPrice4 = getPositiveDouble("Current price: $");
        std::cout << '\n';
    }
    
    // Position 5
    if (numPositions >= 5) {
        std::cout << "Position 5:\n";
        symbol5 = getStockSymbol("Stock symbol: ");
        shares5 = static_cast<int>(getPositiveDouble("Shares: "));
        buyPrice5 = getPositiveDouble("Buy price: $");
        currentPrice5 = getPositiveDouble("Current price: $");
        std::cout << '\n';
    }
    
    // ========== STEP 5: CALCULATE METRICS FOR EACH POSITION ==========
    
    if (numPositions >= 1) {
        value1 = calculatePositionValue(shares1, currentPrice1);
        pnl1 = calculatePositionPnL(shares1, buyPrice1, currentPrice1);
        pnlPercent1 = calculatePnLPercentage(pnl1, shares1 * buyPrice1);
    }
    
    if (numPositions >= 2) {
        value2 = calculatePositionValue(shares2, currentPrice2);
        pnl2 = calculatePositionPnL(shares2, buyPrice2, currentPrice2);
        pnlPercent2 = calculatePnLPercentage(pnl2, shares2 * buyPrice2);
    }
    
    if (numPositions >= 3) {
        value3 = calculatePositionValue(shares3, currentPrice3);
        pnl3 = calculatePositionPnL(shares3, buyPrice3, currentPrice3);
        pnlPercent3 = calculatePnLPercentage(pnl3, shares3 * buyPrice3);
    }
    
    if (numPositions >= 4) {
        value4 = calculatePositionValue(shares4, currentPrice4);
        pnl4 = calculatePositionPnL(shares4, buyPrice4, currentPrice4);
        pnlPercent4 = calculatePnLPercentage(pnl4, shares4 * buyPrice4);
    }
    
    if (numPositions >= 5) {
        value5 = calculatePositionValue(shares5, currentPrice5);
        pnl5 = calculatePositionPnL(shares5, buyPrice5, currentPrice5);
        pnlPercent5 = calculatePnLPercentage(pnl5, shares5 * buyPrice5);
    }
    
    // ========== STEP 6: CALCULATE TOTALS ==========
    
    double totalValue = 0;
    double totalPnL = 0;
    double totalCostBasis = 0;
    
    if (numPositions >= 1) {
        totalValue += value1;
        totalPnL += pnl1;
        totalCostBasis += shares1 * buyPrice1;
    }
    
    if (numPositions >= 2) {
        totalValue += value2;
        totalPnL += pnl2;
        totalCostBasis += shares2 * buyPrice2;
    }
    
    if (numPositions >= 3) {
        totalValue += value3;
        totalPnL += pnl3;
        totalCostBasis += shares3 * buyPrice3;
    }
    
    if (numPositions >= 4) {
        totalValue += value4;
        totalPnL += pnl4;
        totalCostBasis += shares4 * buyPrice4;
    }
    
    if (numPositions >= 5) {
        totalValue += value5;
        totalPnL += pnl5;
        totalCostBasis += shares5 * buyPrice5;
    }
    
    double totalPnLPercent = calculatePnLPercentage(totalPnL, totalCostBasis);
    
    // ========== STEP 7: DISPLAY RESULTS ==========
    
    printTableHeader();
    
    if (numPositions >= 1) {
        printPositionRow(symbol1, shares1, buyPrice1, currentPrice1,
                         value1, pnl1, pnlPercent1);
    }
    
    if (numPositions >= 2) {
        printPositionRow(symbol2, shares2, buyPrice2, currentPrice2,
                         value2, pnl2, pnlPercent2);
    }
    
    if (numPositions >= 3) {
        printPositionRow(symbol3, shares3, buyPrice3, currentPrice3,
                         value3, pnl3, pnlPercent3);
    }
    
    if (numPositions >= 4) {
        printPositionRow(symbol4, shares4, buyPrice4, currentPrice4,
                         value4, pnl4, pnlPercent4);
    }
    
    if (numPositions >= 5) {
        printPositionRow(symbol5, shares5, buyPrice5, currentPrice5,
                         value5, pnl5, pnlPercent5);
    }
    
    printSummary(totalValue, totalPnL, totalPnLPercent);
    
    return 0;
}