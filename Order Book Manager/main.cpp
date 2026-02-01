#include <iostream>

enum class OrderSide
{
    BUY,
    SELL
};

enum class OrderStatus
{
    PENDING,
    FILLED,
    CANCELLED
};

struct Order
{
    int orderId;
    OrderSide side;
    double price;
    int quantity;
    OrderStatus status;
    long long timestamp;
};

struct OrderBook
{
    Order orders[100];
    int orderCount;
};

void addOrder(OrderBook& book, const Order& order)
{
    if(book.orderCount>=100)
    {
        std::cout<<"Order limit reached, no more order can be added";
    }

    

}

int main()
{
    return 0;
}