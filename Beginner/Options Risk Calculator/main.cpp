#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <algorithm>
#include <cctype>
#include "constants.h"
#include <cmath>
#include "risk_calc.h"

static std::string toLower(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(),
                   [](unsigned char c){ return static_cast<char>(std::tolower(c)); });
    return s;
}

static void clearBadInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

static void printMoneyOrUnlimited(double v) {
    if (v == UNLIMITED) {
        std::cout << "Unlimited";
    } else {
        std::cout << "$" << std::fixed << std::setprecision(2) << v;
    }
}

int main() {
    std::cout << "Options Risk Calculator\n";
    std::cout << "=======================\n\n";

    char continue_calc = 'y';

    while (continue_calc == 'y' || continue_calc == 'Y') {
        // 1. Get user inputs
        std::string symbol, option_type;
        int quantity = 0;
        double strike = 0.0, premium = 0.0;

        // Symbol
        while (true) {
            std::cout << "Underlying symbol (e.g., AAPL): ";
            std::cin >> symbol;
            if (!symbol.empty()) break;
            std::cout << "  Invalid symbol. Try again.\n";
        }

        // Option type
        while (true) {
            std::cout << "Option type (call/put): ";
            std::cin >> option_type;
            option_type = toLower(option_type);
            if (option_type == "call" || option_type == "put") break;
            std::cout << "  Invalid option type. Enter \"call\" or \"put\".\n";
        }

        // Quantity (signed)
        while (true) {
            std::cout << "Quantity (# contracts, + = long/buy, - = short/sell): ";
            if (!(std::cin >> quantity)) {
                clearBadInput();
                std::cout << "  Invalid number. Try again.\n";
                continue;
            }
            if (quantity != 0) break;
            std::cout << "  Quantity cannot be 0.\n";
        }

        // Strike
        while (true) {
            std::cout << "Strike price: ";
            if (!(std::cin >> strike)) {
                clearBadInput();
                std::cout << "  Invalid number. Try again.\n";
                continue;
            }
            if (strike > 0.0) break;
            std::cout << "  Strike must be > 0.\n";
        }

        // Premium
        while (true) {
            std::cout << "Premium (per share): ";
            if (!(std::cin >> premium)) {
                clearBadInput();
                std::cout << "  Invalid number. Try again.\n";
                continue;
            }
            if (premium >= 0.0) break;
            std::cout << "  Premium must be >= 0.\n";
        }

        // 2. Calculate all metrics
        double total_premium = calculatePremium(quantity, premium);
        double max_profit   = calculateMaxProfit(option_type, quantity, strike, premium);
        double max_loss     = calculateMaxLoss(option_type, quantity, strike, premium);
        double break_even   = calculateBreakEven(option_type, strike, premium);

        // 3. Display results
        const bool is_long = (quantity > 0);
        const int contracts = std::abs(quantity);

        std::cout << "\n----------------------------------------\n";
        std::cout << "Symbol: " << symbol << "\n";
        std::cout << "Position: " << (is_long ? "Long " : "Short ")
                  << (option_type == "call" ? "Call" : "Put")
                  << " (" << contracts << (contracts == 1 ? " contract" : " contracts") << ")\n";
        std::cout << "Strike: $" << std::fixed << std::setprecision(2) << strike
                  << "   Premium: $" << premium << " / share\n";

        std::cout << "\n";
        std::cout << std::left << std::setw(22) << "Total Premium:";
        double tp_abs = std::abs(total_premium);
        std::cout << (is_long ? "Paid " : "Received ");
        std::cout << "$" << std::fixed << std::setprecision(2) << tp_abs << "\n";

        std::cout << std::left << std::setw(22) << "Max Profit:";
        printMoneyOrUnlimited(max_profit);
        std::cout << "\n";

        std::cout << std::left << std::setw(22) << "Max Loss:";
        printMoneyOrUnlimited(max_loss);
        std::cout << "\n";

        std::cout << std::left << std::setw(22) << "Break-even Price:";
        std::cout << "$" << std::fixed << std::setprecision(2) << break_even << "\n";
        std::cout << "----------------------------------------\n";

        // 4. Ask to continue
        std::cout << "\nCalculate another? (y/n): ";
        std::cin >> continue_calc;
        std::cout << "\n";
    }

    std::cout << "Thanks for using Options Risk Calculator!\n";
    return 0;
}
