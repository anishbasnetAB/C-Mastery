### Challenge 4: Simple Calculator with Input Validation

**Topics: Functions, Switch statements, Loops, Character operations**

Write a calculator program:

- Function `double calculate(double a, double b, char op)` that performs +, -, *, /
- Handle division by zero gracefully
- Use a switch statement for the operations
- Keep asking for calculations until user enters 'q' to quit
- Use proper function separation (input, calculation, output)

**Expected interaction:**

```
Enter first number: 10
Enter operator (+, -, *, /, q to quit): /
Enter second number: 0
Error: Division by zero!
Enter operator (+, -, *, /, q to quit): *
Enter second number: 5
Result: 50