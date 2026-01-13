//header gaurd for the calculations.cpp
#pragma once
double calculatePositionValue(int shares, double currentPrice);

double calculatePositionPnL(int shares, double buyPrice, double currentPrice);

double calculatePnLPercentage(double pnl, double costBasis);