#ifndef RISK_CALC_H
#define RISK_CALC_H

#include <string>

// Function declarations
double calculatePremium(int quantity, double premium);
double calculateMaxProfit(std::string option_type, int quantity, double strike, double premium);
double calculateMaxLoss(std::string option_type, int quantity, double strike, double premium);
double calculateBreakEven(std::string option_type, double strike, double premium);

#endif