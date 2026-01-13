✅ PROJECT 1 — COMMAND-LINE CALCULATOR (FOUNDATION KILLER)
🎯 Goal

Build a loop-driven calculator that never crashes, never lies, and never repeats logic.

✅ REQUIRED FEATURES
Input Flow

Ask user for:

First number (double)

Operator (char)

Second number (double)

If user types x as operator → program exits cleanly.

After printing result → loop back to new calculation.

✅ SUPPORTED OPERATORS
Operator	Meaning
+	Addition
-	Subtraction
*	Multiplication
/	Division
✅ ERROR HANDLING (MANDATORY)

If division by zero → print:

ERROR: Division by zero not allowed.


Then restart loop.

If invalid operator → print:

ERROR: Unknown operator.

✅ FUNCTION RULES (STRICT)

You MUST implement exactly 5 functions:

double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
double calculate(double a, double b, char op);

calculate() Rules:

Uses switch

Calls only the math functions

NO MATH LOGIC inside main()

✅ FORBIDDEN

❌ Global variables
❌ Repeating math logic
❌ exit()
❌ goto

✅ PASS CONDITIONS

You pass only if:

You can enter: 5 / 0 → no crash

You can chain 50 calculations in one run

You can type x and exit cleanly