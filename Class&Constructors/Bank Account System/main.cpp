#include <iostream>
#include <string>
class Account{ //base class

protected:     // protected members, so derived class can use it
    std::string m_accountNumber;
    std::string m_holderName;
    double m_balance;


public:      //public members 

    Account(std::string accountNumber, std::string holderName, double balance ):    //parameterized constructor to initialize object 
    m_accountNumber{accountNumber}, m_holderName{holderName}, m_balance{balance}
    {
        if (balance<0) //validation , if balance is provided less than 0, set balance to 0
        {
            m_balance=0;
        }
        
    }

    //pure virtual function, derived classes MUST implement these.
    virtual std::string getType()=0;

    virtual void applyInterest() =0;

    //Regular virtual functions , derived classes can either use these defualt or override.
    virtual void getInfo(){
        std::cout<<"Account Number "<<m_accountNumber<<std::endl;
        std::cout<<"Account holder name "<<m_holderName<<std::endl;
        std::cout<<"Balance "<<m_balance<<std::endl;
        std::cout<<"Account Type "<<getType()<<std::endl;
    } 

    //Regular functions , it is shared by all no override needed

    Account& deposit(double amount)
    {
        if(amount>0)
            m_balance +=amount;
        return *this;
    }

    virtual Account& withdraw(double amount) //making it virtual so we can override it
    {
        if(amount>0 && amount<=m_balance)
        {
            m_balance -= amount;
        }
        return *this;
    }

    //getters
    double getBalance() const
    {
        return m_balance;
    }

    std::string getHolderName() const   
    {
        return m_holderName;
    }

    std::string getAccountNumber() const
    {
        return m_accountNumber;
    }

    //virtual destructor , without this it can cause memory leak
    virtual ~Account() {}
    
};


class SavingsAccount:public Account{

private:
    double m_interestRate;

public:

    //constructor
    SavingsAccount(std::string accountNumber, std::string holderName, double balance,double interestRate)
    :Account{accountNumber,holderName,balance},
    m_interestRate(interestRate)
    {
       if(m_interestRate<=0)
       {
        m_interestRate=0.03;
       } 
    }

    //pure virtual function implementation
    std::string getType() override {
        return "Savings";
    } 


    void applyInterest() override {
        double interest = m_balance*m_interestRate;
        m_balance += interest;
        std::cout << "Interest added: " << interest << std::endl;
        std::cout << "New balance: "    << m_balance << std::endl;
    }

    //overrides the base function with new line
    void getInfo() override {
        Account::getInfo();
        std::cout<<"Interest Rate "<<m_interestRate<<std::endl;
    }
    //delegates to full constructer with defaults , incase someone wants to open with no balance or other interest
    SavingsAccount(std::string accoutNumber, std::string holderName) : SavingsAccount{accoutNumber, holderName, 0.0, 0.03}
    {}

};

class CurrentAccount:public Account{

private: 
    double m_overdraftlimit;

public:

    CurrentAccount(std::string accountNumber, std::string holderName, double initialBalance, double overdraftLimit)
    : Account{accountNumber,holderName,initialBalance},
    m_overdraftlimit{overdraftLimit}
    {}

    Account& withdraw(double amount) override{
        if (amount > 0 && amount <= m_balance + m_overdraftlimit) {
            m_balance -= amount;
        }
        return *this;
    }
    
    //pure virtual function implementation
    std::string getType() override {
        return "Current";
    } 

    void applyInterest() override {
        std::cout<<"No interest for Current account \n";
    }

    void getInfo() override {
        Account::getInfo();
        std::cout<<"Overdraft Limit: "<<m_overdraftlimit<<std::endl;
    }
};


int main()
{
    // --- test full constructor ---
    SavingsAccount acc1{"ACC001", "John Doe", 1000.0, 0.05};
    acc1.getInfo();
    std::cout << "---" << std::endl;

    // --- test deposit and chaining ---
    acc1.deposit(500.0).deposit(200.0);
    std::cout << "After deposits: " << acc1.getBalance() << std::endl;  // 1700

    // --- test withdraw ---
    acc1.withdraw(300.0);
    std::cout << "After withdraw: " << acc1.getBalance() << std::endl;  // 1400

    // --- test invalid withdraw — balance should not change ---
    acc1.withdraw(9999.0);
    std::cout << "After bad withdraw: " << acc1.getBalance() << std::endl;  // 1400

    // --- test applyInterest on savings ---
    acc1.applyInterest();   // 1400 * 0.05 = 70 added, new balance 1470
    std::cout << "---" << std::endl;

    // --- test delegating constructor ---
    SavingsAccount acc2{"ACC002", "Jane Doe"};
    acc2.getInfo();
    std::cout << "---" << std::endl;

    // --- test validation — negative balance becomes 0 ---
    SavingsAccount acc3{"ACC003", "Bad Balance", -999.0, 0.05};
    std::cout << "Negative balance test: " << acc3.getBalance() << std::endl;  // 0

    // --- test validation — bad interest rate becomes 0.03 ---
    SavingsAccount acc4{"ACC004", "Bad Rate", 1000.0, -0.5};
    acc4.getInfo();
    std::cout << "---" << std::endl;

    // --- current account tests ---
    CurrentAccount curr{"ACC005", "Alice", 500.0, 200.0};
    curr.getInfo();
    std::cout << "---" << std::endl;

    // normal withdraw
    curr.withdraw(300.0);
    std::cout << "After withdraw: " << curr.getBalance() << std::endl;   // 200

    // overdraft — goes below 0 but within limit
    curr.withdraw(350.0);
    std::cout << "After overdraft: " << curr.getBalance() << std::endl;  // -150

    // exceeds overdraft limit — should fail
    curr.withdraw(999.0);
    std::cout << "After bad withdraw: " << curr.getBalance() << std::endl; // -150

    // apply interest on current — just prints message
    curr.applyInterest();
    std::cout << "---" << std::endl;

    // --- POLYMORPHISM — store all accounts in vector<Account*> ---
    std::cout << "=== ALL ACCOUNTS ===" << std::endl;
    std::vector<Account*> accounts = {&acc1, &acc2, &curr};

    for (Account* acc : accounts) {
        acc->getInfo();                                    // correct getInfo() for each type
        std::cout << "Type: "    << acc->getType()    << std::endl;  // correct getType()
        std::cout << "Balance: " << acc->getBalance() << std::endl;
        acc->applyInterest();                              // correct applyInterest() for each
        std::cout << "---" << std::endl;
    }

    return 0;
}
