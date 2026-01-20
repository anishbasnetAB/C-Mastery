#include <iostream>

double amount{};
int count{};

void deposit()
{
    double userDepositAmount{};
    std::cout<<"Enter an amount you want to deposit. \n";
    std::cin>>userDepositAmount;
    amount += userDepositAmount;
    count ++;
}



void withdraw()
{
    double userWithDrawAmount{};
    std::cout<<"Enter an amount you want to deposit. \n";
    std::cin>>userWithDrawAmount;
    amount -= userWithDrawAmount;
    count ++;
}

void balance()
{
    std::cout<<"Your current balance is : "<<amount<<" \n";
}

void transHistory()
{
    std::cout<<"Your total number of transactions are : "<<count<<" \n";
}



int main()
{
    std::cout<<"Mini banking. select option \n";
    int userOption{};
    while (true)
    {
        
        std::cout<<"1. Deposit \n 2. Withdraw \n 3. Check Balance \n 4. Transaction History (just count) \n 5.Exit \n";
        if((std::cin>>userOption).fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        if(userOption==1 || userOption==2 || userOption ==3|| userOption ==4 || userOption==5)
        {
            if (userOption==1)
            {
                deposit();
                continue;
            }
            else if (userOption ==2)
            {
                withdraw();
                continue;
            }
            else if (userOption ==3)
            {
                balance();
                continue;
            }
            else if(userOption ==4)
            {
                transHistory();
                continue;
            }
            else
                break;
        }
        else
            std::cout<<"Please enter valid number";
            continue;
    }
    
    return 0;
}