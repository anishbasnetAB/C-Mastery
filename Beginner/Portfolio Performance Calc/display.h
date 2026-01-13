#include <string> //header gaurd for display.cpp
#ifndef DISPLAY_H
#define DISPLAY_H
void printTableHeader();

void printPositionRow(std::string symbol, int shares, double buyPrice, double currentPrice, double value,
                        double pnl, double pnlPercent);

void printSummary(double totalValue, double totalPnL, double PnLPercenta);
#endif // DISPLAY_H