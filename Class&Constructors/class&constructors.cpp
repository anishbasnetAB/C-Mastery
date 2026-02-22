#include <iostream>

class Position {

private:
    std::string m_symbol;
    int m_shares;
    double m_entryPrice;

public:
    // default constructor
    Position()
        : m_symbol{""}, m_shares{0}, m_entryPrice{0.0}
    {}

    // parameterized constructor
    Position(std::string symbol, int shares, double entryPrice)
        : m_symbol{symbol}, m_shares{shares}, m_entryPrice{entryPrice}
    {}

    // copy constructor
    Position(const Position& other)
        : m_symbol{other.m_symbol}, m_shares{other.m_shares}, m_entryPrice{other.m_entryPrice}
    {}

    //move constructor
    Position(Position&& other)
        :m_symbol{std::move(other.m_symbol)}, m_shares{other.m_shares}, m_entryPrice{other.m_entryPrice}
    {   

    }

    double getPnl(double currentPrice) const {
        return m_shares * (currentPrice - m_entryPrice);
    }
};

int main() {
    Position position{"AAPL", 100, 150.50};   // parameterized constructor
    double pnl = position.getPnl(175.0);
    std::cout << "AAPL PnL: " << pnl << std::endl;

    Position position1{"TSLA", 200, 400};     // parameterized constructor
    double pnl1 = position1.getPnl(450.0);
    std::cout << "TSLA PnL: " << pnl1 << std::endl;

    Position p;                               // default constructor
    std::cout << "Default PnL: " << p.getPnl(100.0) << std::endl;

    Position p2 = position1;                  // copy constructor
    std::cout << "Copied TSLA PnL: " << p2.getPnl(450.0) << std::endl;

    Position p3=position1;                  //move constructor
     std::cout << "Moved TSLA PnL: " << p2.getPnl(40.0) << std::endl;

    return 0;
}