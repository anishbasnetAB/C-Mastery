#include <string> //Header guards for input.h
#ifndef INPUT_H
#define INPUT_H
double getPositiveDouble(const std::string& prompt);

int getIntegerInRange(const std::string& prompt, int min, int max);

std::string getStockSymbol(const std::string& prompt);
#endif
