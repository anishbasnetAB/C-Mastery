Challenge Option 4: Dice Game Simulator
Topics: Functions, Random numbers, Loops, Logic
Create a dice rolling game:
* int rollDice() - Return random number 1-6
* bool isDouble(int dice1, int dice2) - Check if both dice match
* int calculateScore(int rolls) - Roll N times and sum results
* void playGame() - Player vs Computer, best of 5 rounds
Constraint: Use rand() and srand() for randomness.

Game Rules

Player vs Computer
Best of 5 rounds (first to win 3 rounds wins the game)
Each round: both roll 2 dice
Highest total wins the round
If it's a tie, both get a point
Bonus: If you roll doubles (both dice same), you get to roll 1 extra die and add it to your total!