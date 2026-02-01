Problem Statement
You need to build a simple limit order book for a trading system. This will test your understanding of structs, enums, arrays, pointers, and references all in one cohesive problem.
Requirements
Part 1: Define the Data Structures
Create the following:

Enum for Order Side

Define an enum class OrderSide with values: BUY and SELL


Enum for Order Status

Define an enum class OrderStatus with values: PENDING, FILLED, CANCELLED


Order Struct

int orderId
OrderSide side
double price
int quantity
OrderStatus status
long long timestamp (use any number to represent time)


OrderBook Struct

A fixed-size array to hold up to 100 orders: Order orders[100]
int orderCount (tracks how many orders are currently in the book)



Part 2: Implement Functions
Write the following functions:

void addOrder(OrderBook& book, const Order& order)

Adds a new order to the order book
Should check if there's space (orderCount < 100)
Print an error message if the book is full


Order* findOrderById(OrderBook& book, int orderId)

Returns a pointer to the order with the given ID
Returns nullptr if not found


void cancelOrder(OrderBook& book, int orderId)

Find the order by ID and change its status to CANCELLED
Print a message indicating success or failure


void displayOrders(const OrderBook& book, OrderSide side)

Display all orders for a given side (BUY or SELL)
Format: "Order ID: X, Price: $Y, Quantity: Z, Status: PENDING/FILLED/CANCELLED"
Only show orders that aren't CANCELLED


double calculateTotalValue(const OrderBook& book, OrderSide side)

Calculate total value (price × quantity) of all PENDING orders for a given side
Return the sum



Part 3: Main Function
In main(), demonstrate your implementation:

Create an OrderBook
Add at least 5 orders (mix of BUY and SELL)
Display all BUY orders
Cancel one order by ID
Display all SELL orders
Calculate and print total value of pending BUY orders
Use findOrderById to get a pointer to an order and modify its quantity

Example Output
Adding orders to the book...
Order 1001 added successfully.
Order 1002 added successfully.
Order 1003 added successfully.
Order 1004 added successfully.
Order 1005 added successfully.

=== BUY Orders ===
Order ID: 1001, Price: $100.50, Quantity: 10, Status: PENDING
Order ID: 1003, Price: $99.75, Quantity: 25, Status: PENDING

Cancelling order 1002...
Order 1002 cancelled successfully.

=== SELL Orders ===
Order ID: 1004, Price: $101.25, Quantity: 15, Status: PENDING
Order ID: 1005, Price: $102.00, Quantity: 20, Status: PENDING

Total value of pending BUY orders: $3498.75

Modifying order 1003...
Order 1003 quantity updated to 50.
What This Tests

✅ Enums: Two different enum classes with proper scoping
✅ Structs: Nested structs (OrderBook contains Orders)
✅ Arrays: Fixed-size array within a struct
✅ Pointers: Returning pointer from function, null checking, using pointer to modify data
✅ References: Passing structs by reference (both const and non-const)
✅ Array iteration: Looping through orders
✅ Conditional logic: Checking status, side, finding matches

Hints

Use the arrow operator (->) when accessing struct members through a pointer
Remember to initialize orderCount to 0 when creating the OrderBook
When comparing enums, use the scope: if (order.side == OrderSide::BUY)
For iteration, loop from 0 to book.orderCount (not the full array size)
Use nullptr checks before dereferencing pointers from findOrderById


Take your time implementing this. Focus on:

Clean, readable code
Proper use of const where appropriate
Defensive programming (null checks, bounds checks)
Clear output messages

When you're done, share your code and I'll review it with you, pointing out what you did well and areas for improvement. This is a realistic scenario you'd encounter in quantitative finance systems! Sonnet 4.5