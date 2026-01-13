#include "constants.h"
#include <string>

//calculate total premium
double calculatePremium(int quantity, double premium)  
{
    return std::abs(quantity) * premium * SHARES_PER_CONTRACT;
}

//Profit cases 
double calculateMaxProfit(std::string option_type, int quantity, 
                          double strike, double premium)
{
    if (option_type == "call") {
        if (quantity > 0) {
            // Long call
            return UNLIMITED;
        } else {
            // Short call
            return calculatePremium(quantity, premium);
        }
    } else if (option_type == "put") {
        if (quantity > 0) {
            // Long put
            return (strike - premium) * SHARES_PER_CONTRACT * quantity;
        } else {
            // Short put
            return calculatePremium(quantity, premium);
        }
    }
    
    return 0.0;
}

//Loss cases
double calculateMaxLoss(std::string option_type, int quantity, 
                        double strike, double premium)
{
    if (option_type == "call") {
        if (quantity > 0) {
            // Long call: max loss = premium paid
            return calculatePremium(quantity, premium);
        } else {
            // Short call: max loss = unlimited
            return UNLIMITED;
        }
    } else if (option_type == "put") {
        if (quantity > 0) {
            // Long put: max loss = premium paid
            return calculatePremium(quantity, premium);
        } else {
            // Short put: max loss = strike to zero minus premium
            return (strike * SHARES_PER_CONTRACT * std::abs(quantity)) - calculatePremium(quantity, premium);
        }
    }
    
    return 0.0;
}

double calculateBreakEven(std::string option_type, double strike, double premium)
{
    // TODO: Two cases only
    if (option_type=="call"){
        return strike + premium;
    }
    return strike - premium;
}