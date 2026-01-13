// calculations.cpp
#include "calculations.h"

double calculatePositionValue(int shares, double currentPrice)
{
    return shares * currentPrice;
}

double calculatePositionPnL(int shares, double buyPrice, double currentPrice)
{
    return shares * (currentPrice - buyPrice);
}

double calculatePnLPercentage(double pnl, double costBasis)
{
    // Handle division by zero
    if (costBasis <= 0) {
        return 0.0;
    }
    return (pnl / costBasis) * 100.0;
}